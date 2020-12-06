#include "messages.h"
#include "login.h"
#include "ui_messages.h"
#include <QList>
#include <QDebug>
#include <QBitmap>
#include <QPainter>
#include <QFileDialog>
#include <QImage>
#include <QAction>
#include <QMenu>
#include <QMessageBox>
#include <QDialog>
#include <QFormLayout>
#include <QDialogButtonBox>

Messages::Messages(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Messages)
{
    ui->setupUi(this);
    this->setFixedSize(1000,700);
    listWidget =new QListWidget(this);
    listWidget->setFixedSize(300,500);

    database = new Database();

    QFont fonts("Helvetica", 12, QFont::Bold);
    listWidget->setFont(fonts);

    zapros="select * from data where acc_id = ";
    connect (this->listWidget,SIGNAL(itemClicked(QListWidgetItem *)),this,SLOT(display(QListWidgetItem *)));



    QMenu *file = new QMenu();
    QAction *delte = new QAction("Удалить аккаунт");
    QAction *block = new QAction("Заблокировать аккаунт");
    QAction *changePass = new QAction("Изменить пароль");

    file->addAction(delte);
    file->addAction(block);
    file->addAction(changePass);
    connect(block, SIGNAL(triggered()), this, SLOT(slotBlock()));
    connect(delte, SIGNAL(triggered()), this, SLOT(slotDelete()));
    connect(changePass, SIGNAL(triggered()), this, SLOT(changePassword()));
    ui->accSet->setMenu(file);


}

Messages::~Messages()
{
    delete ui;
}

void Messages::display (QListWidgetItem * msg)
{


    int counter=0;
    //query.next() дает переход на новыую строчку
    //query.value(2) берет все значения из 2 колонки таблицы
    database->query.exec(zapros + QString::number(this->acc_id));
    rec = database->query.record();
    while (database->query.next()) {
        counter++;
        if(counter==(listWidget->row(msg)+1)) ui->textBrowser->setText(" Theme: " + database->query.value(rec.indexOf("theme")).toString()+ "\n From:" +
                                                                       database->query.value(rec.indexOf("from")).toString() + "\n To:" +database->query.value(rec.indexOf("to")).toString() +
                                                                       "\n Date:  " + database->query.value(rec.indexOf("date")).toString() + "\n\n" + database->query.value(rec.indexOf("text")).toString());

    }

    //qDebug()<<this->acc_id;
    database->query.clear();
    rec.clear();

}

void Messages::refresh()
{

    listWidget->clear();
    database->query.exec(zapros + QString::number(this->acc_id));
    rec = database->query.record();


    int count=0;
    while (database->query.next()) {
        count++;
        QListWidgetItem *newItem = new QListWidgetItem;
        newItem->setText( "\n Theme: " + database->query.value(rec.indexOf("theme")).toString()+ "\n From:" +
                          database->query.value(rec.indexOf("from")).toString() +
                          "\n Date:  " + database->query.value(rec.indexOf("date")).toString() + "\n");
        listWidget->insertItem(count, newItem);
        newItem->setData(Qt::UserRole,database->query.value(rec.indexOf("msg_id")).toInt());

    }

    database->query.first();
    ui->loginLabel->setText("Почта: " +  database->query.value(rec.indexOf("to")).toString());
    ui->msgsAmountLBL->setText("Всего полученно писем: " + QString::number(count));
    rec.clear();
    database->query.clear();


/////////////////////////////////////////////////////////////////////////////////////////////////////////

    QSqlQuery ava = QSqlQuery();
    QSqlRecord avar = QSqlRecord();
    ava.exec("select * from auth where acc_id = " + QString::number(this->acc_id));
    avar = ava.record();
    ava.first();
    ui->nameEdit->setText(ava.value(avar.indexOf("name")).toString());
    ui->surnameEdit->setText(ava.value(avar.indexOf("surname")).toString());
    QPixmap avat = QPixmap(ava.value(avar.indexOf("avatar")).toString());
    ui->avatar->setPixmap(avat.scaled(150,140));

/////////////////////////////////////////////////////////////////////////////////////////////////////////


}

void Messages::shortDisplay()
{

    database->query.exec (zapros + QString::number(this->acc_id));
    rec = database->query.record();
    refresh();
    database->query.clear();
    rec.clear();


}

void Messages::getStats()
{///Анализ текста письма 
}

void Messages::on_refreshButton_clicked()
{
    listWidget->clear();
    refresh();

}

