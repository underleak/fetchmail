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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Messages
{
public:
    QTextBrowser *textBrowser;
    QPushButton *refreshButton;
    QLabel *label;
    QPushButton *hideButton;
    QPushButton *choiceButton;

    void setupUi(QWidget *Messages)
    {
        if (Messages->objectName().isEmpty())
            Messages->setObjectName(QString::fromUtf8("Messages"));
        Messages->resize(1000, 700);
        textBrowser = new QTextBrowser(Messages);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(300, 0, 700, 570));
        textBrowser->setReadOnly(true);
        refreshButton = new QPushButton(Messages);
        refreshButton->setObjectName(QString::fromUtf8("refreshButton"));
        refreshButton->setGeometry(QRect(20, 610, 77, 24));
        label = new QLabel(Messages);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(340, 620, 301, 16));
        hideButton = new QPushButton(Messages);
        hideButton->setObjectName(QString::fromUtf8("hideButton"));
        hideButton->setGeometry(QRect(183, 610, 77, 24));
        choiceButton = new QPushButton(Messages);
        choiceButton->setObjectName(QString::fromUtf8("choiceButton"));
        choiceButton->setEnabled(true);
        choiceButton->setGeometry(QRect(101, 650, 78, 24));
        choiceButton->setCheckable(true);
        choiceButton->setFlat(false);

        retranslateUi(Messages);

        QMetaObject::connectSlotsByName(Messages);
    } // setupUi

    void retranslateUi(QWidget *Messages)
    {
        Messages->setWindowTitle(QCoreApplication::translate("Messages", "Form", nullptr));
        refreshButton->setText(QCoreApplication::translate("Messages", "Refresh", nullptr));
        label->setText(QCoreApplication::translate("Messages", "TextLabel", nullptr));
        hideButton->setText(QCoreApplication::translate("Messages", "Hide", nullptr));
        choiceButton->setText(QCoreApplication::translate("Messages", "Choose", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Messages: public Ui_Messages {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESSAGES_H
