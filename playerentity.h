#ifndef PLAYERENTITY_H
#define PLAYERENTITY_H

#include <QTimer>
#include <QObject>

#include "livingentity.h"
#include "maincontroller.h"

class PlayerEntity: public QObject, public LivingEntity
{
    Q_OBJECT

private:
    QTimer *moveUTimer;
    QTimer *moveDTimer;
    QTimer *moveLTimer;
    QTimer *moveRTimer;
    QTimer *collisionTimer;

    MainController *mc;

    bool isDead;

public slots:
    void moveUpSlot();
    void moveDownSlot();
    void moveLeftSlot();
    void moveRightSlot();
    void collisionSlot();
    void deathSlot();

public:
    PlayerEntity(QString image, int x, int y, double speed, int maxHealth, MainController *value);
    void collision(int direction);
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;

    int type() const override
    {
        return PLAYERENTITY;
    }
    MainController *getMc() const;
    void setMc(MainController *value);
    bool getIsDead() const;
    void setIsDead(bool value);
};

#endif // PLAYERENTITY_H
