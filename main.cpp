#include "login.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication application(argc, argv);
    Login login;
    login.show();
    return application.exec();
}
