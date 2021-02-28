#include <QPixmap>

#include "blockentity.h"
#include "warpentity.h"
#include "pathmonsterentity.h"
#include "playerentity.h"
#include "pickableentity.h"

#include "maincontroller.h"

MainController::MainController():
    QObject()
{
    scene = new QGraphicsScene(0,0,640,640);

    view = new QGraphicsView();
    view->setScene(scene);
    view->show();

    loadMap(1, 10, 18);
    currentLevel = 1;
    inventory = new PlayerInventory();
}

void MainController::loadMap(QList<QList<QString>> map, int dx, int dy){
    startX = dx;
    startY = dy;

    scene->clear();

    scene->addItem(new PlayerEntity(":/Character/NinjaRight", dx, dy, 3, 3, this));

    QListIterator<QList<QString>> iterator(map);

    scene->setBackgroundBrush(QImage(iterator.next()[0]));

    while(iterator.hasNext()){
        QList<QString> infos = iterator.next();

        if(infos[0] == "BLOCKENTITY"){
            scene->addItem(new BlockEntity(infos[1], infos[2].toInt(), infos[3].toInt()));
        }
        else if(infos[0] == "WARPENTITY"){
            scene->addItem(new WarpEntity(infos[1], infos[2].toInt(), infos[3].toInt(), infos[4].toInt(),  infos[5].toInt(), infos[6].toInt()));
        }
        else if(infos[0] == "PATHMONSTERENTITY"){
            scene->addItem(new PathMonsterEntity(infos[1], infos[2].toInt(), infos[3].toInt(), infos[4].toDouble(),  infos[5].toInt(), infos[6]));
        }
        else if(infos[0] == "PICKABLEENTITY"){
            scene->addItem(new PickableEntity(infos[1], infos[2].toInt(), infos[3].toInt(), infos[4]));
        }
    }

    view->viewport()->update();
}

