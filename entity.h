#ifndef ENTITY_H
#define ENTITY_H

#include <QGraphicsPixmapItem>

#include <QDebug>

class Entity: public QGraphicsPixmapItem
{
public:
    const int PIXELS = 32;
    const int SIZE = 20;

    int ENTITY = 66000;
    int MOVABLEENTITY = 66001;
    int LIVINGENTITY = 66002;
    int BLOCKENTITY = 66003;
    int PLAYERENTITY = 66004;
    int WARPENTITY = 66005;

    int type() const override
    {
        return ENTITY;
    }
};

#endif // ENTITY_H
