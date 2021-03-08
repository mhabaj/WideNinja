#include <QApplication>

#include "maincontroller.h"
#include "filemanager.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainController *mc = new MainController();

//    FileManager *fm = new FileManager();

//    QList<QList<QString>> map = fm->loadDefaultMap(2);

//    map.push_back({"BLOCKENTITY", ":/Terrain/Tree", "13", "5"});
//    map.push_back({"BLOCKENTITY", ":/Terrain/Tree", "13", "6"});
//    map.push_back({"BLOCKENTITY", ":/Terrain/Tree", "13", "7"});
//    map.push_back({"BLOCKENTITY", ":/Terrain/Tree", "13", "8"});
//    map.push_back({"BLOCKENTITY", ":/Terrain/Tree", "13", "9"});
//    map.push_back({"FOLLOWINGENTITY", ":/Character/SamouraiDown", "4", "4", "3", "1", "2"});

//    QListIterator<QList<QString>> ite(map);

//    while(ite.hasNext()){
//        QList<QString> info = ite.next();
//        if(info[0] == "FOLLOWINGENTITY" ){
//            map.removeOne(info);
//            map.push_back({"FOLLOWINGENTITY", ":/Character/SamouraiDown", "4", "4", "3", "1", "2"});
//        }
//    }

//    fm->saveDefaultMap(map, 2);

    return a.exec();
}
