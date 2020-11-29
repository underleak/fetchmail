#include "registration.h"
#include "ui_registration.h"
#include "login.h"

Registration::Registration(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Registration)
{
    ui->setupUi(this);
    this->setWindowTitle("Регистрация");
    ui->textLogin->setMaxLength(35);
    ui->textPassword->setMaxLength(20);
    ui->textPassword->setEchoMode(QLineEdit::Password);
}

Registration::~Registration()
{
    delete ui;
}

void Registration::on_back_clicked()
{
    this->close();
    emit back();
}

void Registration::on_signUp_clicked()
{
    QString login = ui->textLogin->text();
    QString password = ui->textPassword->text();

    if (login.isEmpty() || password.isEmpty()) {
        QMessageBox::critical(this, "Ошибка регистрации", "Пожалуйста, введите логин и пароль.", QMessageBox::Ok);
        return;
    }

    QSqlQuery quary = QSqlQuery(Login::get_db());
    quary.exec("SELECT * FROM auth WHERE login = '" + login + "'");

    if (!quary.size())
        quary.exec("INSERT INTO auth (login, password) VALUES ('" + login + "', '" + password + "')");
    else
        QMessageBox::critical(this, "Ошибка регистрации", "Пользователь с таким именем уже существует.", QMessageBox::Ok);
}

void Registration::on_clear_clicked()
{
    ui->textLogin->clear();
    ui->textPassword->clear();
}

void Registration::on_showPassword_clicked()
{
    ui->textPassword->echoMode() == QLineEdit::Normal ? ui->textPassword->setEchoMode(QLineEdit::Password)
                                                  : ui->textPassword->setEchoMode(QLineEdit::Normal);
}

