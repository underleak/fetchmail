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
    QLabel *label;
    QLineEdit *textLogin;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *textPassword;
    QPushButton *clear;

    void setupUi(QWidget *Registration)
    {
        if (Registration->objectName().isEmpty())
            Registration->setObjectName(QString::fromUtf8("Registration"));
        Registration->resize(800, 500);
        showPassword = new QPushButton(Registration);
        showPassword->setObjectName(QString::fromUtf8("showPassword"));
        showPassword->setGeometry(QRect(500, 190, 120, 21));
        back = new QPushButton(Registration);
        back->setObjectName(QString::fromUtf8("back"));
        back->setGeometry(QRect(330, 380, 140, 30));
        signUp = new QPushButton(Registration);
        signUp->setObjectName(QString::fromUtf8("signUp"));
        signUp->setGeometry(QRect(300, 230, 191, 22));
        label = new QLabel(Registration);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 800, 30));
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
        clear->setGeometry(QRect(330, 256, 138, 31));

        retranslateUi(Registration);

        QMetaObject::connectSlotsByName(Registration);
    } // setupUi

    void retranslateUi(QWidget *Registration)
    {
        Registration->setWindowTitle(QCoreApplication::translate("Registration", "Form", nullptr));
        showPassword->setText(QCoreApplication::translate("Registration", "\320\277\320\276\320\272\320\260\320\267\320\260\321\202\321\214 \320\277\320\260\321\200\320\276\320\273\321\214 (icon)", nullptr));
        back->setText(QCoreApplication::translate("Registration", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        signUp->setText(QCoreApplication::translate("Registration", "\320\227\320\260\321\200\320\265\320\263\320\265\321\201\321\202\321\200\320\270\321\200\320\276\320\262\320\260\321\202\321\214\321\201\321\217", nullptr));
#if QT_CONFIG(tooltip)
        label->setToolTip(QCoreApplication::translate("Registration", "<html><head/><body><p align=\"center\"><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        label->setText(QCoreApplication::translate("Registration", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt;\">\320\237\320\276\320\266\320\260\320\273\321\203\320\271\321\201\321\202\320\260 \320\262\320\262\320\265\320\264\320\270\321\202\320\265 \320\264\320\260\320\275\320\275\321\213\320\265 \321\215\320\273\320\265\320\272\321\202\321\200\320\276\320\275\320\275\320\276\320\271 \320\277\320\276\321\207\321\202\321\213:</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("Registration", "\320\233\320\276\320\263\320\270\320\275:", nullptr));
        label_3->setText(QCoreApplication::translate("Registration", "\320\237\320\260\321\200\320\276\320\273\321\214:", nullptr));
        clear->setText(QCoreApplication::translate("Registration", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214 ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Registration: public Ui_Registration {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTRATION_H
