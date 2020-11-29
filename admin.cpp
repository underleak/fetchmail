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
    getStats();
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

void Admin::getStats()
{
// 1 Pie Chart
    QPieSeries *pieChartSeries_1 = new QPieSeries();
    pieChartSeries_1->append("Jane", 1);
    pieChartSeries_1->append("Loh", 2);
    pieChartSeries_1->append("Andy", 3);
    pieChartSeries_1->append("Barbara", 4);
    pieChartSeries_1->append("Axel", 5);
    pieChartSeries_1->setVerticalPosition(0.65);

    QPieSlice *pieChartSlice_1 = pieChartSeries_1->slices().at(1);
    pieChartSlice_1->setExploded();
    pieChartSlice_1->setLabelVisible();
    pieChartSlice_1->setPen(QPen(Qt::darkGreen, 2));
    pieChartSlice_1->setBrush(Qt::green);

    QChart *pieChart_1 = new QChart();
    pieChart_1->addSeries(pieChartSeries_1);
    //pieChart_1->setTitle("Всего писем в системе:");
    pieChart_1->legend()->hide();
    pieChart_1->setAnimationOptions(QChart::SeriesAnimations);
    pieChart_1->setBackgroundBrush(QBrush(QColor("transparent")));

    QChartView *pieChartView_1 = new QChartView(pieChart_1);
    pieChartView_1->setRenderHint(QPainter::Antialiasing);
    pieChartView_1->setParent(ui->pieChart_1);
    pieChartView_1->resize(300, 270);
///////////////////////////////////////////////////////////////////
// Bar Chart
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

    QStackedBarSeries *barSeries = new QStackedBarSeries();
    barSeries->append(set0);
    barSeries->append(set1);
    barSeries->append(set2);
    barSeries->append(set3);
    barSeries->append(set4);

    QChart *barChart = new QChart();
    barChart->addSeries(barSeries);
    //barChart->setTitle("Simple stackedbarchart example");
    barChart->setAnimationOptions(QChart::SeriesAnimations);
    barChart->setBackgroundBrush(QBrush(QColor("transparent")));

    QStringList categories;
    categories << "Jan" << "Feb" << "Mar" << "Apr" << "May" << "Jun";

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    barChart->addAxis(axisX, Qt::AlignBottom);
    barSeries->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    barChart->addAxis(axisY, Qt::AlignLeft);
    barSeries->attachAxis(axisY);
    barChart->legend()->setVisible(true);
    barChart->legend()->setAlignment(Qt::AlignBottom);

    QChartView *barChartView = new QChartView(barChart);
    barChartView->setRenderHint(QPainter::Antialiasing);
    barChartView->setParent(ui->barChart);
    barChartView->resize(300, 270);
///////////////////////////////////////////////////////////////////////////
// 2 Pie Chart
    QPieSeries *pieChartSeries_2 = new QPieSeries();
    pieChartSeries_2->append("Jane", 1);
    pieChartSeries_2->append("Did", 2);
    pieChartSeries_2->append("Andy", 3);
    pieChartSeries_2->append("Barbara", 4);
    pieChartSeries_2->append("Axel", 5);
    pieChartSeries_2->setVerticalPosition(0.65);

    QPieSlice *pieChartSlice_2 = pieChartSeries_2->slices().at(1);
    pieChartSlice_2->setExploded();
    pieChartSlice_2->setLabelVisible();
    pieChartSlice_2->setPen(QPen(Qt::darkGreen, 2));
    pieChartSlice_2->setBrush(Qt::green);

    QChart *pieChart_2 = new QChart();
    pieChart_2->addSeries(pieChartSeries_2);
    //pieChart_2->setTitle("Всего писем в системе:");
    pieChart_2->legend()->hide();
    pieChart_2->setAnimationOptions(QChart::SeriesAnimations);
    pieChart_2->setBackgroundBrush(QBrush(QColor("transparent")));

    QChartView *pieChartView_2 = new QChartView(pieChart_2);
    pieChartView_2->setRenderHint(QPainter::Antialiasing);
    pieChartView_2->setParent(ui->pieChart_2);
    pieChartView_2->resize(300, 270);
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
