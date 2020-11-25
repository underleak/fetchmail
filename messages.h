#ifndef MESSAGES_H
#define MESSAGES_H

#include <QWidget>
#include <QListWidget>
#include <QString>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QFont>

namespace Ui {
class Messages;
}

class Messages : public QWidget
{
    Q_OBJECT

public:
    explicit Messages(QWidget *parent = nullptr);
    int acc_id;

    void shortDisplay();
    ~Messages();

private:
    Ui::Messages *ui;
    QListWidget *listWidget;
    QSqlQuery query;
    QString zapros;
    QSqlRecord rec;
    void refresh();
    void getStats();

public slots:
      void  display (QListWidgetItem *);

private slots:
      void on_refreshButton_clicked();
      void on_hideButton_clicked();
      void on_choiceButton_clicked();
};

#endif // MESSAGES_H
