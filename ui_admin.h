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
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
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
    QPushButton *updatePage;
    QComboBox *comboBox;
    QPushButton *unblockAll;
    QPushButton *verifyAll;
    QPushButton *deleteAllMessages;
    QLabel *unverifiedUsers;
    QLabel *blockedUsers;
    QLabel *totalMessages;
    QFrame *donutPieChart;
    QHBoxLayout *horizontalLayout;
    QFrame *verticalBarChart;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *backUp;
    QPushButton *importButton;

    void setupUi(QWidget *Admin)
    {
        if (Admin->objectName().isEmpty())
            Admin->setObjectName(QString::fromUtf8("Admin"));
        Admin->setWindowModality(Qt::NonModal);
        Admin->resize(1044, 700);
        QFont font;
        font.setPointSize(12);
        font.setStyleStrategy(QFont::PreferDefault);
        Admin->setFont(font);
        Admin->setContextMenuPolicy(Qt::DefaultContextMenu);
        Admin->setToolTipDuration(-1);
        Admin->setLayoutDirection(Qt::LeftToRight);
        Admin->setInputMethodHints(Qt::ImhNone);
        lineEdit = new QLineEdit(Admin);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(420, 570, 120, 25));
        tableView = new QTableView(Admin);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(50, 300, 750, 250));
        tableView->setSortingEnabled(true);
        getTable = new QPushButton(Admin);
        getTable->setObjectName(QString::fromUtf8("getTable"));
        getTable->setGeometry(QRect(550, 570, 40, 25));
        submitChanges = new QPushButton(Admin);
        submitChanges->setObjectName(QString::fromUtf8("submitChanges"));
        submitChanges->setGeometry(QRect(410, 640, 121, 31));
        submitChanges->setLayoutDirection(Qt::RightToLeft);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/main/checkmark.png"), QSize(), QIcon::Selected, QIcon::On);
        submitChanges->setIcon(icon);
        deleteSelectedRows = new QPushButton(Admin);
        deleteSelectedRows->setObjectName(QString::fromUtf8("deleteSelectedRows"));
        deleteSelectedRows->setGeometry(QRect(680, 640, 141, 31));
        deleteSelectedRows->setLayoutDirection(Qt::RightToLeft);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icon/main/trash.png"), QSize(), QIcon::Selected, QIcon::On);
        deleteSelectedRows->setIcon(icon1);
        updatePage = new QPushButton(Admin);
        updatePage->setObjectName(QString::fromUtf8("updatePage"));
        updatePage->setGeometry(QRect(130, 640, 111, 31));
        updatePage->setLayoutDirection(Qt::RightToLeft);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icon/main/renew.png"), QSize(), QIcon::Selected, QIcon::On);
        updatePage->setIcon(icon2);
        comboBox = new QComboBox(Admin);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(70, 570, 331, 25));
        unblockAll = new QPushButton(Admin);
        unblockAll->setObjectName(QString::fromUtf8("unblockAll"));
        unblockAll->setGeometry(QRect(819, 430, 171, 30));
        unblockAll->setLayoutDirection(Qt::RightToLeft);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icon/main/unlockAll.png"), QSize(), QIcon::Selected, QIcon::On);
        unblockAll->setIcon(icon3);
        verifyAll = new QPushButton(Admin);
        verifyAll->setObjectName(QString::fromUtf8("verifyAll"));
        verifyAll->setGeometry(QRect(819, 330, 171, 30));
        verifyAll->setLayoutDirection(Qt::RightToLeft);
        verifyAll->setIcon(icon);
        deleteAllMessages = new QPushButton(Admin);
        deleteAllMessages->setObjectName(QString::fromUtf8("deleteAllMessages"));
        deleteAllMessages->setGeometry(QRect(819, 530, 171, 30));
        deleteAllMessages->setLayoutDirection(Qt::RightToLeft);
        deleteAllMessages->setIcon(icon1);
        unverifiedUsers = new QLabel(Admin);
        unverifiedUsers->setObjectName(QString::fromUtf8("unverifiedUsers"));
        unverifiedUsers->setGeometry(QRect(820, 300, 171, 30));
        unverifiedUsers->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        blockedUsers = new QLabel(Admin);
        blockedUsers->setObjectName(QString::fromUtf8("blockedUsers"));
        blockedUsers->setGeometry(QRect(810, 400, 181, 30));
        blockedUsers->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        totalMessages = new QLabel(Admin);
        totalMessages->setObjectName(QString::fromUtf8("totalMessages"));
        totalMessages->setGeometry(QRect(810, 500, 181, 30));
        totalMessages->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        donutPieChart = new QFrame(Admin);
        donutPieChart->setObjectName(QString::fromUtf8("donutPieChart"));
        donutPieChart->setGeometry(QRect(50, 0, 375, 300));
        donutPieChart->setStyleSheet(QString::fromUtf8(" background-color: #212427;\n"
""));
        horizontalLayout = new QHBoxLayout(donutPieChart);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(1, 1, 1, 1);
        verticalBarChart = new QFrame(Admin);
        verticalBarChart->setObjectName(QString::fromUtf8("verticalBarChart"));
        verticalBarChart->setGeometry(QRect(480, 0, 375, 300));
        verticalBarChart->setStyleSheet(QString::fromUtf8(" background-color: #212427;"));
        horizontalLayout_2 = new QHBoxLayout(verticalBarChart);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(1, 1, 1, 1);
        backUp = new QPushButton(Admin);
        backUp->setObjectName(QString::fromUtf8("backUp"));
        backUp->setGeometry(QRect(680, 599, 141, 33));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(backUp->sizePolicy().hasHeightForWidth());
        backUp->setSizePolicy(sizePolicy);
        backUp->setSizeIncrement(QSize(0, 0));
        backUp->setBaseSize(QSize(0, 0));
        QFont font1;
        font1.setPointSize(13);
        font1.setBold(false);
        font1.setUnderline(false);
        font1.setWeight(50);
        font1.setStrikeOut(false);
        font1.setKerning(false);
        font1.setStyleStrategy(QFont::PreferDefault);
        backUp->setFont(font1);
        backUp->setMouseTracking(false);
        backUp->setTabletTracking(false);
        backUp->setFocusPolicy(Qt::StrongFocus);
        backUp->setContextMenuPolicy(Qt::NoContextMenu);
        backUp->setAcceptDrops(false);
