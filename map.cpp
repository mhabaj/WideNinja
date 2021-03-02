#include "map.h"

Map::Map(QString bg)
{
    setBackground(bg);
}

QList<Entity *> Map::getEntities()
{
    return entities;
}

void Map::setEntities(QList<Entity *> &value)
{
    entities = value;
}

Entity* Map::getEntity(int ind)
{
    return entities[ind];
}

void Map::setEntity(Entity *e)
{
    entities.append(e);
}

QString Map::getBackground()
{
    return background;
}

void Map::setBackground(QString &value)
{
    background = value;
}
