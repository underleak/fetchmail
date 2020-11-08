#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
    this->setWindowTitle("Вход");

    registration = new Registration();
    connect(registration, &Registration::back, this, &Registration::show);
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
    if (!quary.exec("SELECT * FROM users"))
    {
        qDebug() << quary.lastError().databaseText();
        qDebug() << quary.lastError().driverText();
        return;
    }

    quary.exec("SELECT * FROM users WHERE login = '" + login + "' AND password = '" + password + "'");
    if (quary.size())
        qDebug() << "ZAEBIS";
        // тут логика после успещного входа
    else
        qDebug() << "HUEVO";
        // тут логика после неуспешного входа
}
