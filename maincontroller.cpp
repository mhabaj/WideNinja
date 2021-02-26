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

    loadMap(0);
    inventory = new PlayerInventory();
}


void MainController::loadMap(Map *map){
    scene->clear();

    QList<Entity *> mapList = map->getEntities();

    QListIterator<Entity *> iterator(mapList);

    scene->setBackgroundBrush(QImage(map->getBackground()));

    while(iterator.hasNext()){
        scene->addItem(iterator.next());
    }

    view->viewport()->update();
}

void MainController::loadMap(int id){
    if(id == 0){
        Map *m = new Map(":/Background/ForestFloor");

        m->setEntity(new PlayerEntity(":/Character/NinjaRight", 1, 14, 3, 3, this));
        m->setEntity(new PathMonsterEntity(":/Character/Wolf", 2, 7, 1, 1, "R:4:U:4:L:2:D:2:L:2:D:2"));
        m->setEntity(new WarpEntity(":/Terrain/Warp", 0, 14, 1));
        m->setEntity(new BlockEntity(":/Terrain/Tree", 0, 0));

        loadMap(m);
    }
    if(id == 1){
        Map *m = new Map(":/Background/ForestFloor");

        m->setEntity(new PlayerEntity(":/Character/NinjaRight", 18, 14, 3, 3, this));
        m->setEntity(new WarpEntity(":/Terrain/Warp", 19, 14, 0));
        m->setEntity(new BlockEntity(":/Terrain/Tree", 0, 1));
        m->setEntity(new PickableEntity(":/Item/Key",5,5,"keyForest"));

        loadMap(m);
    }
}


PlayerInventory *MainController::getInventory() const
{
    return inventory;
}

void MainController::setInventory(PlayerInventory *value)
{
    inventory = value;
}






