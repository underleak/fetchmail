#ifndef MESSAGES_H
#define MESSAGES_H

#include <QListWidget>
#include <QFont>
#include <QBitmap>
#include <QPainter>
#include <QFileDialog>
#include <QImage>
#include <QAction>
#include <QMenu>
#include <QDialog>
#include <QDialogButtonBox>
#include <QFormLayout>
#include "database.h"
#include "login.h"

namespace Ui { class Messages; }

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
    Database *database;
    QListWidget *listWidget;
    QString zapros;
    void refresh();
    void getStats();
    void updateInfo();

public slots:
    void display (QListWidgetItem *);

private slots:
    void on_refreshButton_clicked();
    void on_hideButton_clicked();
    void on_choiceButton_clicked();
    void on_changePersInfo_clicked();
    void on_applyChanges_clicked();
    void on_toolButton_clicked();
    void slotBlock();
    void slotDelete();
    void changePassword();
};

#endif // MESSAGES_H
