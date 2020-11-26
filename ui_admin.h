/********************************************************************************
** Form generated from reading UI file 'admin.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMIN_H
#define UI_ADMIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Admin
{
public:
    QLineEdit *lineEdit;
    QTableView *tableView;
    QPushButton *getTable;
    QPushButton *submitChanges;
    QPushButton *deleteSelectedRows;
    QPushButton *updateTable;
    QComboBox *comboBox;
    QLabel *label;
    QPushButton *unblockAll;
    QPushButton *verifyAll;
    QPushButton *deleteAllMessages;

    void setupUi(QWidget *Admin)
    {
        if (Admin->objectName().isEmpty())
            Admin->setObjectName(QString::fromUtf8("Admin"));
        Admin->resize(791, 502);
        lineEdit = new QLineEdit(Admin);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(340, 40, 120, 25));
        tableView = new QTableView(Admin);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(60, 210, 651, 251));
        tableView->setSortingEnabled(true);
        getTable = new QPushButton(Admin);
        getTable->setObjectName(QString::fromUtf8("getTable"));
        getTable->setGeometry(QRect(470, 40, 40, 25));
        submitChanges = new QPushButton(Admin);
        submitChanges->setObjectName(QString::fromUtf8("submitChanges"));
        submitChanges->setGeometry(QRect(340, 470, 80, 21));
        deleteSelectedRows = new QPushButton(Admin);
        deleteSelectedRows->setObjectName(QString::fromUtf8("deleteSelectedRows"));
        deleteSelectedRows->setGeometry(QRect(610, 470, 100, 21));
        updateTable = new QPushButton(Admin);
        updateTable->setObjectName(QString::fromUtf8("updateTable"));
        updateTable->setGeometry(QRect(60, 470, 80, 21));
        comboBox = new QComboBox(Admin);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(60, 40, 280, 25));
        label = new QLabel(Admin);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(80, 130, 500, 20));
        unblockAll = new QPushButton(Admin);
        unblockAll->setObjectName(QString::fromUtf8("unblockAll"));
        unblockAll->setGeometry(QRect(640, 110, 120, 25));
        verifyAll = new QPushButton(Admin);
        verifyAll->setObjectName(QString::fromUtf8("verifyAll"));
        verifyAll->setGeometry(QRect(640, 160, 120, 25));
        deleteAllMessages = new QPushButton(Admin);
        deleteAllMessages->setObjectName(QString::fromUtf8("deleteAllMessages"));
        deleteAllMessages->setGeometry(QRect(490, 160, 120, 25));

        retranslateUi(Admin);

        QMetaObject::connectSlotsByName(Admin);
    } // setupUi

    void retranslateUi(QWidget *Admin)
    {
        Admin->setWindowTitle(QCoreApplication::translate("Admin", "Form", nullptr));
        getTable->setText(QCoreApplication::translate("Admin", "OK", nullptr));
        submitChanges->setText(QCoreApplication::translate("Admin", "\320\237\320\276\320\264\321\202\320\262\320\265\321\200\320\264\320\270\321\202\321\214", nullptr));
        deleteSelectedRows->setText(QCoreApplication::translate("Admin", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \321\201\321\202\321\200\320\276\320\272\321\203", nullptr));
        updateTable->setText(QCoreApplication::translate("Admin", "\320\236\320\261\320\275\320\276\320\262\320\270\321\202\321\214", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("Admin", "\320\222\321\213\320\262\320\265\321\201\321\202\320\270 \320\270\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\216 \320\276 \320\262\321\201\320\265\321\205 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217\321\205", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("Admin", "\320\222\321\213\320\262\320\265\321\201\321\202\320\270 \320\277\320\270\321\201\321\214\320\274\320\260 \320\262\321\201\320\265\321\205 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\320\265\320\271", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("Admin", "\320\222\321\213\320\262\320\265\321\201\321\202\320\270 \320\270\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\216 \320\276 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\320\265 \321\201 \320\273\320\276\320\263\320\270\320\275\320\276\320\274:", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("Admin", "\320\222\321\213\320\262\320\265\321\201\321\202\320\270 \320\277\320\270\321\201\321\214\320\274\320\260 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217 \321\201 \320\273\320\276\320\263\320\270\320\275\320\276\320\274:", nullptr));

        label->setText(QCoreApplication::translate("Admin", "\320\242\321\203\321\202 \320\261\321\203\320\264\320\265\321\202 \321\200\320\260\320\267\320\275\320\260\321\217 \321\201\321\202\320\260\321\202\320\270\321\201\321\202\320\270\321\207\320\265\321\201\320\272\320\260\321\217 \320\270\320\275\321\204\320\260 \320\262 \320\267\320\260\320\262\320\270\321\201\320\270\320\274\320\276\321\201\321\202\320\270 \320\276\321\202 \320\262\321\213\320\261\321\200\320\260\320\275\320\275\320\276\320\263\320\276 \320\277\320\260\321\200\320\260\320\274\320\265\321\202\321\200\320\260 \321\207\320\265\320\272\320\261\320\276\320\272\321\201\320\260 \320\262\321\213\321\210\320\265", nullptr));
        unblockAll->setText(QCoreApplication::translate("Admin", "\320\240\320\260\320\267\320\261\320\273\320\276\320\272\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \320\262\321\201\320\265\321\205", nullptr));
        verifyAll->setText(QCoreApplication::translate("Admin", "\320\237\320\276\320\264\321\202\320\262\320\265\321\200\320\264\320\270\321\202\321\214 \320\262\321\201\320\265\321\205", nullptr));
        deleteAllMessages->setText(QCoreApplication::translate("Admin", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\262\321\201\320\265 \320\277\320\270\321\201\321\214\320\274\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Admin: public Ui_Admin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMIN_H