void Messages::on_hideButton_clicked()
{

    database->query.clear();
    QString deleteQuery;

    QList <QListWidgetItem *> list = listWidget->selectedItems();
    QList <QListWidgetItem *> :: iterator itt;
    itt=list.begin();


    QListWidgetItem * ptr;
    for (int i=1; i<=list.size(); i++ ) {

        int tmp=listWidget->row(*itt);
        ptr = listWidget->item(tmp);
        deleteQuery = "delete from data where msg_id = " + ptr->data(Qt::UserRole).toString();
        database->query.exec(deleteQuery);
        qDebug()<<deleteQuery;
        itt++;

    }
    database->query.clear();
    refresh();

    listWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->choiceButton->setChecked(false);

}

void Messages::on_choiceButton_clicked()
{

    (listWidget->selectionMode()==QAbstractItemView::MultiSelection)?listWidget->setSelectionMode(QAbstractItemView::SingleSelection):
                                                                     listWidget->setSelectionMode(QAbstractItemView::MultiSelection);

}

void Messages::updateInfo()
{

    QSqlQuery updateQuery = QSqlQuery();
    updateQuery.exec("update auth set name = '" + ui->nameEdit->text() + "' where acc_ID = " +  QString::number(this->acc_id));
    updateQuery.clear();
    updateQuery.exec("update auth set surname = '" + ui->surnameEdit->text() + "' where acc_ID = " + QString::number(this->acc_id));
    updateQuery.clear();
    refresh();




}

void Messages::on_changePersInfo_clicked()
{
    ui->nameEdit->setEnabled(true);
    ui->surnameEdit->setEnabled(true);
    ui->birthEbit->setEnabled(true);
}

void Messages::on_applyChanges_clicked()
{
    updateInfo();
    ui->nameEdit->setEnabled(false);
    ui->surnameEdit->setEnabled(false);
    ui->birthEbit->setEnabled(false);

}

void Messages::on_toolButton_clicked()
{
    QString path = QFileDialog::getOpenFileName(
            this, "Open Dialog", "", "*.png *.jpg *.bmp *.JPG");

     QSqlQuery imgQuery = QSqlQuery();
     QString lal = "UPDATE auth SET avatar = '" + path + "' WHERE acc_ID = " + QString::number(this->acc_id) + ";";
     imgQuery.exec(lal);
     qDebug()<<lal;
     refresh();

}

void Messages::slotBlock()
{
    QSqlQuery updateQuery = QSqlQuery();
    updateQuery.exec("update auth set isBlocked = '1' where acc_ID = " +  QString::number(this->acc_id));

}

void Messages::slotDelete()
{
    QSqlQuery updateQuery = QSqlQuery();
    QMessageBox msgBox;
    QPushButton *confirmButton = msgBox.addButton(tr("Удалить"), QMessageBox::ActionRole);
    msgBox.setIcon(QMessageBox::Critical);
    msgBox.setText("Вы уверенны, что хотите удалит аккаунт? \nВсе данные будут удалены");
    msgBox.exec();
    if (msgBox.clickedButton() == confirmButton){
        updateQuery.exec("update auth set isBlocked = '1' where acc_ID = " +  QString::number(this->acc_id));
    }

}

void Messages::changePassword()
{





    QDialog dlg(this);
    dlg.setWindowTitle(tr("Обновление пароля"));

    QLineEdit *ledit1 = new QLineEdit(&dlg);
    QLineEdit *ledit2 = new QLineEdit(&dlg);

    QDialogButtonBox *btn_box = new QDialogButtonBox(&dlg);
    btn_box->setStandardButtons(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);

    connect(btn_box, &QDialogButtonBox::accepted, &dlg, &QDialog::accept);
    connect(btn_box, &QDialogButtonBox::rejected, &dlg, &QDialog::reject);

    QFormLayout *layout = new QFormLayout();
    layout->addRow(tr("Ваш текущий пароль:"), ledit1);
    layout->addRow(tr("Новый пароль:"), ledit2);
    layout->addWidget(btn_box);

    dlg.setLayout(layout);

    // В случае, если пользователь нажал "Ok".
    if(dlg.exec() == QDialog::Accepted) {
          QSqlQuery passwordQuery = QSqlQuery();
          passwordQuery.exec("select password from auth where acc_id = " + QString::number(this->acc_id));
          QSqlRecord tmp = passwordQuery.record();

          passwordQuery.first();
         if (passwordQuery.value(tmp.indexOf("password")).toString() == ledit1->text()){
             passwordQuery.clear();
             QString changeString = "update auth set password = '" + ledit2->text() + "' where acc_ID = " +  QString::number(this->acc_id);
             passwordQuery.exec(changeString);

         }
         else {
             QMessageBox msgBox;
             msgBox.setIcon(QMessageBox::Critical);
             msgBox.setText("Вы ввели не существующий пароль");
             msgBox.exec();

         }


       dlg.close();

    }


}



