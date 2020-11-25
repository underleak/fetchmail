#include "login.h"
#include "messages.h"
#include <QApplication>
#include <stdlib.h>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Login w;
    w.show();
    return a.exec();
}
