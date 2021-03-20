#ifndef ENTITY_H
#define ENTITY_H

#include <QGraphicsPixmapItem>

#include <QDebug>

class Entity: public QGraphicsPixmapItem
{
public:
    const int PIXELS = 32;
    const int SIZE = 20;

    const int L = 1;
    const int R = 2;
    const int D = 3;
    const int U = 4;

    const int ENTITY = 66000;
    const int MOVABLEENTITY = 66001;
    const int LIVINGENTITY = 66002;
    const int BLOCKENTITY = 66003;
    const int PLAYERENTITY = 66004;
    const int WARPENTITY = 66005;
    const int PATHMONSTERENTITY = 66006;
    const int PICKABLEENTITY = 66007;
    const int SAMOURAIWATCHER = 66008;

    ~Entity();

    Entity(QString image, int x, int y);

    int type() const override
    {
        return ENTITY;
    }
};

#endif // ENTITY_H
