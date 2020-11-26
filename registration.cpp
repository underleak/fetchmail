#include "registration.h"
#include "ui_registration.h"

Registration::Registration(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Registration)
{
    ui->setupUi(this);
    this->setWindowTitle("Регистрация");
    ui->lineEdit_2->setMaxLength(35);
    ui->lineEdit->setMaxLength(20);
    ui->lineEdit->setEchoMode(QLineEdit::Password);
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

    if (login.isEmpty() || password.isEmpty())
    {
        reply = QMessageBox::critical(this, "Ошибка регистрации", "Пожалуйста, введите логин и пароль.", QMessageBox::Ok);
    }
    else
    {
        quary = QSqlQuery(Login::get_db());
        if (!quary.exec("SELECT * FROM auth"))
        {
            qDebug() << quary.lastError().databaseText();
            qDebug() << quary.lastError().driverText();
            return;
        }

        quary.exec("SELECT * FROM auth WHERE login = '" + login + "'");
        if (quary.size())
            reply = QMessageBox::critical(this, "Ошибка регистрации", "Пользователь с таким именем уже существует.", QMessageBox::Ok);
        else
            quary.exec("INSERT INTO auth (login, password) VALUES ('" + login + "', '" + password + "')");
    }
}

void Registration::on_pushButton_3_clicked()
{
    ui->lineEdit_2->clear();
}

void Registration::on_pushButton_4_clicked()
{
    ui->lineEdit->clear();
}

void Registration::on_pushButton_5_clicked()
{
    ui->lineEdit->echoMode() == QLineEdit::Normal ? ui->lineEdit->setEchoMode(QLineEdit::Password)
                                                  : ui->lineEdit->setEchoMode(QLineEdit::Normal);
}

