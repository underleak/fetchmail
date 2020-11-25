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
    QPushButton *pushButton_5;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QPushButton *pushButton_4;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton_3;

    void setupUi(QWidget *Registration)
    {
        if (Registration->objectName().isEmpty())
            Registration->setObjectName(QString::fromUtf8("Registration"));
        Registration->resize(800, 500);
        pushButton_5 = new QPushButton(Registration);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(500, 190, 120, 21));
        pushButton = new QPushButton(Registration);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(330, 380, 140, 30));
        pushButton_2 = new QPushButton(Registration);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(330, 240, 140, 30));
        label = new QLabel(Registration);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 800, 30));
        lineEdit = new QLineEdit(Registration);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(310, 190, 180, 20));
        label_2 = new QLabel(Registration);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(260, 150, 47, 20));
        pushButton_4 = new QPushButton(Registration);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(630, 190, 100, 20));
        label_3 = new QLabel(Registration);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(260, 190, 47, 20));
        lineEdit_2 = new QLineEdit(Registration);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(310, 150, 180, 20));
        pushButton_3 = new QPushButton(Registration);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(500, 150, 100, 20));

        retranslateUi(Registration);

        QMetaObject::connectSlotsByName(Registration);
    } // setupUi

    void retranslateUi(QWidget *Registration)
    {
        Registration->setWindowTitle(QCoreApplication::translate("Registration", "Form", nullptr));
        pushButton_5->setText(QCoreApplication::translate("Registration", "\320\277\320\276\320\272\320\260\320\267\320\260\321\202\321\214 \320\277\320\260\321\200\320\276\320\273\321\214 (icon)", nullptr));
        pushButton->setText(QCoreApplication::translate("Registration", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Registration", "\320\227\320\260\321\200\320\265\320\263\320\265\321\201\321\202\321\200\320\270\321\200\320\276\320\262\320\260\321\202\321\214\321\201\321\217", nullptr));
#if QT_CONFIG(tooltip)
        label->setToolTip(QCoreApplication::translate("Registration", "<html><head/><body><p align=\"center\"><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        label->setText(QCoreApplication::translate("Registration", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt;\">\320\237\320\276\320\266\320\260\320\273\321\203\320\271\321\201\321\202\320\260 \320\262\320\262\320\265\320\264\320\270\321\202\320\265 \320\264\320\260\320\275\320\275\321\213\320\265 \321\215\320\273\320\265\320\272\321\202\321\200\320\276\320\275\320\275\320\276\320\271 \320\277\320\276\321\207\321\202\321\213:</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("Registration", "\320\233\320\276\320\263\320\270\320\275:", nullptr));
        pushButton_4->setText(QCoreApplication::translate("Registration", "\320\276\321\207\320\270\321\201\321\202\320\270\321\202\321\214 (icon)", nullptr));
        label_3->setText(QCoreApplication::translate("Registration", "\320\237\320\260\321\200\320\276\320\273\321\214:", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Registration", "\320\276\321\207\320\270\321\201\321\202\320\270\321\202\321\214 (icon)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Registration: public Ui_Registration {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTRATION_H
