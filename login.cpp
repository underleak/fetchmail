#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
    this->setWindowTitle("Вход");
    ui->lineEdit->setEchoMode(QLineEdit::Password);

    registration = new Registration();
    msg = new Messages();
    connect(registration, &Registration::back, this, &Login::show);
}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_2_clicked()
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

void Login::on_pushButton_clicked()
{
    QString login = ui->lineEdit_2->text();
    QString password = ui->lineEdit->text();

    quary = QSqlQuery(Login::get_db());
    if (!quary.exec("SELECT * FROM auth"))
    {
        qDebug() << quary.lastError().databaseText();
        qDebug() << quary.lastError().driverText();
        return;
    }

    if (login == "admin" && password == "admin")
    {
        adm = new Admin();
        this->close();
        adm->show();
        return;
    }

    quary.exec("SELECT * FROM auth WHERE login = '" + login + "' AND password = '" + password + "'");
    if (quary.size())
    {
        QString zapros="SELECT acc_ID FROM auth WHERE login = '"+ login + "' AND password = '" + password +"'" ;
        quary.exec(zapros);
        QSqlRecord rec = quary.record();
        quary.next();
        msg->acc_id = quary.value(rec.indexOf("acc_ID")).toInt();
        this->close();
        msg->shortDisplay();
        msg->show();
    }
    else
        qDebug() << "HUEVO";
        // тут логика после неуспешного входа
}

void Login::on_pushButton_3_clicked()
{
    ui->lineEdit_2->clear();
}

void Login::on_pushButton_4_clicked()
{
    ui->lineEdit->clear();
}

void Login::on_pushButton_5_clicked()
{
    ui->lineEdit->echoMode() == QLineEdit::Normal ? ui->lineEdit->setEchoMode(QLineEdit::Password)
                                                  : ui->lineEdit->setEchoMode(QLineEdit::Normal);
}
