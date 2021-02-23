#ifndef MOVABLEENTITY_H
#define MOVABLEENTITY_H

#include "entity.h"

class MovableEntity: public Entity
{
private:
    float speed;
    bool diag;

public:
    MovableEntity(double speed);
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    double getSpeed() const;
    void setSpeed(double value);
    bool getDiag() const;
    void setDiag(bool value);

    int type() const override
    {
        return MOVABLEENTITY;
    }
};

#endif // MOVABLEENTITY_H
