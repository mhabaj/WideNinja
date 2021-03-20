#include <QApplication>

#include "maincontroller.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainController *mc = new MainController();
    return a.exec();
}
