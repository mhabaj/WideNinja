#include <QPixmap>
#include "blockentity.h"
#include "warpentity.h"
#include <QFile>
#include "maincontroller.h"

MainController::MainController():
    QObject()
{
    loadMap();


    scene = new QGraphicsScene(0,0,640,640);

    view = new QGraphicsView();
    view->setScene(scene);
    view->show();
    loadMapSlot(0);


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

        col++;
        if(col == SIZE){
            col = 0;
            row++;
        }
    }

    view->viewport()->update();
}

void MainController::closing()
{
    saveMap();
}

QGraphicsView *MainController::getView() const
{
    return view;
}

void MainController::setView(QGraphicsView *value)
{
    view = value;
}

void MainController::saveMap()
{

    QFile file(":/Map/lvlA");
    file.open(QIODevice::WriteOnly);
    QDataStream out(&file);
    out << map;
    qDebug() << map;

    qDebug()<<"SAVE DE LA MAP:----------------------------------------------------------------------------------\n";
}

void MainController::loadMap()
{

    QFile file(":/Map/lvlA");
    file.open(QIODevice::ReadOnly);
    QDataStream in(&file);    // read the data serialized from the file
    in >> map;           // extract "the answer is" and 42
    qDebug() << map;
    qDebug()<<"LOAD MAP------------------------------------------------------------------------------------------------\n";


}

QList<QList<QList<QString> > > MainController::getMap() const
{
    return map;
}

void MainController::setMap(const QList<QList<QList<QString> > > &value)
{
    map = value;
}
