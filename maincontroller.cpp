#include <QPixmap>
#include "blockentity.h"
#include "warpentity.h"
#include "pathmonsterentity.h"
#include "playerentity.h"
#include "pickableentity.h"
#include "samouraiwatcher.h"

#include "maincontroller.h"

MainController::MainController():
    QObject()
{
    scene = new QGraphicsScene(0,0,640,640);

    view = new QGraphicsView();
    view->setScene(scene);
    view->show();

    loadMap(0, 10, 18);
    currentLevel = 0;
    inventory = new PlayerInventory();
}

void MainController::loadMap(Map *map, int dx, int dy){
    startX = dx;
    startY = dy;

    scene->clear();

    map->setEntity(new PlayerEntity(":/Character/NinjaRight", dx, dy, 3, 3, this));

    QList<Entity *> mapList = map->getEntities();

    QListIterator<Entity *> iterator(mapList);

    scene->setBackgroundBrush(QImage(map->getBackground()));

    while(iterator.hasNext()){
        scene->addItem(iterator.next());
    }

    view->viewport()->update();
}

void MainController::loadMap(int id, int dx, int dy){
    currentLevel = id;

    if(id == 0){
        Map *m = new Map(":/Background/ForestFloor");

        m->setEntity(new WarpEntity(":/Terrain/Warp", 19, 14, 1, 1, 14));
        m->setEntity(new WarpEntity(":/Terrain/Warp", 19, 15, 1, 1, 15));

        for(int i = 0; i < 20; i++){
            m->setEntity(new BlockEntity(":/Terrain/Tree", 0, i));
        }
        for(int i = 1; i < 19; i++){
            m->setEntity(new BlockEntity(":/Terrain/Tree", i, 0));
            m->setEntity(new BlockEntity(":/Terrain/Tree", i, 19));
        }
        for(int i = 0; i < 14; i++){
            m->setEntity(new BlockEntity(":/Terrain/Tree", 19, i));
        }
        m->setEntity(new BlockEntity(":/Terrain/Tree", 19, 16));
        m->setEntity(new BlockEntity(":/Terrain/Tree", 19, 17));
        m->setEntity(new BlockEntity(":/Terrain/Tree", 19, 18));
        m->setEntity(new BlockEntity(":/Terrain/Tree", 19, 19));

        m->setEntity(new PickableEntity(":/Item/Key",5,5,"keyForest"));
        m->setEntity(new SamouraiWatcher(":Character/NinjaRight", 9, 9, 0, 1, 5,this));

        loadMap(m, dx, dy);
    }
    if(id == 1){
        Map *m = new Map(":/Background/ForestFloor");

        m->setEntity(new WarpEntity(":/Terrain/Warp", 0, 14, 0, 18, 14));
        m->setEntity(new WarpEntity(":/Terrain/Warp", 0, 15, 0, 18, 15));
        m->setEntity(new WarpEntity(":/Terrain/Warp", 19, 4, 2, 1, 4));
        m->setEntity(new WarpEntity(":/Terrain/Warp", 19, 5, 2, 1, 5));

        m->setEntity(new BlockEntity(":/Terrain/Tree", 0, 16));
        m->setEntity(new BlockEntity(":/Terrain/Tree", 0, 17));
        m->setEntity(new BlockEntity(":/Terrain/Tree", 0, 18));
        m->setEntity(new BlockEntity(":/Terrain/Tree", 0, 19));
        for(int i = 0; i < 14; i++){
            m->setEntity(new BlockEntity(":/Terrain/Tree", 0, i));
        }
        for(int i = 1; i < 19; i++){
            m->setEntity(new BlockEntity(":/Terrain/Tree", i, 0));
            if(i != 9 && i != 10)
            m->setEntity(new BlockEntity(":/Terrain/Tree", i, 19));
        }
        for(int i = 6; i < 20; i++){
            m->setEntity(new BlockEntity(":/Terrain/Tree", 19, i));
        }
        m->setEntity(new BlockEntity(":/Terrain/Tree", 19, 0));
        m->setEntity(new BlockEntity(":/Terrain/Tree", 19, 1));
        m->setEntity(new BlockEntity(":/Terrain/Tree", 19, 2));
        m->setEntity(new BlockEntity(":/Terrain/Tree", 19, 3));

        for(int i = 11; i < 19; i++){
            m->setEntity(new BlockEntity(":/Terrain/Tree", i, 17));
            m->setEntity(new BlockEntity(":/Terrain/Tree", i, 18));
        }

        for(int i = 1; i < 9; i++){
            m->setEntity(new BlockEntity(":/Terrain/Tree", i, 16));
            m->setEntity(new BlockEntity(":/Terrain/Tree", i, 17));
            m->setEntity(new BlockEntity(":/Terrain/Tree", i, 18));
        }

        for(int i = 11; i < 17; i++){
            m->setEntity(new BlockEntity(":/Terrain/Tree", i, 12));
            m->setEntity(new BlockEntity(":/Terrain/Tree", i, 13));
            m->setEntity(new BlockEntity(":/Terrain/Tree", i, 14));
        }

        for(int i = 3; i < 9; i++){
            m->setEntity(new BlockEntity(":/Terrain/Tree", i, 10));
            m->setEntity(new BlockEntity(":/Terrain/Tree", i, 11));
            m->setEntity(new BlockEntity(":/Terrain/Tree", i, 12));
            m->setEntity(new BlockEntity(":/Terrain/Tree", i, 13));
            m->setEntity(new BlockEntity(":/Terrain/Tree", i, 14));
            m->setEntity(new BlockEntity(":/Terrain/Tree", i, 15));
        }

        for(int i = 3; i < 6; i++){
            if(i != 3 && i != 4) {
                m->setEntity(new BlockEntity(":/Terrain/Tree", i, 3));
                m->setEntity(new BlockEntity(":/Terrain/Tree", i, 4));
            }
            m->setEntity(new BlockEntity(":/Terrain/Tree", i, 5));
            if(i != 4 && i != 5){
                m->setEntity(new BlockEntity(":/Terrain/Tree", i, 6));
                m->setEntity(new BlockEntity(":/Terrain/Tree", i, 7));
            }
        }

        for(int i = 8; i < 17; i++){
            m->setEntity(new BlockEntity(":/Terrain/Tree", i, 3));
            m->setEntity(new BlockEntity(":/Terrain/Tree", i, 4));
            m->setEntity(new BlockEntity(":/Terrain/Tree", i, 5));
            m->setEntity(new BlockEntity(":/Terrain/Tree", i, 6));
            m->setEntity(new BlockEntity(":/Terrain/Tree", i, 7));
            m->setEntity(new BlockEntity(":/Terrain/Tree", i, 8));
            m->setEntity(new BlockEntity(":/Terrain/Tree", i, 9));
        }

        m->setEntity(new PathMonsterEntity(":/Character/Wolf", 9, 10, 4, 1, "R:9:D:6:L:9:U:6"));
        m->setEntity(new PathMonsterEntity(":/Character/Wolf", 17, 15, 4.5, 1, "L:7:U:4:R:7:D:4"));

        m->setEntity(new PathMonsterEntity(":/Character/Wolf", 1, 1, 5, 1, "D:8:R:6:U:8:L:6"));
        m->setEntity(new PathMonsterEntity(":/Character/Wolf", 6, 8, 5.5, 1, "L:4:U:6:R:4:D:6"));

        loadMap(m, dx, dy);
    }
    if(id == 2){
        Map *m = new Map(":/Background/ForestFloor");

        m->setEntity(new WarpEntity(":/Terrain/Warp", 0, 4, 1, 18, 4));
        m->setEntity(new WarpEntity(":/Terrain/Warp", 0, 5, 1, 18, 5));

        m->setEntity(new BlockEntity(":/Terrain/Tree", 0, 0));
        m->setEntity(new BlockEntity(":/Terrain/Tree", 0, 1));
        m->setEntity(new BlockEntity(":/Terrain/Tree", 0, 2));
        m->setEntity(new BlockEntity(":/Terrain/Tree", 0, 3));
        for(int i = 6; i < 20; i++){
            m->setEntity(new BlockEntity(":/Terrain/Tree", 0, i));
        }
        for(int i = 1; i < 19; i++){
            m->setEntity(new BlockEntity(":/Terrain/Tree", i, 0));
            m->setEntity(new BlockEntity(":/Terrain/Tree", i, 19));
        }
        for(int i = 0; i < 20; i++){
            m->setEntity(new BlockEntity(":/Terrain/Tree", 19, i));
        }

        loadMap(m, dx, dy);
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

QGraphicsView *MainController::getView() const
{
    return view;
}

QGraphicsScene *MainController::getScene() const
{
    return scene;
}






