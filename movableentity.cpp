#include "movableentity.h"

MovableEntity::MovableEntity(QString image, int x, int y, double speed)
    :Entity(image, x, y)
{
    setSpeed(speed);
    diag = false;
}

bool MovableEntity::getDiag() const
{
    return diag;
}

void MovableEntity::setDiag(bool value)
{
    diag = value;
}

void MovableEntity::moveUp(){
    if(diag)
        setPos(x(), y() - speed/2);
    else
        setPos(x(), y() - speed);

}

void MovableEntity::moveDown(){
    if(diag)
        setPos(x(), y() + speed/2);
    else
        setPos(x(), y() + speed);
}

void MovableEntity::moveLeft(){
    if(diag)
        setPos(x() - speed/2, y());
    else
        setPos(x() - speed, y());
}

void MovableEntity::moveRight(){
    if(diag)
        setPos(x() + speed/2, y());
    else
        setPos(x() + speed, y());
}

double MovableEntity::getSpeed() const
{
    return speed;
}

void MovableEntity::setSpeed(double value)
{
    speed = value;
}
