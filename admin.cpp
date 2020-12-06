#include "admin.h"
#include "ui_admin.h"
#include "login.h"

Admin::Admin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Admin)
{
    ui->setupUi(this);
    ui->blockedUsers->setAlignment(Qt::AlignCenter);
    ui->unverifiedUsers->setAlignment(Qt::AlignCenter);
    ui->totalMessages->setAlignment(Qt::AlignCenter);

    database = new Database();

    statistics = new Statistics(ui);
    statistics->updateStats();
    on_getTable_clicked();
    statistics->getDonutPieChart();
    statistics->getVerticalBarChart();
}

Admin::~Admin()
{
    delete ui;
}

void Admin::on_getTable_clicked()
{
    database->query.exec("select * from auth where login = '" + ui->lineEdit->text() + "'");
    database->query.first();
    database->queryRecord = database->query.record();
    statistics->acc_ID = database->queryRecord.value(0).toString();
    database->queryRecord.clear();

    model = new QSqlTableModel(this, database->getDatabase());
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);

    if (ui->comboBox->currentIndex() == 0)
        model->setTable("auth");

    if (ui->comboBox->currentIndex() == 1)
        model->setTable("data");

    if (ui->comboBox->currentIndex() == 2)
    {
        model->setTable("auth");
        model->setFilter("acc_ID = " + statistics->acc_ID);
    }

    if (ui->comboBox->currentIndex() == 3)
    {
        model->setTable("data");
        model->setFilter("acc_id = " + statistics->acc_ID);
    }

    if (!statistics->acc_ID.toInt() && ui->comboBox->currentIndex() > 1)
        QMessageBox::critical(this, "Пользователь не найден", "Пожалуйста, введите существующий логин.", QMessageBox::Ok);

    else {
        model->select();
        ui->tableView->setModel(model);
        on_updatePage_clicked();
    }
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
    statistics->updateStats();
    statistics->getDonutPieChart();
    statistics->getVerticalBarChart();
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
        database->query.exec("update auth set isBlocked = 0");
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
        database->query.exec("update auth set isVerified = 1");
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
            database->query.exec("DELETE FROM data WHERE msg_id;");
    }
}
