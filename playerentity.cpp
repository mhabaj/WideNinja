#include "playerentity.h"

#include <QKeyEvent>
#include <QObject>
#include "blockentity.h"
#include "warpentity.h"
#include "pickableentity.h"
#include "gateentity.h"

PlayerEntity::PlayerEntity(int x, int y, double speed, int maxHealth, MainController *value):
    LivingEntity(x, y, speed, maxHealth)
{
    upPix = new QPixmap(":/Character/NinjaUp");
    downPix = new QPixmap(":/Character/NinjaDown");
    leftPix = new QPixmap(":/Character/NinjaLeft");
    rightPix = new QPixmap(":/Character/NinjaRight");
    deathPix = new QPixmap(":/Character/NinjaDead");

    if(x == 18)
        setPixmap(*leftPix);
    else if(x == 1)
        setPixmap(*rightPix);
    else if(y == 18)
        setPixmap(*upPix);
    else if(y == 1)
        setPixmap(*downPix);

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
    collisionTimer->start(100);
}

void PlayerEntity::keyPressEvent(QKeyEvent *event){
    if(!event->isAutoRepeat() && !isDead){
        if(event->key() == Qt::Key_Left)
        {
            if(!moveLTimer->isActive() && !moveRTimer->isActive()){
                if(moveUTimer->isActive() || moveDTimer->isActive())
                    setDiag(true);
                moveLTimer->start(10);
                setPixmap(*leftPix);
            }
        }
        else if(event->key() == Qt::Key_Right)
        {
            if(!moveRTimer->isActive() && !moveLTimer->isActive()){
                if(moveUTimer->isActive() || moveDTimer->isActive())
                    setDiag(true);
                moveRTimer->start(10);
                setPixmap(*rightPix);
            }
        }
        else if(event->key() == Qt::Key_Up)
        {
            if(!moveUTimer->isActive() && !moveDTimer->isActive()){
                if(moveRTimer->isActive() || moveLTimer->isActive())
                    setDiag(true);
                moveUTimer->start(10);
                setPixmap(*upPix);
            }
        }
        else if(event->key() == Qt::Key_Down)
        {
            if(!moveDTimer->isActive() && !moveUTimer->isActive()){
                if(moveRTimer->isActive() || moveLTimer->isActive())
                    setDiag(true);
                moveDTimer->start(10);
                setPixmap(*downPix);
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
void PlayerEntity::collisionSlot()
{
    collision(0);
}

void PlayerEntity::collision(int direction){
    QListIterator<QGraphicsItem *> collidings(collidingItems());

    while(collidings.hasNext())
    {
        QGraphicsItem *item = collidings.next();

        if(item->type() == BLOCKENTITY){
            if(direction == L) moveRightSlot();
            else if(direction == R) moveLeftSlot();
            else if(direction == U) moveDownSlot();
            else if(direction == D) moveUpSlot();
        }

        else if(item->type() == PATHMONSTERENTITY || item->type() == FOLLOWINGENTITY){
            isDead = true;

            if(moveLTimer->isActive()) moveLTimer->stop();
            if(moveRTimer->isActive()) moveRTimer->stop();
            if(moveUTimer->isActive()) moveUTimer->stop();
            if(moveDTimer->isActive()) moveDTimer->stop();

            setPixmap(*deathPix);

            QTimer::singleShot(1500, this, SLOT(deathSlot()));
        }

        else if(item->type() == WARPENTITY)
        {
            mc->getInventory()->pushTemp();
            mc->getInventory()->clearTemp();
            mc->loadMap(((WarpEntity *)item)->getId(), ((WarpEntity *)item)->getDx(), ((WarpEntity *)item)->getDy());
        }

        else if(item->type() == PICKABLEENTITY)
        {
            mc->getInventory()->addTempValue(((PickableEntity *)item)->getKey());
            delete item;
        }
        else if(item->type() == GATEENTITY)
        {
            if(mc->getInventory()->getValuePickable(((GateEntity *)item)->getKey()) >= 1)
            {
                ((GateEntity *)item)->setOpened(true);
                mc->loadMap(((GateEntity *)item)->getId(), ((GateEntity *)item)->getDx(), ((GateEntity *)item)->getDy());
            }
            else
            {
                if(direction == L) moveRightSlot();
                else if(direction == R) moveLeftSlot();
                else if(direction == U) moveDownSlot();
                else if(direction == D) moveUpSlot();
            }
        }
    }
}

void PlayerEntity::moveUpSlot(){
    if(y() > 0){
        if(diag)
            setPos(x(), y() - getSpeed()/2);
        else
            setPos(x(), y() - getSpeed());
        collision(U);
    }
}

void PlayerEntity::moveDownSlot(){
    if(y() < 608){
        if(diag)
            setPos(x(), y() + getSpeed()/2);
        else
            setPos(x(), y() + getSpeed());
        collision(D);
    }
}

void PlayerEntity::moveLeftSlot(){
    if(x() > 0){
        if(diag)
            setPos(x() - getSpeed()/2, y());
        else
            setPos(x() - getSpeed(), y());
        collision(L);
    }
}

void PlayerEntity::moveRightSlot(){
    if(x() < 608){
        if(diag)
            setPos(x() + getSpeed()/2, y());
        else
            setPos(x() + getSpeed(), y());
        collision(R);
    }
}

void PlayerEntity::deathSlot(){
    mc->getInventory()->clearTemp();
    mc->loadMap(mc->getCurrentLevel(), mc->getStartX(), mc->getStartY());
}

bool PlayerEntity::getDiag() const
{
    return diag;
}

void PlayerEntity::setDiag(bool value)
{
    diag = value;
}

MainController *PlayerEntity::getMc() const
{
    return mc;
}

void PlayerEntity::setMc(MainController *value)
{
    mc = value;
}

PlayerEntity::~PlayerEntity()
{
    delete upPix;
    delete downPix;
    delete rightPix;
    delete leftPix;
    delete deathPix;

    delete moveUTimer;
    delete moveDTimer;
    delete moveLTimer;
    delete moveRTimer;
}
