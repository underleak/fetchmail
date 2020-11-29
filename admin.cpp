#include "admin.h"
#include "ui_admin.h"
#include "login.h"

Admin::Admin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Admin)
{
    ui->setupUi(this);
    query = QSqlQuery(Login::get_db());

    updateStats();
    on_getTable_clicked();
    getDonutPieChart();
    getVerticalBarChart();
    getHorizontalBarChart();
}

Admin::~Admin()
{
    delete ui;
}

void Admin::on_getTable_clicked()
{
    query.exec("select * from auth where login = '" + ui->lineEdit->text() + "'");
    query.first();
    record = query.record();
    acc_ID = record.value(0).toString();
    record.clear();

    model = new QSqlTableModel(this, Login::get_db());
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);

    if (ui->comboBox->currentIndex() == 0)
        model->setTable("auth");

    if (ui->comboBox->currentIndex() == 1)
        model->setTable("data");

    if (ui->comboBox->currentIndex() == 2)
    {
        model->setTable("auth");
        model->setFilter("acc_ID = " + acc_ID);
    }

    if (ui->comboBox->currentIndex() == 3)
    {
        model->setTable("data");
        model->setFilter("acc_id = " + acc_ID);
    }

    model->select();
    ui->tableView->setModel(model);
}

void Admin::on_deleteSelectedRows_clicked()
{
    QItemSelection selectedRows = ui->tableView->selectionModel()->selection();
    QVector<int> selectedIndexes;

    foreach(const QModelIndex & index, selectedRows.indexes())
    {
        if (!(std::find(selectedIndexes.begin(), selectedIndexes.end(), index.row()) != selectedIndexes.end()))
        {
            selectedIndexes.append(index.row());
            model->removeRow(index.row());
        }
    }
}

void Admin::on_updatePage_clicked()
{
    updateTable();
    updateStats();
    getDonutPieChart();
    getVerticalBarChart();
    getHorizontalBarChart();
}

void Admin::updateStats()
{
    query.exec("SELECT SUM(isBlocked), SUM(isVerified = 0) FROM auth");
    query.first();
    ui->blockedUsers->setText("Всего заблокировано: " +  query.value(0).toString());
    ui->blockedUsers->setAlignment(Qt::AlignCenter);
    ui->unverifiedUsers->setText("Всего на подтверждении: " + query.value(1).toString());
    ui->unverifiedUsers->setAlignment(Qt::AlignCenter);

    query.exec("SELECT COUNT(msg_id) FROM data");
    query.first();
    ui->totalMessages->setText("Всего писем в системе: " +  query.value(0).toString());
    ui->totalMessages->setAlignment(Qt::AlignCenter);
}

void Admin::getDonutPieChart()
{
    ui->donutPieChart->hide();

    QPieSeries *series = new QPieSeries();
    series->setHoleSize(0.35);
    series->setVerticalPosition(0.45);

    QPieSlice *seriesSlice = series->append("Kok", 23);
    seriesSlice->setExploded();
    seriesSlice->setLabelVisible();
    series->append("Остальные 77%", 77);

    QChart *chart = new QChart();
    chart->addSeries(series);
    //chart->setTitle("Всего писем в системе:");
    chart->legend()->hide();
    chart->setAnimationOptions(QChart::SeriesAnimations);
    chart->setBackgroundBrush(QBrush(QColor("transparent")));

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setParent(ui->donutPieChart);
    chartView->resize(300, 300);
    ui->donutPieChart->show();
}


void Admin::getVerticalBarChart()
{
    ui->verticalBarChart->hide();

    QBarSet *set0 = new QBarSet("Дата рождения");
    QBarSet *set1 = new QBarSet("Аватар");
    QBarSet *set2 = new QBarSet("Имя");
    QBarSet *set3 = new QBarSet("Фамилия");

    *set0 << 25;
    *set1 << 25;
    *set2 << 25;
    *set3 << 25;

    set2->setBrush(QBrush(Qt::gray));
    set3->setBrush(QBrush(Qt::gray));

    QStackedBarSeries *series = new QStackedBarSeries();
    series->append(set0);
    series->append(set1);
    series->append(set2);
    series->append(set3);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->legend()->setAlignment(Qt::AlignTop);
    chart->legend()->setMinimumWidth(300);
    chart->setAnimationOptions(QChart::SeriesAnimations);
    chart->setBackgroundBrush(QBrush(QColor("transparent")));

    QStringList categories;
    categories << "Kok";

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
    chartView->resize(300, 270);
    ui->verticalBarChart->show();
}

void Admin::getHorizontalBarChart()
{
    ui->horizontalBarChart->hide();
    QBarSet *set0 = new QBarSet("Jane");
    QBarSet *set1 = new QBarSet("John");
    QBarSet *set2 = new QBarSet("Axel");
    QBarSet *set3 = new QBarSet("Mary");
    QBarSet *set4 = new QBarSet("Samantha");

    *set0 << 1 << 2 << 3 << 4 << 5 << 6;
    *set1 << 5 << 0 << 0 << 4 << 0 << 7;
    *set2 << 3 << 5 << 8 << 13 << 8 << 5;
    *set3 << 5 << 6 << 7 << 3 << 4 << 5;
    *set4 << 9 << 7 << 5 << 3 << 1 << 2;

    QHorizontalPercentBarSeries *series = new QHorizontalPercentBarSeries();
    series->append(set0);
    series->append(set1);
    series->append(set2);
    series->append(set3);
    series->append(set4);

    QChart *chart = new QChart();
        chart->addSeries(series);
        chart->legend()->hide();
        chart->setAnimationOptions(QChart::SeriesAnimations);
        chart->setBackgroundBrush(QBrush(QColor("transparent")));

    QStringList categories;
    categories << "Jan" << "Feb" << "Mar";

    QBarCategoryAxis *axisY = new QBarCategoryAxis();
    axisY->append(categories);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    QValueAxis *axisX = new QValueAxis();
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setParent(ui->horizontalBarChart);
    chartView->resize(300, 270);
    ui->horizontalBarChart->show();
}

void Admin::updateTable()
{
    model->select();
}

void Admin::on_submitChanges_clicked()
{
    model->submitAll();
}

void Admin::on_unblockAll_clicked()
{
    if (model->tableName() == "auth") {
        model->setEditStrategy(QSqlTableModel::OnFieldChange);
        for (int i = 0; i < model->rowCount(); i++)
            model->setData(model->index(i, 3), 0, Qt::EditRole);
        model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    }
    else {
        query.exec("update auth set isBlocked = 0");
    }
}

void Admin::on_verifyAll_clicked()
{
    if (model->tableName() == "auth") {
        model->setEditStrategy(QSqlTableModel::OnFieldChange);
        for (int i = 0; i < model->rowCount(); i++)
            model->setData(model->index(i, 4), 1, Qt::EditRole);
        model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    }
    else {
        query.exec("update auth set isVerified = 1");
    }
}

void Admin::on_deleteAllMessages_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Внимание!", "Вы уверены, что хотите удалить все письма?",
                                                              QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        if (model->tableName() == "data"){
            model->removeRows(0, model->rowCount());
            model->submitAll();
        }
        else
            query.exec("DELETE FROM data WHERE msg_id;");
    }
}
