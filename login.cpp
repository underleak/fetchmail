#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
    this->setWindowTitle("Вход");
    ui->textPassword->setEchoMode(QLineEdit::Password);

    registration = new Registration();
    connect(registration, &Registration::back, this, &Login::show);

    msg = new Messages();
}

Login::~Login()
{
    delete ui;
}

void Login::on_signUp_clicked()
{
    registration->show();
    this->close();
}

QSqlDatabase& Login::get_db()
{
    static QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setDatabaseName("mail");
    db.setUserName("root");
    db.setPassword("12345");
    if(!db.open())
    {
        qDebug() << db.lastError().text();
    }
    return db;
}

void Login::on_sign_In_clicked()
{
    QString login = ui->textLogin->text();
    QString password = ui->textPassword->text();

    if (login == "admin" && password == "admin")
    {
        adm = new Admin();
        this->close();
        adm->show();
        return;
    }

    QSqlQuery quary = QSqlQuery(get_db());
    quary.exec("SELECT * FROM auth WHERE login = '" + login + "' AND password = '" +  password + "'");

    quary.first();
    QSqlRecord record = quary.record();

    if (login.isEmpty() || password.isEmpty())
    {
        QMessageBox::critical(this, "Ошибка входа", "Пожалуйста, введите логин и пароль.", QMessageBox::Ok);
        return;
    }

    if  (!quary.size())
    {
        QMessageBox::critical(this, "Ошибка входа", "Неправильный логин или пароль.", QMessageBox::Ok);
        return;
    }

    if (quary.value(record.indexOf("isBlocked")).toString() == "1")
    {
        QMessageBox::critical(this, "Ошибка входа", "Ваш профиль был заблокирован, обратитесь в службу поддержки.", QMessageBox::Ok);
        return;
    }

    if (quary.value(record.indexOf("isVerifed")).toString() == "0")
    {
        QMessageBox::critical(this, "Ошибка входа", "Ваш профиль еще не активирован, подождите, пока администратор подтвердит регистрацию.", QMessageBox::Ok);
        return;
    }

    quary.exec("SELECT acc_ID FROM auth WHERE login = '"+ login + "' AND password = '" + password +"'");
    quary.first();
    record = quary.record();
    msg->acc_id = quary.value(record.indexOf("acc_ID")).toInt();
    msg->shortDisplay();
    msg->show();
    this->close();
}

void Login::on_clear_clicked()
{
    ui->textLogin->clear();
    ui->textPassword->clear();
}

void Login::on_showPassword_clicked()
{
    ui->textPassword->echoMode() == QLineEdit::Normal ? ui->textPassword->setEchoMode(QLineEdit::Password)
                                                  : ui->textPassword->setEchoMode(QLineEdit::Normal);
}