#if QT_CONFIG(tooltip)
        backUp->setToolTip(QString::fromUtf8(""));
#endif // QT_CONFIG(tooltip)
        backUp->setToolTipDuration(0);
#if QT_CONFIG(statustip)
        backUp->setStatusTip(QString::fromUtf8(""));
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(whatsthis)
        backUp->setWhatsThis(QString::fromUtf8(""));
#endif // QT_CONFIG(whatsthis)
#if QT_CONFIG(accessibility)
        backUp->setAccessibleName(QString::fromUtf8(""));
#endif // QT_CONFIG(accessibility)
        backUp->setLayoutDirection(Qt::RightToLeft);
        backUp->setAutoFillBackground(false);
        backUp->setStyleSheet(QString::fromUtf8(""));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icon/main/downArrow.svg"), QSize(), QIcon::Selected, QIcon::On);
        backUp->setIcon(icon4);
        backUp->setIconSize(QSize(14, 14));
#if QT_CONFIG(shortcut)
        backUp->setShortcut(QString::fromUtf8(""));
#endif // QT_CONFIG(shortcut)
        backUp->setCheckable(false);
        backUp->setAutoRepeatDelay(301);
        backUp->setAutoRepeatInterval(99);
        backUp->setAutoDefault(false);
        backUp->setFlat(false);
        importButton = new QPushButton(Admin);
        importButton->setObjectName(QString::fromUtf8("importButton"));
        importButton->setGeometry(QRect(860, 600, 131, 31));
        importButton->setContextMenuPolicy(Qt::NoContextMenu);
        importButton->setAcceptDrops(false);
        importButton->setLayoutDirection(Qt::RightToLeft);
        importButton->setIcon(icon4);
        importButton->setIconSize(QSize(14, 14));

        retranslateUi(Admin);

        backUp->setDefault(false);


        QMetaObject::connectSlotsByName(Admin);
    } // setupUi

    void retranslateUi(QWidget *Admin)
    {
        Admin->setWindowTitle(QCoreApplication::translate("Admin", "Form", nullptr));
        getTable->setText(QCoreApplication::translate("Admin", "OK", nullptr));
        submitChanges->setText(QCoreApplication::translate("Admin", "\320\237\320\276\320\264\321\202\320\262\320\265\321\200\320\264\320\270\321\202\321\214", nullptr));
        deleteSelectedRows->setText(QCoreApplication::translate("Admin", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \321\201\321\202\321\200\320\276\320\272\321\203", nullptr));
        updatePage->setText(QCoreApplication::translate("Admin", "\320\236\320\261\320\275\320\276\320\262\320\270\321\202\321\214", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("Admin", "\320\222\321\213\320\262\320\265\321\201\321\202\320\270 \320\270\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\216 \320\276 \320\262\321\201\320\265\321\205 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217\321\205", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("Admin", "\320\222\321\213\320\262\320\265\321\201\321\202\320\270 \320\277\320\270\321\201\321\214\320\274\320\260 \320\262\321\201\320\265\321\205 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\320\265\320\271", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("Admin", "\320\222\321\213\320\262\320\265\321\201\321\202\320\270 \320\270\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\216 \320\276 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\320\265 \321\201 \320\273\320\276\320\263\320\270\320\275\320\276\320\274:", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("Admin", "\320\222\321\213\320\262\320\265\321\201\321\202\320\270 \320\277\320\270\321\201\321\214\320\274\320\260 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217 \321\201 \320\273\320\276\320\263\320\270\320\275\320\276\320\274:", nullptr));

        unblockAll->setText(QCoreApplication::translate("Admin", "\320\240\320\260\320\267\320\261\320\273\320\276\320\272\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \320\262\321\201\320\265\321\205", nullptr));
        verifyAll->setText(QCoreApplication::translate("Admin", "\320\237\320\276\320\264\321\202\320\262\320\265\321\200\320\264\320\270\321\202\321\214 \320\262\321\201\320\265\321\205", nullptr));
        deleteAllMessages->setText(QCoreApplication::translate("Admin", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\262\321\201\320\265 \320\277\320\270\321\201\321\214\320\274\320\260", nullptr));
#if QT_CONFIG(tooltip)
        unverifiedUsers->setToolTip(QCoreApplication::translate("Admin", "<html><head/><body><p align=\"center\"><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        unverifiedUsers->setText(QCoreApplication::translate("Admin", "<html><head/><body><p align=\"center\">\320\222\321\201\320\265\320\263\320\276 \320\275\320\260 \320\277\320\276\320\264\321\202\320\262\320\265\321\200\320\266\320\264\320\265\320\275\320\270\320\270:</p></body></html>", nullptr));
#if QT_CONFIG(tooltip)
        blockedUsers->setToolTip(QCoreApplication::translate("Admin", "<html><head/><body><p align=\"center\"><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        blockedUsers->setText(QCoreApplication::translate("Admin", "<html><head/><body><p align=\"center\">\320\222\321\201\320\265\320\263\320\276 \320\267\320\260\320\261\320\273\320\276\320\272\320\270\321\200\320\276\320\262\320\260\320\275\320\276:</p></body></html>", nullptr));
#if QT_CONFIG(tooltip)
        totalMessages->setToolTip(QCoreApplication::translate("Admin", "<html><head/><body><p align=\"center\"><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        totalMessages->setText(QCoreApplication::translate("Admin", "<html><head/><body><p align=\"center\">\320\222\321\201\320\265\320\263\320\276 \320\277\320\270\321\201\320\265\320\274 \320\262 \321\201\320\270\321\201\321\202\320\265\320\274\320\265:</p></body></html>", nullptr));
        backUp->setText(QCoreApplication::translate("Admin", "BackUp", nullptr));
        importButton->setText(QCoreApplication::translate("Admin", "Import", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Admin: public Ui_Admin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMIN_H
