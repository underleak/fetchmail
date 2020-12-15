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
#include <QtGui/QIcon>
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
    QLabel *label_3;

    void setupUi(QMainWindow *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QString::fromUtf8("Login"));
        Login->resize(738, 501);
        centralwidget = new QWidget(Login);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        signUp = new QPushButton(centralwidget);
        signUp->setObjectName(QString::fromUtf8("signUp"));
        signUp->setGeometry(QRect(299, 300, 181, 31));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(240, 180, 47, 20));
        signIn = new QPushButton(centralwidget);
        signIn->setObjectName(QString::fromUtf8("signIn"));
        signIn->setGeometry(QRect(299, 260, 181, 31));
        showPassword = new QPushButton(centralwidget);
        showPassword->setObjectName(QString::fromUtf8("showPassword"));
        showPassword->setGeometry(QRect(490, 220, 41, 26));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/main/eye.png"), QSize(), QIcon::Selected, QIcon::On);
        showPassword->setIcon(icon);
        textLogin = new QLineEdit(centralwidget);
        textLogin->setObjectName(QString::fromUtf8("textLogin"));
        textLogin->setGeometry(QRect(300, 180, 180, 20));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(236, 220, 61, 20));
        clear = new QPushButton(centralwidget);
        clear->setObjectName(QString::fromUtf8("clear"));
        clear->setGeometry(QRect(370, 340, 40, 40));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icon/main/trash.png"), QSize(), QIcon::Selected, QIcon::On);
        clear->setIcon(icon1);
        clear->setIconSize(QSize(17, 17));
        textPassword = new QLineEdit(centralwidget);
        textPassword->setObjectName(QString::fromUtf8("textPassword"));
        textPassword->setGeometry(QRect(300, 220, 180, 20));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(320, 30, 131, 131));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/icon/main/envelope_icon.png")));
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
        showPassword->setText(QString());
        label_2->setText(QCoreApplication::translate("Login", "\320\237\320\260\321\200\320\276\320\273\321\214:", nullptr));
        clear->setText(QString());
        label_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
