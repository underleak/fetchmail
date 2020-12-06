#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <QWidget>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QMessageBox>
#include "database.h"

namespace Ui {
class Registration;
}

class Registration : public QWidget
{
    Q_OBJECT

public:
    explicit Registration(QWidget *parent = nullptr);
    ~Registration();

signals:
    void back();

private slots:
    void on_back_clicked();
    void on_signUp_clicked();
    void on_clear_clicked();
    void on_showPassword_clicked();

private:
    Ui::Registration *ui;
    Database *database;
};

#endif // REGISTRATION_H
