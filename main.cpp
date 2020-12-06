#include "login.h"
#include <QApplication>
#include <stdlib.h>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication application(argc, argv);
    QFile file("style.qss");
    file.open(QFile::ReadOnly);
    application.setStyleSheet(file.readAll());
    Login login;
    login.show();
    return application.exec();
}
