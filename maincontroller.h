#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QList>
#include <QObject>

#include "map.h"

class MainController: public QObject
{
    Q_OBJECT

private:
    QGraphicsScene *scene;
    QGraphicsView *view;
public:
    void loadMap(Map *map);
    void loadMap(int id);
    const int PIXELS = 32;
    const int SIZE = 20;

    MainController();
};

#endif // MAINCONTROLLER_H
