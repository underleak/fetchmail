#include "messages.h"
#include "login.h"
#include "ui_messages.h"
#include <QList>
#include <QDebug>



Messages::Messages(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Messages)
{
    ui->setupUi(this);
    this->setFixedSize(1000,700);
    listWidget =new QListWidget(this);
    listWidget->setFixedSize(300,570);
    query = QSqlQuery(Login::get_db());
    QFont fonts("Helvetica", 12, QFont::Bold);
    listWidget->setFont(fonts);

    zapros="select * from data where acc_id = ";
    connect (this->listWidget,SIGNAL(itemClicked(QListWidgetItem *)),this,SLOT(display(QListWidgetItem *)));
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
    query.exec(zapros + QString::number(this->acc_id));
    rec = query.record();
    while (query.next()) {
        counter++;
        if(counter==(listWidget->row(msg)+1)) ui->textBrowser->setText(" Theme: " + query.value(rec.indexOf("theme")).toString()+ "\n From:" +
                                                                       query.value(rec.indexOf("from")).toString() + "\n To:" +query.value(rec.indexOf("to")).toString() +
                                                                       "\n Date:  " + query.value(rec.indexOf("date")).toString() + "\n\n" + query.value(rec.indexOf("text")).toString());
    }
    //qDebug()<<this->acc_id;
    query.clear();
    rec.clear();
}

void Messages::refresh()
{
    listWidget->clear();
    query.exec(zapros + QString::number(this->acc_id));
    rec = query.record();

    int count=0;
    while (query.next()) {
        count++;
        QListWidgetItem *newItem = new QListWidgetItem;
        newItem->setText( "\n Theme: " + query.value(rec.indexOf("theme")).toString()+ "\n From:" +
                          query.value(rec.indexOf("from")).toString() +
                          "\n Date:  " + query.value(rec.indexOf("date")).toString() + "\n");
        listWidget->insertItem(count, newItem);
        newItem->setData(Qt::UserRole,query.value(rec.indexOf("msg_id")).toInt());

    }
    rec.clear();
    query.clear();
    ui->label->setText("Всего полученно писем: " + QString::number(count));
}

void Messages::shortDisplay()
{
    query.exec (zapros + QString::number(this->acc_id));
    rec = query.record();
    refresh();
    query.clear();
    rec.clear();
}

void Messages::getStats()
{

///Анализ текста письма

}

void Messages::on_refreshButton_clicked()
{
    listWidget->clear();
    refresh();
}

void Messages::on_hideButton_clicked()
{
    query.clear();
    QString deleteQuery;

    QList <QListWidgetItem *> list = listWidget->selectedItems();
    QList <QListWidgetItem *> :: iterator itt;
    itt=list.begin();

    QListWidgetItem * ptr;
    for (int i=1; i<=list.size(); i++ ) {

        int tmp=listWidget->row(*itt);
        ptr = listWidget->item(tmp);
        deleteQuery = "delete from data where msg_id = " + ptr->data(Qt::UserRole).toString();
        query.exec(deleteQuery);
        qDebug()<<deleteQuery;
        itt++;
    }
    query.clear();
    refresh();

    listWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->choiceButton->setChecked(false);
}

void Messages::on_choiceButton_clicked()
{
    (listWidget->selectionMode()==QAbstractItemView::MultiSelection) ? listWidget->setSelectionMode(QAbstractItemView::SingleSelection)
                                                                     : listWidget->setSelectionMode(QAbstractItemView::MultiSelection);
}














