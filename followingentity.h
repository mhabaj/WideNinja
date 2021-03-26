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
    QPixmap *upPix, *downPix, *rightPix, *leftPix;
    int dx;
    int dy;

private slots:
    void behaviour();

public:
    FollowingEntity(int x, int y, double speed, int maxHealth, MainController *value);
    ~FollowingEntity();

    void follow();
    std::pair<int, int> findNext();

    void moveTowardsPlayer();
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
