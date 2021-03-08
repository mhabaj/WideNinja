#ifndef FOLLOWINGENTITY_H
#define FOLLOWINGENTITY_H

#include "livingentity.h"
#include "maincontroller.h"

class FollowingEntity: public QObject, public LivingEntity
{
    Q_OBJECT
    Q_PROPERTY(int x READ x WRITE setX)
    Q_PROPERTY(int y READ y WRITE setY)

private:
    MainController *mc;
    int dx;
    int dy;

private slots:
    void move();

public:
    FollowingEntity(QString image, int x, int y, double speed, int maxHealth, MainController *value);

    void follow();
    std::pair<int, int> findNext();

    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();

    int type() const override
    {
        return FOLLOWINGENTITY;
    }

    int nextMove();
};

#endif // FOLLOWINGENTITY_H
