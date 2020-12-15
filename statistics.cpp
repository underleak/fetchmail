#include "statistics.h"
#include "ui_admin.h"

Statistics::Statistics(Ui::Admin *ui)
{
    this->ui = ui;
    database = new Database();
}

void Statistics::updateStats()
{
    database->query.exec("SELECT SUM(isBlocked), SUM(isVerified = 0) FROM auth");
    database->query.first();
    ui->blockedUsers->setText("Всего заблокировано: " +  database->query.value(0).toString());
    ui->unverifiedUsers->setText("Всего на подтверждении: " + database->query.value(1).toString());

    database->query.exec("SELECT COUNT(*) FROM data");
    database->query.first();
    ui->totalMessages->setText("Всего писем в системе: " +  database->query.value(0).toString());
}

void Statistics::getDonutPieChart()
{
    ui->donutPieChart->hide();

    QPieSeries *series = new QPieSeries();
    series->setHoleSize(0.35);
    series->setVerticalPosition(0.6);

    QPieSlice *seriesSlice = new QPieSlice();
    QChart *chart = new QChart();
    chart->setTheme(QChart::ChartThemeQt);

    if (ui->comboBox->currentIndex() <= 1){
        database->query.exec("SELECT COUNT(*) FROM auth where isBlocked = 1 or isVerified = 0");
        database->query.first();
        int inactive = database->query.value(0).toInt();

        database->query.exec("select * from auth");
        seriesSlice = series->append("Активные: " + QString::number(database->query.size() - inactive), database->query.size() - inactive);
        series->append("Заблокированные / неподтвержденные: " + QString::number(inactive), inactive);
        chart->setTitle("Распределение пользователей:");
    }

    if (ui->comboBox->currentIndex() >= 2){
        database->query.exec("SELECT COUNT(*) FROM data where acc_id = " + acc_ID);
        database->query.first();
        int individual = database->query.value(0).toInt();

        database->query.exec("SELECT COUNT(*) FROM data");
        database->query.first();
        int total = database->query.value(0).toInt();

        seriesSlice = series->append("Письма " + ui->lineEdit->text() + ": " + QString::number(individual), individual);
        series->append("Остальные письма: " + QString::number(total - individual), total - individual);
        chart->setTitle("Доля " + ui->lineEdit->text() + " в общем объеме писем:");
    }

    seriesSlice->setExploded();
    seriesSlice->setPen(QPen(Qt::darkGreen, 2));
    seriesSlice->setBrush(Qt::green);

    chart->addSeries(series);
    chart->setAnimationOptions(QChart::SeriesAnimations);
    chart->setBackgroundBrush(QBrush(QColor("transparent")));
    chart->legend()->setAlignment(Qt::AlignLeft);
    chart->legend()->detachFromChart();
    chart->legend()->setGeometry(50, 40, 400, 200);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setParent(ui->donutPieChart);
    chartView->resize(375, 300);
    ui->donutPieChart->show();
    chart->legend()->setLabelBrush(Qt::white);
    chart->setTitleBrush(Qt::white);

}

void Statistics::getVerticalBarChart()
{
    ui->verticalBarChart->hide();

    QStackedBarSeries *series = new QStackedBarSeries();
    QChart *chart = new QChart();
    QStringList categories;
    QBarSet *set0 = new QBarSet("");

    if (ui->comboBox->currentIndex() <= 1){
        database->query.exec("SELECT login, total_msg FROM auth ORDER BY total_msg DESC");
        for (int i = 0; i < 5 && database->query.next(); ++i) {
            categories << database->query.value(0).toString();
            *set0 << database->query.value(1).toInt();
        }
        set0->setBrush(QBrush(Qt::green));
        series->append(set0);
        chart->legend()->hide();
        chart->setTitle("Топ пользователей по количеству писем:");
    }

    if (ui->comboBox->currentIndex() >= 2){
        QStringList labels = {"Аватар", "Имя", "Фамилия", "Дата рождения"};
        QStringList colorLabels = {};
        QStringList grayLabels = {};

        QBarSet *set1 = new QBarSet("");
        QBarSet *set2 = new QBarSet("");
        QBarSet *set3 = new QBarSet("");

        *set0 << 25;
        *set1 << 25;
        *set2 << 25;
        *set3 << 25;

        database->query.exec("select avatar, name, surname, dateBirth from auth where acc_ID = " + acc_ID);
        database->query.first();
        database->queryRecord = database->query.record();

        for(int i = 0; i < 4; i++){
            if (database->queryRecord.value(i).toString() == "")
                grayLabels.append(labels.at(i));
            else
                colorLabels.append(labels.at(i));
        }
        colorLabels.append(grayLabels);

        set0->setLabel(colorLabels.at(0));
        set1->setLabel(colorLabels.at(1));
        set2->setLabel(colorLabels.at(2));
        set3->setLabel(colorLabels.at(3));

        chart->setTheme(QChart::ChartThemeQt);
        for (int i = 0; i < grayLabels.size(); i++){
            if (i == 0) set3->setBrush(QBrush(Qt::gray));
            if (i == 1) set2->setBrush(QBrush(Qt::gray));
            if (i == 2) set1->setBrush(QBrush(Qt::gray));
            if (i == 3) set0->setBrush(QBrush(Qt::gray));
        }

        series->append(set0);
        series->append(set1);
        series->append(set2);
        series->append(set3);

        categories << ui->lineEdit->text();

        chart->setTitle("Заполненность профиля " + ui->lineEdit->text() + ": " + QString::number(100 - 25 * grayLabels.size()) + "%");
    }

    chart->addSeries(series);
    chart->legend()->setAlignment(Qt::AlignTop);
    chart->legend()->setMinimumWidth(300);
    chart->setAnimationOptions(QChart::SeriesAnimations);
    chart->setBackgroundBrush(QBrush(QColor("transparent")));

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setParent(ui->verticalBarChart);
    chartView->resize(400, 300);
    ui->verticalBarChart->show();
    chart->setTitleBrush(Qt::white);
    axisX->setLabelsBrush(Qt::white);
    axisY->setLabelsBrush(Qt::white);
}
