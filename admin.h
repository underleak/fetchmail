#ifndef ADMIN_H
#define ADMIN_H

#include <QWidget>
#include <QSqlError>
#include <QSqlRecord>
#include <QSqlQuery>
#include <QString>
#include <QSqlTableModel>

namespace Ui {
class Admin;
}

class Admin : public QWidget
{
    Q_OBJECT

public:
    explicit Admin(QWidget *parent = nullptr);
    ~Admin();

private slots:
    void on_getTable_clicked();
    void on_deleteSelectedRows_clicked();
    void on_updateTable_clicked();
    void on_submitChanges_clicked();

    void on_unblockAll_clicked();

    void on_verifyAll_clicked();

    void on_deleteAllMessages_clicked();

private:
    Ui::Admin *ui;
    QSqlQuery query;
    QSqlRecord recording;
    QString findStat;
    QString acc_ID;
    QSqlTableModel* model;
};

#endif // ADMIN_H
