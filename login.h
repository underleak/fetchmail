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
#include <QMessageBox>
#include "registration.h"
#include "messages.h"
#include "admin.h"

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
    void on_sign_In_clicked();
    void on_signUp_clicked();
    void on_clear_clicked();
    void on_showPassword_clicked();

private:
    Ui::Login *ui;
    Registration *registration;
    Messages *msg;
    Admin *adm;

signals:
    void next();

};
#endif // LOGIN_H
