#include <QApplication>
#include <QDebug>
#include "maincontroller.h"
#include "filemanager.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QString path = a.applicationDirPath();
    MainController *mc = new MainController(path);
    return a.exec();
}
