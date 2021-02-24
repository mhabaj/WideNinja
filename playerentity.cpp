#include "playerentity.h"

#include <QKeyEvent>
#include <QObject>
#include "blockentity.h"
#include "warpentity.h"

PlayerEntity::PlayerEntity(double speed, int maxHealth):
    LivingEntity(speed, maxHealth)
{
    setPixmap(*new QPixmap(":/Character/NinjaDown"));

    moveUTimer = new QTimer();
    QObject::connect(moveUTimer, SIGNAL(timeout()), this, SLOT(moveUpSlot()));
    moveDTimer = new QTimer();
    QObject::connect(moveDTimer, SIGNAL(timeout()), this, SLOT(moveDownSlot()));
    moveLTimer = new QTimer();
    QObject::connect(moveLTimer, SIGNAL(timeout()), this, SLOT(moveLeftSlot()));
    moveRTimer = new QTimer();
    QObject::connect(moveRTimer, SIGNAL(timeout()), this, SLOT(moveRightSlot()));

    collisionTimer = new QTimer();
    QObject::connect(collisionTimer, SIGNAL(timeout()), this, SLOT(collisionSlot()));
    collisionTimer->start(10);
}

void PlayerEntity::keyPressEvent(QKeyEvent *event){
    if(!event->isAutoRepeat()){
        if(event->key() == Qt::Key_Left)
        {
            if(!moveLTimer->isActive() && !moveRTimer->isActive()){
                if(moveUTimer->isActive() || moveDTimer->isActive())
                    setDiag(true);
                moveLTimer->start(10);
                setPixmap(*new QPixmap(":/Character/NinjaLeft"));
            }
        }
        else if(event->key() == Qt::Key_Right)
        {
            if(!moveRTimer->isActive() && !moveLTimer->isActive()){
                if(moveUTimer->isActive() || moveDTimer->isActive())
                    setDiag(true);
                moveRTimer->start(10);
                setPixmap(*new QPixmap(":/Character/NinjaRight"));
            }
        }
        else if(event->key() == Qt::Key_Up)
        {
            if(!moveUTimer->isActive() && !moveDTimer->isActive()){
                if(moveRTimer->isActive() || moveLTimer->isActive())
                    setDiag(true);
                moveUTimer->start(10);
                setPixmap(*new QPixmap(":/Character/NinjaUp"));
            }
        }
        else if(event->key() == Qt::Key_Down)
        {
            if(!moveDTimer->isActive() && !moveUTimer->isActive()){
                if(moveRTimer->isActive() || moveLTimer->isActive())
                    setDiag(true);
                moveDTimer->start(10);
                setPixmap(*new QPixmap(":/Character/NinjaDown"));
            }
        }
    }
}

void PlayerEntity::keyReleaseEvent(QKeyEvent *event){
    if(!event->isAutoRepeat()){
        if(event->key() == Qt::Key_Left)
        {
            if(moveLTimer->isActive()){
                moveLTimer->stop();
                setDiag(false);
            }
        }
        else if(event->key() == Qt::Key_Right)
        {
            if(moveRTimer->isActive()){
                moveRTimer->stop();
                setDiag(false);
            }
        }
        else if(event->key() == Qt::Key_Up)
        {
            if(moveUTimer->isActive()){
                moveUTimer->stop();
                setDiag(false);
            }
        }
        else if(event->key() == Qt::Key_Down)
        {
            if(moveDTimer->isActive()){
                moveDTimer->stop();
                setDiag(false);
            }
        }
    }
}
void PlayerEntity::collisionSlot(){
    collision(0);
}

void PlayerEntity::collision(int direction){
    QListIterator<QGraphicsItem *> collidings(collidingItems());

    while(collidings.hasNext()){
        QGraphicsItem *item = collidings.next();

        if(item->type() == BLOCKENTITY){
            if(direction == L) moveRight();
            else if(direction == R) moveLeft();
            else if(direction == U) moveDown();
            else if(direction == D) moveUp();
        }

        if(item->type() == WARPENTITY){
            emit(loadMapSignal(((WarpEntity*)item)->getId()));
        }

        if(item->type() == PATHMONSTERENTITY){
            qDebug() << "AGROUGROU ! MECHANT !!!";
        }
    }
}

void PlayerEntity::moveUpSlot(){
    moveUp();
    collision(U);
}

void PlayerEntity::moveDownSlot(){
    moveDown();
    collision(D);
}

void PlayerEntity::moveLeftSlot(){
    moveLeft();
    collision(L);
}

void PlayerEntity::moveRightSlot(){
    moveRight();
    collision(R);
}
