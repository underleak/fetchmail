#include "registration.h"
#include "ui_registration.h"

Registration::Registration(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Registration)
{
    ui->setupUi(this);
    this->setWindowTitle("Регистрация");
}

Registration::~Registration()
{
    delete ui;
}

void Registration::on_pushButton_clicked()
{
    this->close();
    emit back();
}

void Registration::on_pushButton_2_clicked()
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

    quary.exec("INSERT INTO users VALUES ('" + login + "', '" + password + "')");
}
