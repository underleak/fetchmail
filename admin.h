#ifndef ADMIN_H
#define ADMIN_H

#include <QWidget>
#include <QSqlError>
#include <QSqlRecord>
#include <QSqlQuery>
#include <QString>
#include <QtCharts/QLineSeries>
#include <QSqlTableModel>

#include <QChartView>
#include <QPieSeries>
#include <QPieSlice>
#include <QBarSet>
#include <QStackedBarSeries>
#include <QBarCategoryAxis>
#include <QValueAxis>
#include <QHorizontalPercentBarSeries>

using namespace QtCharts;

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

    Ui::Admin *ui;
    void getOverview();
    QSqlQuery query;
    QSqlRecord record;
    QString findStat;
    QString acc_ID;
    QSqlTableModel *model;

private slots:
    void on_getTable_clicked();
    void on_deleteSelectedRows_clicked();
    void on_updatePage_clicked();
    void on_submitChanges_clicked();
    void on_unblockAll_clicked();
    void on_verifyAll_clicked();
    void on_deleteAllMessages_clicked();
    void updateTable();
    void updateStats();
    void getDonutPieChart();
    void getVerticalBarChart();
    void getHorizontalBarChart();
};

#endif // ADMIN_H
