#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QList>
#include <QObject>
#include "filemanager.h"
#include "playerinventory.h"

class MainController: public QObject
{
    Q_OBJECT

private:
    QGraphicsScene *scene;
    QGraphicsView *view;
    PlayerInventory *inventory;
    FileManager* fm;
    int currentLevel;
    int startX, startY;


public:
    void loadMap(QList<QList<QString>> map, int dx, int dy);
    void loadMap(int id, int dx, int dy);
    const int PIXELS = 32;
    const int SIZE = 20;

    MainController();

    PlayerInventory *getInventory() const;
    void setInventory(PlayerInventory *value);
    int getCurrentLevel() const;
    int getStartX() const;
    int getStartY() const;
};

#endif // MAINCONTROLLER_H
