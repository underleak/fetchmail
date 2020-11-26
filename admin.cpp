#include "admin.h"
#include "ui_admin.h"
#include "login.h"

Admin::Admin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Admin)
{
    ui->setupUi(this);
    query = QSqlQuery(Login::get_db());
    ui->unblockAll->hide();
    ui->verifyAll->hide();
    ui->deleteAllMessages->hide();
}

Admin::~Admin()
{
    delete ui;
}

void Admin::on_getTable_clicked()
{
    ui->unblockAll->hide();
    ui->verifyAll->hide();
    ui->deleteAllMessages->hide();

    query.exec("select * from auth where login = '" + ui->lineEdit->text() + "'");
    query.first();
    recording = query.record();
    acc_ID = recording.value(0).toString();
    recording.clear();

    model = new QSqlTableModel(this, Login::get_db());
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);

    if (ui->comboBox->currentIndex() == 0)
    {
        model->setTable("auth");
        ui->unblockAll->show();
        ui->verifyAll->show();
    }

    if (ui->comboBox->currentIndex() == 1)
    {
        model->setTable("data");
        ui->deleteAllMessages->show();
    }

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
    if (ui->tableView->model())
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
}

void Admin::on_updateTable_clicked()
{
    if (ui->tableView->model())
        model->select();
}

void Admin::on_submitChanges_clicked()
{
    if (ui->tableView->model())
        model->submitAll();
}

void Admin::on_unblockAll_clicked()
{
    for (int i = 0; i < model->rowCount(); i++)
        model->setData(model->index(i, 3), 0, Qt::EditRole);
}

void Admin::on_verifyAll_clicked()
{
    for (int i = 0; i < model->rowCount(); i++)
        model->setData(model->index(i, 4), 1, Qt::EditRole);
}

void Admin::on_deleteAllMessages_clicked()
{
    model->removeRows(0, model->rowCount());
}
