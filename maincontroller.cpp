#include <QPixmap>
#include "blockentity.h"
#include "warpentity.h"
#include "pathmonsterentity.h"

#include "maincontroller.h"

MainController::MainController():
    QObject()
{
    scene = new QGraphicsScene(0,0,640,640);

    view = new QGraphicsView();
    view->setScene(scene);
    view->show();
}

void MainController::loadMapSlot(Map *map){
    scene->clear();

    QList<Entity *> mapList = map->getEntities();

    QListIterator<Entity *> iterator(mapList);

    scene->setBackgroundBrush(QImage(map->getBackground()));

    while(iterator.hasNext()){
        scene->addItem(iterator.next());
    }

    view->viewport()->update();
}
