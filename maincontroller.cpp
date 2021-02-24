#include <QPixmap>
#include "blockentity.h"
#include "warpentity.h"
#include "pathmonsterentity.h"

#include "maincontroller.h"

MainController::MainController(QList<QList<QList<QString>>> map):
    QObject()
{
    setMap(map);

    scene = new QGraphicsScene(0,0,640,640);

    view = new QGraphicsView();
    view->setScene(scene);
    view->show();
}

void MainController::loadMapSlot(int id){
    scene->clear();

    QListIterator<QList<QString>> iterator(map[id]);

    scene->setBackgroundBrush(QImage(iterator.next()[0]));

    int col = 0;
    int row = 0;

    while(iterator.hasNext()){

        QList<QString> object = iterator.next();

        if(object[0] == "wall"){
            BlockEntity *wall = new BlockEntity();
            wall->setPixmap(object[1]);
            wall->setX(col*PIXELS);
            wall->setY(row*PIXELS);
            scene->addItem(wall);
        }
        else if(object[0] == "player"){
            PlayerEntity *player = new PlayerEntity(3, 3);
            QObject::connect(player, SIGNAL(loadMapSignal(int)), this, SLOT(loadMapSlot(int)));
            player->setFlag(QGraphicsItem::ItemIsFocusable);
            player->setFocus();
            player->setPixmap(*new QPixmap(":/Character/NinjaDown"));
            player->setX(col*PIXELS);
            player->setY(row*PIXELS);
            scene->addItem(player);
        }
        else if(object[0] == "warp"){
            WarpEntity *warp = new WarpEntity(object[1].toInt());
            warp->setPixmap(object[2]);
            warp->setX(col*PIXELS);
            warp->setY(row*PIXELS);
            scene->addItem(warp);
        }
        else if(object[0] == "pathMonster"){
            PathMonsterEntity *pm = new PathMonsterEntity(object[2].toInt(), object[3].toInt());
            pm->setPixmap(object[1]);
            pm->setX(col*PIXELS);
            pm->setY(row*PIXELS);
            pm->setPath(object[4]);
            scene->addItem(pm);
            pm->start();
        }

        col++;
        if(col == SIZE){
            col = 0;
            row++;
        }
    }

    view->viewport()->update();
}

QList<QList<QList<QString> > > MainController::getMap() const
{
    return map;
}

void MainController::setMap(const QList<QList<QList<QString> > > &value)
{
    map = value;
}
