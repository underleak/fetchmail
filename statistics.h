#ifndef STATISTICS_H
#define STATISTICS_H

#include <QChartView>
#include <QPieSeries>
#include <QPieSlice>
#include <QBarSet>
#include <QStackedBarSeries>
#include <QBarCategoryAxis>
#include <QValueAxis>
#include "database.h"
#include "admin.h"

using namespace QtCharts;

namespace Ui { class Admin; }

class Statistics
{
public:
    Statistics(Ui::Admin *ui);
    QString acc_ID;
    void updateStats();
    void getDonutPieChart();
    void getVerticalBarChart();

private:
    Ui::Admin *ui;
    Database *database;
};

#endif // STATISTICS_H
