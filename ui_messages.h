/********************************************************************************
** Form generated from reading UI file 'messages.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MESSAGES_H
#define UI_MESSAGES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Messages
{
public:
    QTextBrowser *textBrowser;
    QPushButton *refreshButton;
    QLabel *msgsAmountLBL;
    QPushButton *hideButton;
    QPushButton *choiceButton;
    QLabel *avatar;
    QLabel *loginLabel;
    QLabel *nameLBL;
    QLabel *surnameLBL;
    QLabel *dateBirthLBL;
    QLineEdit *nameEdit;
    QLineEdit *surnameEdit;
    QLineEdit *birthEbit;
    QPushButton *changePersInfo;
    QPushButton *applyChanges;
    QToolButton *toolButton;
    QPushButton *accSet;

    void setupUi(QWidget *Messages)
    {
        if (Messages->objectName().isEmpty())
            Messages->setObjectName(QString::fromUtf8("Messages"));
        Messages->resize(1000, 700);
        textBrowser = new QTextBrowser(Messages);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(300, 0, 700, 500));
        textBrowser->setReadOnly(true);
        refreshButton = new QPushButton(Messages);
        refreshButton->setObjectName(QString::fromUtf8("refreshButton"));
        refreshButton->setGeometry(QRect(20, 530, 77, 24));
        msgsAmountLBL = new QLabel(Messages);
        msgsAmountLBL->setObjectName(QString::fromUtf8("msgsAmountLBL"));
        msgsAmountLBL->setGeometry(QRect(570, 520, 181, 16));
        hideButton = new QPushButton(Messages);
        hideButton->setObjectName(QString::fromUtf8("hideButton"));
        hideButton->setGeometry(QRect(183, 530, 77, 24));
        choiceButton = new QPushButton(Messages);
        choiceButton->setObjectName(QString::fromUtf8("choiceButton"));
        choiceButton->setEnabled(true);
        choiceButton->setGeometry(QRect(101, 570, 78, 24));
        choiceButton->setCheckable(true);
        choiceButton->setFlat(false);
        avatar = new QLabel(Messages);
        avatar->setObjectName(QString::fromUtf8("avatar"));
        avatar->setGeometry(QRect(759, 510, 150, 140));
        avatar->setStyleSheet(QString::fromUtf8("border-radius:5px;"));
        loginLabel = new QLabel(Messages);
        loginLabel->setObjectName(QString::fromUtf8("loginLabel"));
        loginLabel->setGeometry(QRect(570, 550, 171, 16));
        nameLBL = new QLabel(Messages);
        nameLBL->setObjectName(QString::fromUtf8("nameLBL"));
        nameLBL->setGeometry(QRect(316, 519, 27, 16));
        surnameLBL = new QLabel(Messages);
        surnameLBL->setObjectName(QString::fromUtf8("surnameLBL"));
        surnameLBL->setGeometry(QRect(316, 549, 58, 16));
        dateBirthLBL = new QLabel(Messages);
        dateBirthLBL->setObjectName(QString::fromUtf8("dateBirthLBL"));
        dateBirthLBL->setGeometry(QRect(316, 579, 97, 16));
        nameEdit = new QLineEdit(Messages);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));
        nameEdit->setEnabled(false);
        nameEdit->setGeometry(QRect(419, 519, 125, 24));
        surnameEdit = new QLineEdit(Messages);
        surnameEdit->setObjectName(QString::fromUtf8("surnameEdit"));
        surnameEdit->setEnabled(false);
        surnameEdit->setGeometry(QRect(419, 549, 125, 24));
        birthEbit = new QLineEdit(Messages);
        birthEbit->setObjectName(QString::fromUtf8("birthEbit"));
        birthEbit->setEnabled(false);
        birthEbit->setGeometry(QRect(419, 579, 125, 24));
        changePersInfo = new QPushButton(Messages);
        changePersInfo->setObjectName(QString::fromUtf8("changePersInfo"));
        changePersInfo->setGeometry(QRect(339, 620, 91, 24));
        applyChanges = new QPushButton(Messages);
        applyChanges->setObjectName(QString::fromUtf8("applyChanges"));
        applyChanges->setGeometry(QRect(440, 620, 80, 24));
        toolButton = new QToolButton(Messages);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setGeometry(QRect(875, 660, 24, 19));
        toolButton->setCursor(QCursor(Qt::PointingHandCursor));
        accSet = new QPushButton(Messages);
        accSet->setObjectName(QString::fromUtf8("accSet"));
        accSet->setGeometry(QRect(750, 660, 121, 24));

        retranslateUi(Messages);

        QMetaObject::connectSlotsByName(Messages);
    } // setupUi

    void retranslateUi(QWidget *Messages)
    {
        Messages->setWindowTitle(QCoreApplication::translate("Messages", "Form", nullptr));
        refreshButton->setText(QCoreApplication::translate("Messages", "Refresh", nullptr));
        msgsAmountLBL->setText(QCoreApplication::translate("Messages", "msgsAmount", nullptr));
        hideButton->setText(QCoreApplication::translate("Messages", "Hide", nullptr));
        choiceButton->setText(QCoreApplication::translate("Messages", "Choose", nullptr));
        avatar->setText(QCoreApplication::translate("Messages", "avatar", nullptr));
        loginLabel->setText(QCoreApplication::translate("Messages", "loginLabel", nullptr));
        nameLBL->setText(QCoreApplication::translate("Messages", "\320\230\320\274\321\217", nullptr));
        surnameLBL->setText(QCoreApplication::translate("Messages", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217", nullptr));
        dateBirthLBL->setText(QCoreApplication::translate("Messages", "\320\224\320\260\321\202\320\260 \321\200\320\276\320\266\320\264\320\265\320\275\320\270\321\217", nullptr));
        changePersInfo->setText(QCoreApplication::translate("Messages", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        applyChanges->setText(QCoreApplication::translate("Messages", "\320\236\320\272", nullptr));
        toolButton->setText(QCoreApplication::translate("Messages", "...", nullptr));
        accSet->setText(QCoreApplication::translate("Messages", "\320\243\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\320\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Messages: public Ui_Messages {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESSAGES_H
