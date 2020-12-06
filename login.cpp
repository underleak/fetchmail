#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
    this->setWindowTitle("Вход");
    ui->textPassword->setEchoMode(QLineEdit::Password);

    database = new Database();

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

    database->query.exec("SELECT * FROM auth WHERE login = '" + login + "' AND password = '" +  password + "'");

    database->query.first();
    QSqlRecord record = database->query.record();

    if (login.isEmpty() || password.isEmpty())
    {
        QMessageBox::critical(this, "Ошибка входа", "Пожалуйста, введите логин и пароль.", QMessageBox::Ok);
        return;
    }

    if  (!database->query.size())
    {
        QMessageBox::critical(this, "Ошибка входа", "Неправильный логин или пароль.", QMessageBox::Ok);
        return;
    }

    if (database->query.value(record.indexOf("isBlocked")).toString() == "1")
    {
        QMessageBox::critical(this, "Ошибка входа", "Ваш профиль был заблокирован, обратитесь в службу поддержки.", QMessageBox::Ok);
        return;
    }

    if (database->query.value(record.indexOf("isVerifed")).toString() == "0")
    {
        QMessageBox::critical(this, "Ошибка входа", "Ваш профиль еще не активирован, подождите, пока администратор подтвердит регистрацию.", QMessageBox::Ok);
        return;
    }

    database->query.exec("SELECT acc_ID FROM auth WHERE login = '"+ login + "' AND password = '" + password +"'");
    database->query.first();
    record = database->query.record();
    msg->acc_id = database->query.value(record.indexOf("acc_ID")).toInt();
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


