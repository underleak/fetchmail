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
    QPushButton *signUp;
    QLabel *label;
    QPushButton *signIn;
    QPushButton *showPassword;
    QLineEdit *textLogin;
    QLabel *label_2;
    QPushButton *clear;
    QLineEdit *textPassword;

    void setupUi(QMainWindow *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QString::fromUtf8("Login"));
        Login->resize(800, 500);
        centralwidget = new QWidget(Login);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        signUp = new QPushButton(centralwidget);
        signUp->setObjectName(QString::fromUtf8("signUp"));
        signUp->setGeometry(QRect(250, 300, 230, 31));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(250, 180, 47, 20));
        signIn = new QPushButton(centralwidget);
        signIn->setObjectName(QString::fromUtf8("signIn"));
        signIn->setGeometry(QRect(250, 260, 230, 31));
        showPassword = new QPushButton(centralwidget);
        showPassword->setObjectName(QString::fromUtf8("showPassword"));
        showPassword->setGeometry(QRect(490, 220, 151, 21));
        textLogin = new QLineEdit(centralwidget);
        textLogin->setObjectName(QString::fromUtf8("textLogin"));
        textLogin->setGeometry(QRect(300, 180, 180, 20));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(250, 220, 47, 20));
        clear = new QPushButton(centralwidget);
        clear->setObjectName(QString::fromUtf8("clear"));
        clear->setGeometry(QRect(290, 340, 141, 31));
        textPassword = new QLineEdit(centralwidget);
        textPassword->setObjectName(QString::fromUtf8("textPassword"));
        textPassword->setGeometry(QRect(300, 220, 180, 20));
        Login->setCentralWidget(centralwidget);

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QMainWindow *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "Login", nullptr));
        signUp->setText(QCoreApplication::translate("Login", "\320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217", nullptr));
        label->setText(QCoreApplication::translate("Login", "\320\233\320\276\320\263\320\270\320\275:", nullptr));
        signIn->setText(QCoreApplication::translate("Login", "\320\222\321\205\320\276\320\264", nullptr));
        showPassword->setText(QCoreApplication::translate("Login", "\320\277\320\276\320\272\320\260\320\267\320\260\321\202\321\214 \320\277\320\260\321\200\320\276\320\273\321\214 (icon)", nullptr));
        label_2->setText(QCoreApplication::translate("Login", "\320\237\320\260\321\200\320\276\320\273\321\214:", nullptr));
        clear->setText(QCoreApplication::translate("Login", "\320\276\321\207\320\270\321\201\321\202\320\270\321\202\321\214 (icon)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
