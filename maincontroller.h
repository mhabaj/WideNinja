#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QList>
#include <QObject>

#include "playerentity.h"
#include "map.h"

class MainController: public QObject
{
    Q_OBJECT

public slots:
    void loadMapSlot(Map *map);

private:
    QGraphicsScene *scene;
    QGraphicsView *view;
public:
    const int PIXELS = 32;
    const int SIZE = 20;

    MainController();
};

#endif // MAINCONTROLLER_H
