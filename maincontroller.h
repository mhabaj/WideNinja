#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QList>
#include <QObject>
#include "filemanager.h"
#include "playerinventory.h"
class FileManager;
class MainController: public QObject
{
    Q_OBJECT

private:
    QString appWorkingDirectory;
    QGraphicsScene *scene;
    QGraphicsView *view;
    PlayerInventory *inventory;
    FileManager* fm;
    int currentLevel;
    int startX, startY;
    const int maxMapCount = 3;

public:
    void loadMap(QList<QList<QString>> map, int dx, int dy);
    void loadMap(int id, int dx, int dy);
    const int PIXELS = 32;
    const int SIZE = 20;

    MainController(QString workingDirectory);

    PlayerInventory *getInventory() const;
    void setInventory(PlayerInventory *value);
    int ** getCollisionMap();
    int * getPlayerCoords();
    int getCurrentLevel() const;
    int getStartX() const;
    int getStartY() const;

    QGraphicsScene *getScene() const;
    QGraphicsView *getView() const;
    FileManager *getFm() const;
    QString getWorkingDirectory() const;
    void setWorkingDirectory(const QString &value);
};

#endif // MAINCONTROLLER_H
