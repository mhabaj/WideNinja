#ifndef MAP_H
#define MAP_H

#include "entity.h"
class Map
{
private:
    const int SIZE = 20;
    QList<Entity *> entities;
    QString background;
public:
    Map(QString bg);
    Map();
    QList<Entity *> getEntities();
    void setEntities(QList<Entity *> &value);
    Entity* getEntity(int ind) ;
    void setEntity(Entity *e);
    QString getBackground() ;
    void setBackground(QString &value);

};

#endif // MAP_H
