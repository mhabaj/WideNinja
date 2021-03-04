#include <QApplication>

#include "maincontroller.h"
#include "filemanager.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainController *mc = new MainController();

//    FileManager *fm = new FileManager();

//    QList<QList<QString>> map = fm->loadDefaultMap(0);

//    QListIterator<QList<QString>> ite(map);

//    while(ite.hasNext()){
//        QList<QString> info = ite.next();
//        if(info[0] == "SAMOURAIWATCHER" && info[2] == "9" && info[3] == "9"){
//            qDebug() << "BISMILLAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";
//            map.removeOne(info);
//            map.push_back({"SAMOURAIWATCHER", ":/Character/SamouraiRight", "9", "9", "0", "1", "2"});
//        }
//    }

//    fm->saveDefaultMap(map, 0);

    return a.exec();
}
