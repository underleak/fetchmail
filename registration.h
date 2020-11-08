#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <QWidget>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include "login.h"

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
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Registration *ui;
    QSqlQuery quary;
};

#endif // REGISTRATION_H
