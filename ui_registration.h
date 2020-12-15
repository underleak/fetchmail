/********************************************************************************
** Form generated from reading UI file 'registration.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTRATION_H
#define UI_REGISTRATION_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Registration
{
public:
    QPushButton *showPassword;
    QPushButton *back;
    QPushButton *signUp;
    QLineEdit *textLogin;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *textPassword;
    QPushButton *clear;
    QLabel *label_4;

    void setupUi(QWidget *Registration)
    {
        if (Registration->objectName().isEmpty())
            Registration->setObjectName(QString::fromUtf8("Registration"));
        Registration->resize(800, 500);
        showPassword = new QPushButton(Registration);
        showPassword->setObjectName(QString::fromUtf8("showPassword"));
        showPassword->setGeometry(QRect(500, 180, 41, 31));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/main/eye.png"), QSize(), QIcon::Selected, QIcon::On);
        showPassword->setIcon(icon);
        back = new QPushButton(Registration);
        back->setObjectName(QString::fromUtf8("back"));
        back->setGeometry(QRect(340, 380, 140, 30));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icon/main/back.png"), QSize(), QIcon::Selected, QIcon::Off);
        back->setIcon(icon1);
        signUp = new QPushButton(Registration);
        signUp->setObjectName(QString::fromUtf8("signUp"));
        signUp->setGeometry(QRect(320, 230, 171, 22));
        textLogin = new QLineEdit(Registration);
        textLogin->setObjectName(QString::fromUtf8("textLogin"));
        textLogin->setGeometry(QRect(310, 150, 180, 20));
        label_2 = new QLabel(Registration);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(260, 150, 47, 20));
        label_3 = new QLabel(Registration);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(260, 190, 47, 20));
        textPassword = new QLineEdit(Registration);
        textPassword->setObjectName(QString::fromUtf8("textPassword"));
        textPassword->setGeometry(QRect(310, 190, 180, 20));
        clear = new QPushButton(Registration);
        clear->setObjectName(QString::fromUtf8("clear"));
        clear->setGeometry(QRect(390, 260, 41, 41));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icon/main/trash.png"), QSize(), QIcon::Selected, QIcon::On);
        clear->setIcon(icon2);
        label_4 = new QLabel(Registration);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(340, 10, 131, 131));
        label_4->setPixmap(QPixmap(QString::fromUtf8(":/icon/main/envelope_icon.png")));

        retranslateUi(Registration);

        QMetaObject::connectSlotsByName(Registration);
    } // setupUi

    void retranslateUi(QWidget *Registration)
    {
        Registration->setWindowTitle(QCoreApplication::translate("Registration", "Form", nullptr));
        showPassword->setText(QString());
        back->setText(QCoreApplication::translate("Registration", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        signUp->setText(QCoreApplication::translate("Registration", "\320\227\320\260\321\200\320\265\320\263\320\265\321\201\321\202\321\200\320\270\321\200\320\276\320\262\320\260\321\202\321\214\321\201\321\217", nullptr));
        label_2->setText(QCoreApplication::translate("Registration", "\320\233\320\276\320\263\320\270\320\275:", nullptr));
        label_3->setText(QCoreApplication::translate("Registration", "\320\237\320\260\321\200\320\276\320\273\321\214:", nullptr));
        clear->setText(QString());
        label_4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Registration: public Ui_Registration {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTRATION_H
