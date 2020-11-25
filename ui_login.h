/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton_2;
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_5;
    QLineEdit *lineEdit_2;
    QLabel *label_2;
    QPushButton *pushButton_3;
    QLineEdit *lineEdit;
    QPushButton *pushButton_4;

    void setupUi(QMainWindow *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QString::fromUtf8("Login"));
        Login->resize(800, 500);
        centralwidget = new QWidget(Login);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(250, 300, 230, 21));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(250, 180, 47, 20));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(250, 260, 230, 21));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(490, 220, 120, 21));
        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(300, 180, 180, 20));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(250, 220, 47, 20));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(490, 180, 100, 20));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(300, 220, 180, 20));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(620, 220, 100, 20));
        Login->setCentralWidget(centralwidget);

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QMainWindow *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "Login", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Login", "\320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217", nullptr));
        label->setText(QCoreApplication::translate("Login", "\320\233\320\276\320\263\320\270\320\275:", nullptr));
        pushButton->setText(QCoreApplication::translate("Login", "\320\222\321\205\320\276\320\264", nullptr));
        pushButton_5->setText(QCoreApplication::translate("Login", "\320\277\320\276\320\272\320\260\320\267\320\260\321\202\321\214 \320\277\320\260\321\200\320\276\320\273\321\214 (icon)", nullptr));
        label_2->setText(QCoreApplication::translate("Login", "\320\237\320\260\321\200\320\276\320\273\321\214:", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Login", "\320\276\321\207\320\270\321\201\321\202\320\270\321\202\321\214 (icon)", nullptr));
        pushButton_4->setText(QCoreApplication::translate("Login", "\320\276\321\207\320\270\321\201\321\202\320\270\321\202\321\214 (icon)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
