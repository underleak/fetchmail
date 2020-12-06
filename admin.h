#ifndef ADMIN_H
#define ADMIN_H

#include <QWidget>
#include <QSqlError>
#include <QSqlRecord>
#include <QSqlQuery>
#include <QString>
#include <QSqlTableModel>
#include "database.h"
#include "statistics.h"

class Statistics;

namespace Ui {
class Admin;
}

class Admin : public QWidget
{
    Q_OBJECT

public:
    explicit Admin(QWidget *parent = nullptr);

    ~Admin();

private:
    void getOverview();
    Ui::Admin *ui;
    QString findStat;
    QSqlTableModel *model;
    Database *database;
    Statistics *statistics;

private slots:
    void on_getTable_clicked();
    void on_deleteSelectedRows_clicked();
    void on_updatePage_clicked();
    void on_submitChanges_clicked();
    void on_unblockAll_clicked();
    void on_verifyAll_clicked();
    void on_deleteAllMessages_clicked();
    void updateTable();
};

#endif // ADMIN_H
