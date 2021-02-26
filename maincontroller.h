#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QList>
#include <QObject>
#include "playerinventory.h"

#include "map.h"

class MainController: public QObject
{
    Q_OBJECT

private:
    QGraphicsScene *scene;
    QGraphicsView *view;
    PlayerInventory *inventory;

public:
    void loadMap(Map *map);
    void loadMap(int id);
    const int PIXELS = 32;
    const int SIZE = 20;

    MainController();

    PlayerInventory *getInventory() const;
    void setInventory(PlayerInventory *value);
};

#endif // MAINCONTROLLER_H
