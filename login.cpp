#include "login.h"
#include "ui_login.h"


Login::Login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
    this->setWindowTitle("Вход");
    registration = new Registration();
    msg=new Messages();
    ui->lineEdit->setEchoMode(QLineEdit::Password);

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
    db.setHostName("localhost");
    db.setDatabaseName("testdb");
    db.setUserName("root");
    db.setPassword("20643579");
    if(!db.open()) qDebug() << db.lastError().text();

    return db;
}

void Login::on_pushButton_clicked()
{

    if (ui->lineEdit->text()=="admin" & ui->lineEdit_2->text()=="admin")
    {
        adm = new Admin();
        this->close();
        adm->show();
        return;

    }

    quary = QSqlQuery(Login::get_db());
    QSqlRecord record;


        quary.exec("SELECT * FROM auth WHERE login = '" + ui->lineEdit_2->text() + "' AND password = '" +  ui->lineEdit->text() + "'");
        record=quary.record();
        quary.first();

        if (quary.value(record.indexOf("isBlocked")).toString() == "1")
        {
            reply = QMessageBox::critical(this, "Ошибка входа", "Ваш профиль был заблокирован, обратитесь в службу поддержки.", QMessageBox::Ok);
            return;
        }

        else if (quary.value(record.indexOf("isVerifed")).toString() == "0")
        {
            reply = QMessageBox::critical(this, "Ошибка входа", "Ваш профиль еще не активирован, подождите, пока администратор подтвердит регистрацию.", QMessageBox::Ok);
            return;
        }

        else if  (!quary.size())
        {
            reply = QMessageBox::critical(this, "Ошибка входа", "Неправильный логин или пароль.", QMessageBox::Ok);
            return;
        }


              QString zapros="SELECT acc_ID FROM auth WHERE login = '"+ ui->lineEdit_2->text() + "' AND password = '" +  ui->lineEdit->text() +"'" ;
              quary.exec(zapros);
              QSqlRecord rec = quary.record();
              quary.first();
              msg->acc_id = quary.value(rec.indexOf("acc_ID")).toInt();
              this->close();
              msg->shortDisplay();
              msg->show();





     }
void Login::on_pushButton_3_clicked()
{
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
}


void Login::on_pushButton_5_clicked()
{
    ui->lineEdit->echoMode() == QLineEdit::Normal ? ui->lineEdit->setEchoMode(QLineEdit::Password)
                                                  : ui->lineEdit->setEchoMode(QLineEdit::Normal);
}



