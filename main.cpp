#include <QApplication>
#include <QFile>
#include "maincontroller.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);



    MainController *mc = new MainController();


    QObject::connect(&a, SIGNAL(aboutToQuit()), mc, SLOT(closing()));


    //mc->saveMap();
    return a.exec();
}
