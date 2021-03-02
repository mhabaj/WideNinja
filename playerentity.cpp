#include "playerentity.h"

#include <QKeyEvent>
#include <QObject>
#include "blockentity.h"
#include "warpentity.h"
#include "pickableentity.h"

PlayerEntity::PlayerEntity(QString image, int x, int y, double speed, int maxHealth, MainController *value):
    LivingEntity(image, x, y, speed, maxHealth)
{
    isDead = false;

    setMc(value);

    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();

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
    if(!event->isAutoRepeat() && !isDead){
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
    if(!event->isAutoRepeat() && !isDead){
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

        else if(item->type() == PATHMONSTERENTITY){
            isDead = true;

            if(moveLTimer->isActive()) moveLTimer->stop();
            if(moveRTimer->isActive()) moveRTimer->stop();
            if(moveUTimer->isActive()) moveUTimer->stop();
            if(moveDTimer->isActive()) moveDTimer->stop();

            setPixmap(*new QPixmap(":/Character/NinjaDead"));
            QTimer::singleShot(1500, this, SLOT(deathSlot()));
        }

        else if(item->type() == WARPENTITY){
            mc->getInventory()->pushTemp();
            mc->getInventory()->clearTemp();
            mc->loadMap(((WarpEntity *)item)->getId(), ((WarpEntity *)item)->getDx(), ((WarpEntity *)item)->getDy());
        }

        else if(item->type() == PICKABLEENTITY)
        {
            mc->getInventory()->addTempValue(((PickableEntity *)item)->getKey());
            delete item;
        }
    }
}

MainController *PlayerEntity::getMc() const
{
    return mc;
}

void PlayerEntity::setMc(MainController *value)
{
    mc = value;
}

bool PlayerEntity::getIsDead() const
{
    return isDead;
}

void PlayerEntity::setIsDead(bool value)
{
    isDead = value;
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

void PlayerEntity::deathSlot(){
    mc->getInventory()->clearTemp();
    mc->loadMap(mc->getCurrentLevel(), mc->getStartX(), mc->getStartY());
}
