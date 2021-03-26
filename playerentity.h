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
    QPixmap *upPix, *downPix, *leftPix, *rightPix, *deathPix;
    QTimer *moveUTimer;
    QTimer *moveDTimer;
    QTimer *moveLTimer;
    QTimer *moveRTimer;
    QTimer *collisionTimer;

    MainController *mc;

    bool isDead;
    bool diag;

public slots:
    void moveUpSlot();
    void moveDownSlot();
    void moveLeftSlot();
    void moveRightSlot();
    void collisionSlot();
    void deathSlot();

public:
    PlayerEntity(int x, int y, double speed, int maxHealth, MainController *value);
    ~PlayerEntity();
    void collision(int direction);
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;

    MainController *getMc() const;
    void setMc(MainController *value);
    bool getIsDead() const;
    void setIsDead(bool value);
    bool getDiag() const;
    void setDiag(bool value);

    int type() const override
    {
        return PLAYERENTITY;
    }
};

#endif // PLAYERENTITY_H