void MainController::loadMap(int id, int dx, int dy){
    currentLevel = id;

    if(id == 0){
        QList<QList<QString>> map;

        map.append({":/Background/ForestFloor"});

        map.append({"WARPENTITY", ":/Terrain/Warp", "19", "14", "1", "1", "14"});
        map.append({"WARPENTITY", ":/Terrain/Warp", "19", "15", "1", "1", "15"});

        for(int i = 0; i < 20; i++){
            map.append({"BLOCKENTITY", ":/Terrain/Tree", "0", QString::number(i)});
        }
        for(int i = 1; i < 19; i++){
            map.append({"BLOCKENTITY", ":/Terrain/Tree", QString::number(i), "0"});
            map.append({"BLOCKENTITY", ":/Terrain/Tree", QString::number(i), "19"});
        }
        for(int i = 0; i < 20; i++){
            if(i != 14 && i != 15)
                map.append({"BLOCKENTITY", ":/Terrain/Tree", "19", QString::number(i)});
        }

        map.append({"PICKABLEENTITY", ":/Item/Key", "5", "5","keyForest"});

        loadMap(map, dx, dy);
    }
    if(id == 1){
        QList<QList<QString>> map;

        map.append({":/Background/ForestFloor"});

        map.append({"WARPENTITY", ":/Terrain/Warp", "0", "14", "0", "18", "14"});
        map.append({"WARPENTITY", ":/Terrain/Warp", "0", "15", "0", "18", "15"});
        map.append({"WARPENTITY", ":/Terrain/Warp", "19", "4", "2", "1", "4"});
        map.append({"WARPENTITY", ":/Terrain/Warp", "19", "5", "2", "1", "5"});

        for(int i = 0; i < 20; i++){
            if(i != 14 && i != 15)
                map.append({"BLOCKENTITY", ":/Terrain/Tree", "0", QString::number(i)});
        }
        for(int i = 1; i < 19; i++){
            map.append({"BLOCKENTITY", ":/Terrain/Tree", QString::number(i), "0"});
            if(i != 9 && i != 10)
                map.append({"BLOCKENTITY", ":/Terrain/Tree", QString::number(i), "19"});
        }
        for(int i = 0; i < 20; i++){
            if(i != 4 && i != 5)
                map.append({"BLOCKENTITY", ":/Terrain/Tree", "19", QString::number(i)});
        }

        for(int i = 11; i < 19; i++){
            map.append({"BLOCKENTITY", ":/Terrain/Tree", QString::number(i), "17"});
            map.append({"BLOCKENTITY", ":/Terrain/Tree", QString::number(i), "18"});
        }

        for(int i = 1; i < 9; i++){
            map.append({"BLOCKENTITY", ":/Terrain/Tree", QString::number(i), "16"});
            map.append({"BLOCKENTITY", ":/Terrain/Tree", QString::number(i), "17"});
            map.append({"BLOCKENTITY", ":/Terrain/Tree", QString::number(i), "18"});
        }

        for(int i = 11; i < 17; i++){
            map.append({"BLOCKENTITY", ":/Terrain/Tree", QString::number(i), "12"});
            map.append({"BLOCKENTITY", ":/Terrain/Tree", QString::number(i), "13"});
            map.append({"BLOCKENTITY", ":/Terrain/Tree", QString::number(i), "14"});
        }

        for(int i = 3; i < 9; i++){
            map.append({"BLOCKENTITY", ":/Terrain/Tree", QString::number(i), "10"});
            map.append({"BLOCKENTITY", ":/Terrain/Tree", QString::number(i), "11"});
            map.append({"BLOCKENTITY", ":/Terrain/Tree", QString::number(i), "12"});
            map.append({"BLOCKENTITY", ":/Terrain/Tree", QString::number(i), "13"});
            map.append({"BLOCKENTITY", ":/Terrain/Tree", QString::number(i), "14"});
            map.append({"BLOCKENTITY", ":/Terrain/Tree", QString::number(i), "15"});
        }

        for(int i = 3; i < 6; i++){
            if(i != 3 && i != 4) {
                map.append({"BLOCKENTITY", ":/Terrain/Tree", QString::number(i), "3"});
                map.append({"BLOCKENTITY", ":/Terrain/Tree", QString::number(i), "4"});
            }
            map.append({"BLOCKENTITY", ":/Terrain/Tree", QString::number(i), "5"});
            if(i != 4 && i != 5){
                map.append({"BLOCKENTITY", ":/Terrain/Tree", QString::number(i), "6"});
                map.append({"BLOCKENTITY", ":/Terrain/Tree", QString::number(i), "7"});
            }
        }

        for(int i = 8; i < 17; i++){
            map.append({"BLOCKENTITY", ":/Terrain/Tree", QString::number(i), "3"});
            map.append({"BLOCKENTITY", ":/Terrain/Tree", QString::number(i), "4"});
            map.append({"BLOCKENTITY", ":/Terrain/Tree", QString::number(i), "5"});
            map.append({"BLOCKENTITY", ":/Terrain/Tree", QString::number(i), "6"});
            map.append({"BLOCKENTITY", ":/Terrain/Tree", QString::number(i), "7"});
            map.append({"BLOCKENTITY", ":/Terrain/Tree", QString::number(i), "8"});
            map.append({"BLOCKENTITY", ":/Terrain/Tree", QString::number(i), "9"});
        }

        map.append({"PATHMONSTERENTITY", ":/Character/Wolf", "9", "10", "4", "1", "R:9:D:6:L:9:U:6"});
        map.append({"PATHMONSTERENTITY", ":/Character/Wolf", "17", "15", "4.5", "1", "L:7:U:4:R:7:D:4"});

        map.append({"PATHMONSTERENTITY", ":/Character/Wolf", "1", "1", "5", "1", "D:8:R:6:U:8:L:6"});
        map.append({"PATHMONSTERENTITY", ":/Character/Wolf", "6", "8", "5.5", "1", "L:4:U:6:R:4:D:6"});

        loadMap(map, dx, dy);
    }
    if(id == 2){
        QList<QList<QString>> map;

        map.append({":/Background/ForestFloor"});

        map.append({"WARPENTITY", ":/Terrain/Warp", "0", "4", "1", "18", "4"});
        map.append({"WARPENTITY", ":/Terrain/Warp", "0", "5", "1", "18", "5"});

        for(int i = 0; i < 20; i++){
            if(i != 4 && i != 5)
                map.append({"BLOCKENTITY", ":/Terrain/Tree", "0", QString::number(i)});
        }
        for(int i = 1; i < 19; i++){
            map.append({"BLOCKENTITY", ":/Terrain/Tree", QString::number(i), "0"});
            map.append({"BLOCKENTITY", ":/Terrain/Tree", QString::number(i), "19"});
        }
        for(int i = 0; i < 20; i++){
            map.append({"BLOCKENTITY", ":/Terrain/Tree", "19", QString::number(i)});
        }

        loadMap(map, dx, dy);
    }
}

int MainController::getCurrentLevel() const
{
    return currentLevel;
}


PlayerInventory *MainController::getInventory() const
{
    return inventory;
}

void MainController::setInventory(PlayerInventory *value)
{
    inventory = value;
}

int MainController::getStartX() const
{
    return startX;
}

int MainController::getStartY() const
{
    return startY;
}






