#include <QPixmap>

#include "blockentity.h"
#include "warpentity.h"
#include "pathmonsterentity.h"
#include "playerentity.h"
#include "pickableentity.h"
#include "samouraiwatcher.h"
#include "gateentity.h"


#include "maincontroller.h"

MainController::MainController():
    QObject()
{
    scene = new QGraphicsScene(0,0,640,640);

    view = new QGraphicsView();
    fm = new FileManager();
    view->setScene(scene);
    view->show();

    loadMap(1, 10, 18);
    inventory = new PlayerInventory();
}

FileManager *MainController::getFm() const
{
    return fm;
}

QGraphicsView *MainController::getView() const
{
    return view;
}

QGraphicsScene *MainController::getScene() const
{
    return scene;
}

void MainController::loadMap(QList<QList<QString>> map, int dx, int dy)
{
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
        else if(infos[0] == "SAMOURAIWATCHER"){
            scene->addItem(new SamouraiWatcher(infos[1], infos[2].toInt(), infos[3].toInt(), infos[4].toDouble(),  infos[5].toInt(), infos[6].toInt(), this));
        }
        else if(infos[0] == "PICKABLEENTITY"){
            scene->addItem(new PickableEntity(infos[1], infos[2].toInt(), infos[3].toInt(), infos[4]));
        }
        else if(infos[0] == "GATEENTITY"){
            scene->addItem(new GateEntity(infos[1], infos[2].toInt(), infos[3].toInt(), infos[4].toInt(), infos[5].toInt(), infos[6].toInt(), infos[7]));
        }
    }

    view->viewport()->update();
}

void MainController::loadMap(int id, int dx, int dy){
    currentLevel = id;

    QList<QList<QString>> map;

    map= fm->loadDefaultMap(currentLevel);
    loadMap(map, dx, dy);

    int** cm = getCollisionMap();

    for (int h = 0; h < 20; h++)
    {
        QString a = "";

        for (int w = 0; w < 20; w++)
        {
              a += QString::number(cm[h][w]);
        }

        qDebug() << a;
    }
}

int ** MainController::getCollisionMap(){

    int** collisionMap = 0;
    collisionMap = new int*[20];

    for (int h = 0; h < 20; h++)
    {
        collisionMap[h] = new int[20];

        for (int w = 0; w < 20; w++)
        {
              collisionMap[h][w] = 0;
        }
    }

    QListIterator<QGraphicsItem *> ite(scene->items());

    while(ite.hasNext()){
        QGraphicsItem *item = ite.next();

        if(item->type() == 66003 || item->type() == 66006 || item->type() == 66008){
            int x = item->x()/PIXELS;
            int y = item->y()/PIXELS;

            collisionMap[y][x] = 1;
        }
    }

    return collisionMap;
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

