#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>
#include <QSqlError>
#include <QSqlRecord>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QBoxLayout>
#include <QLabel>
#include <QValidator>
#include <QApplication>
#include <QMessageBox>
#include "registration.h"
#include "messages.h"
#include "admin.h"

class Registration;
class Messages;

QT_BEGIN_NAMESPACE
namespace Ui { class Login; }
QT_END_NAMESPACE

class Login : public QMainWindow
{
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);
    ~Login();
    static QSqlDatabase& get_db();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();

private:
    Ui::Login *ui;
    Registration *registration;
    QSqlQuery quary;
    Messages *msg;
    Admin *adm;
    QMessageBox::StandardButton reply;

signals:
    void next();

};
#endif // LOGIN_H
