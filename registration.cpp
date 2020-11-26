#include "registration.h"
#include "ui_registration.h"
#include "login.h"



Registration::Registration(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Registration)
{
    ui->setupUi(this);
    this->setWindowTitle("Регистрация");
    ui->lineEdit->setMaxLength(35);
    ui->lineEdit_2->setMaxLength(20);
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
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
    QString login = ui->lineEdit->text();
    QString password = ui->lineEdit_2->text();

    if (login.isEmpty() || password.isEmpty())
    {
       reply = QMessageBox::critical(this, "Ошибка регистрации", "Пожалуйста, введите логин и пароль.", QMessageBox::Ok);
    }
    else
    {
        quary = QSqlQuery(Login::get_db());
        quary.exec("SELECT * FROM auth WHERE login = '" + login + "'");
        if (quary.size())
             reply = QMessageBox::critical(this, "Ошибка регистрации", "Пользователь с таким именем уже существует.", QMessageBox::Ok);
        else
            quary.exec("INSERT INTO auth (login, password) VALUES ('" + login + "', '" + password + "')");
    }
}

void Registration::on_pushButton_3_clicked()
{
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
}



void Registration::on_pushButton_5_clicked()
{
    ui->lineEdit_2->echoMode() == QLineEdit::Normal ? ui->lineEdit_2->setEchoMode(QLineEdit::Password)
                                                  : ui->lineEdit_2->setEchoMode(QLineEdit::Normal);
}

