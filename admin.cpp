#include "admin.h"
#include "ui_admin.h"

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

    QMenu *file = new QMenu();
    QAction *fullBackUp = new QAction("Полный бэкап");
    QAction *structBackUp = new QAction("Бэкап структуры");

    file->addAction(fullBackUp);
    file->addAction(structBackUp);
    connect(fullBackUp, SIGNAL(triggered()), this, SLOT(slotFullBackUp()));
    connect(structBackUp, SIGNAL(triggered()), this, SLOT(slotStructBackUp()));
    ui->backUp->setMenu(file);

    QMenu *imp = new QMenu();
    QAction *rmImport = new QAction("Имопрт с перезаписью");
    QAction *addImp = new QAction("Импорт с дозаписью");
    imp->addAction(rmImport);
    imp->addAction(addImp);
    connect(rmImport, SIGNAL(triggered()), this, SLOT(slotrmImport()));
    connect(addImp, SIGNAL(triggered()), this, SLOT(slotaddImport()));
    ui->importButton->setMenu(imp);
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

QString Admin::on_backUp_clicked()
{
    QString path = QFileDialog::getExistingDirectory(
                this, "Open Dialog","");
    return path;
}

void Admin::slotFullBackUp()
{
    char* systemQuery = "/usr/local/mysql-8.0.21-macos10.15-x86_64/bin/mysqldump -uroot -p20643579 testdb> ";
    QTime time = QTime::currentTime();
    QString tmpTime = time.toString();

    QString tmpStr = systemQuery +  on_backUp_clicked() + "/backup" + tmpTime + ".sql";
    std::string str = tmpStr.toStdString();
    const char* p = str.c_str();
    qDebug()<<p;
    system(p);
}
void Admin::slotStructBackUp()
{
    char* systemQuery = "/usr/local/mysql-8.0.21-macos10.15-x86_64/bin/mysqldump -t -uroot -p20643579  --no-data testdb --fields-enclosed-by=\\n --fields-terminated-by=, > "; //--xml

    QTime time = QTime::currentTime();
    QString tmpTime = time.toString();

    QString tmpStr = systemQuery +  on_backUp_clicked() + "/backup" + tmpTime + ".csv";
    std::string str = tmpStr.toStdString();
    const char* p = str.c_str();
    qDebug()<<p;

    system(p);
}

//usr/local/mysql-8.0.21-macos10.15-x86_64/bin/mysqldump  -uroot -p20643579  --no-data testdb --xml > /Users/pavelprodanov/Desktop/backup10:19:28.xml

/*
LOAD DATA  INFILE '/usr/local/mysql/data/auth2.csv'
INTO TABLE testdb.auth
FIELDS TERMINATED BY ','
ENCLOSED BY ''''
LINES TERMINATED BY '\n'
IGNORE 1 LINES
(login, password, isBlocked, isVerifed, avatar,name,surname,dateBirth);*/

void Admin::slotaddImport()
{
    QString path = "cp " + QFileDialog::getOpenFileName(
                this, "Open Dialog"," *.csv");
    std::string strPath = path.toStdString();

    strPath+=" /usr/local/mysql/data";
    const char* final = strPath.c_str();
    system(final);

    QString result;
    bool flag = false;
    for (auto i = path.end(); i >= path.begin(); --i){
        if (*i == '/'){
            while (i != path.end()) {
                result.push_back(*i);
                i++;
            }
            flag = true;
        }
        if (flag == true) break;
    }

    QString importStr = "LOAD DATA  INFILE '/usr/local/mysql/data" + result +
            "' INTO TABLE testdb.auth "
            "FIELDS TERMINATED BY ',' "
            "ENCLOSED BY '''' "
            "LINES TERMINATED BY '\n' "
            "IGNORE 1 LINES "
            "(login, password, isBlocked, isVerifed, avatar,name,surname,dateBirth)";
    qDebug()<<importStr;

    QSqlQuery importQuery = QSqlQuery();
    importQuery.exec(importStr);

    std::string tmp = result.toStdString();
    std::string rmStr = "rm /usr/local/mysql/data" + tmp;
    const char* rmChar = rmStr.c_str();
    qDebug()<<rmChar;
    system(rmChar);
}

void Admin::slotrmImport()
{
    QString path = "cp " + QFileDialog::getOpenFileName(
                this, "Open Dialog"," *.csv");
    std::string strPath = path.toStdString();

    strPath+=" /usr/local/mysql/data";
    const char* final = strPath.c_str();
    system(final);

    QString result;
    bool flag = false;
    for (auto i = path.end(); i >= path.begin(); --i){
        if (*i == '/'){
            while (i != path.end()) {
                result.push_back(*i);
                i++;
            }
            flag = true;
        }
        if (flag == true) break;
    }

    QString importStr = "LOAD DATA  INFILE '/usr/local/mysql/data" + result +
            "' INTO TABLE testdb.auth "
            "FIELDS TERMINATED BY ',' "
            "ENCLOSED BY '''' "
            "LINES TERMINATED BY '\n' "
            "IGNORE 1 LINES "
            "(login, password, isBlocked, isVerifed, avatar,name,surname,dateBirth)";
    qDebug()<<importStr;

    QSqlQuery importQuery = QSqlQuery();
    importQuery.exec("delete from auth");
    importQuery.clear();
    importQuery.exec(importStr);

    std::string tmp = result.toStdString();
    std::string rmStr = "rm /usr/local/mysql/data" + tmp;
    const char* rmChar = rmStr.c_str();
    qDebug()<<rmChar;
    system(rmChar);
}
