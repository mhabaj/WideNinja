#include <QPixmap>

#include "blockentity.h"
#include "warpentity.h"
#include "pathmonsterentity.h"
#include "playerentity.h"
#include "pickableentity.h"
#include "samouraiwatcher.h"
#include "gateentity.h"
#include "followingentity.h"


#include "maincontroller.h"

MainController::MainController(QString workingDirectory):
    QObject()
{
    scene = new QGraphicsScene(0,0,640,640);
    appWorkingDirectory = workingDirectory;
    view = new QGraphicsView();
    fm = new FileManager(workingDirectory, 4);

    clearCollisionMap();

    collisionMapTimer = new QTimer();
    QObject::connect(collisionMapTimer, SIGNAL(timeout()), this, SLOT(generateCollisionMap()));
    collisionMapTimer->start(100);

//    QList<QList<QString>> map = fm->loadDefaultMap(3);

//    QListIterator<QList<QString>> ite(map);

//    while(ite.hasNext()){
//        QList<QString> infos = ite.next();

//        if(!infos.isEmpty()){
//            if(infos[0] == "GATEENTITY"){
//                map.removeOne(infos);
//                qDebug() << "c'est bon";
//            }
//        }
//    }

//    map.append({"GATEENTITY", ":/Terrain/DoorClosed", "9", "19", "2", "9", "1", ":/Terrain/DoorOpen", "ForestKey", "1"});

//    fm->saveDefaultMap(map, 3);

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

QString MainController::getWorkingDirectory() const
{
    return appWorkingDirectory;
}

void MainController::setWorkingDirectory(const QString &value)
{
    appWorkingDirectory = value;
}

void MainController::loadMap(QList<QList<QString>> map, int dx, int dy)
{
    startX = dx;
    startY = dy;
    
    scene->clear();
    
    scene->addItem(new PlayerEntity(dx, dy, 3, 3, this));

    QListIterator<QList<QString>> iterator(map);

    scene->setBackgroundBrush(QImage(iterator.next()[0]));

    while(iterator.hasNext()){
        QList<QString> infos = iterator.next();

        if(infos[0] == "BLOCKENTITY"){
            scene->addItem(new BlockEntity(infos[1], infos[2].toInt(), infos[3].toInt()));
        }
        else if(infos[0] == "WARPENTITY"){
            scene->addItem(new WarpEntity(infos[1], infos[2].toInt(), infos[3].toInt(), infos[4].toInt(), infos[5].toInt(), infos[6].toInt()));
        }
        else if(infos[0] == "PATHMONSTERENTITY"){
            scene->addItem(new PathMonsterEntity(infos[1].toInt(), infos[2].toInt(), infos[3].toDouble(), infos[4].toInt(), infos[5]));
        }
        else if(infos[0] == "SAMOURAIWATCHER"){
            scene->addItem(new SamouraiWatcher(infos[1].toInt(), infos[2].toInt(), infos[3].toDouble(), infos[4].toInt(), infos[5], this));
        }
        else if(infos[0] == "PICKABLEENTITY"){
            scene->addItem(new PickableEntity(infos[1], infos[2].toInt(), infos[3].toInt(), infos[4]));
        }
        else if(infos[0] == "GATEENTITY"){
            scene->addItem(new GateEntity(infos[1], infos[2].toInt(), infos[3].toInt(), infos[4].toInt(), infos[5].toInt(), infos[6].toInt(), infos[7], infos[8], infos[9].toInt()));
        }
        else if(infos[0] == "FOLLOWINGENTITY"){
            scene->addItem(new FollowingEntity(infos[1].toInt(), infos[2].toInt(), infos[3].toDouble(), infos[4].toInt(), this));
        }
    }
    generateCollisionMap();
    view->viewport()->update();
}

void MainController::loadMap(int id, int dx, int dy){
    currentLevel = id;

    QList<QList<QString>> map;

    map= fm->loadDefaultMap(currentLevel);
    loadMap(map, dx, dy);
}

void MainController::generateCollisionMap(){
    clearCollisionMap();

    QListIterator<QGraphicsItem *> ite(scene->items());

    while(ite.hasNext()){
        QGraphicsItem *item = ite.next();

        if(item->type() == 66003 || item->type() == 66006 || item->type() == 66008){
            int x = item->x()/PIXELS;
            int y = item->y()/PIXELS;

            collisionMap[x][y] = 1;
        }
    }
}

void MainController::clearCollisionMap(){
    collisionMap.clear();

    for (int loop = 0; loop < 20; loop++)
    {
        collisionMap.append({0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0});
    }
}

QList<QList<int>> MainController::getCollisionMap(){
    return collisionMap;
}

QPair<int, int> MainController::getPlayerCoords()
{
    QPair<int, int> coords;
    QListIterator<QGraphicsItem *> ite(getScene()->items());

    while(ite.hasNext()){
        QGraphicsItem *item = ite.next();

        if(item->type() == 66004)
        {
            coords.first = item->x();
            coords.second = item->y();
            break;
        }
    }

    return coords;
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

