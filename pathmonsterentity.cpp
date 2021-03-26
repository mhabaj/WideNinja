#include "pathmonsterentity.h"

#include <QPropertyAnimation>

PathMonsterEntity::PathMonsterEntity(int x, int y, double speed, int maxHealth, QString path):
    LivingEntity(x, y, speed, maxHealth)
{
    upPix = new QPixmap(":/Character/WolfUp");
    downPix = new QPixmap(":/Character/WolfDown");
    leftPix = new QPixmap(":/Character/WolfLeft");
    rightPix = new QPixmap(":/Character/WolfRight");

    group = new QSequentialAnimationGroup();

    int tempX = x*PIXELS;
    int tempY = y*PIXELS;

    int firstDir = -1;

    QListIterator<QString> iterator(path.split(":"));

    while(iterator.hasNext()){
        QString direction = iterator.next();

        int distance = iterator.next().toInt();

        if(direction == "U"){
            QPropertyAnimation *animation = new QPropertyAnimation(this, "y");
            animation->setDuration((1000/speed)*distance);
            animation->setEndValue(tempY-distance*PIXELS);
            if(group->animationCount() == 0){
                firstDir = U;
                setPixmap(*upPix);
            }
            else
                QObject::connect(group->animationAt(group->animationCount()-1), SIGNAL(finished()), this, SLOT(up()));
            group->addAnimation(animation);
            tempY -= distance*PIXELS;
        }
        else if(direction == "D"){
            QPropertyAnimation *animation = new QPropertyAnimation(this, "y");
            animation->setDuration((1000/speed)*distance);
            animation->setEndValue(tempY+distance*PIXELS);
            if(group->animationCount() == 0){
                firstDir = D;
                setPixmap(*downPix);
            }
            else
                QObject::connect(group->animationAt(group->animationCount()-1), SIGNAL(finished()), this, SLOT(down()));
            group->addAnimation(animation);
            tempY += distance*PIXELS;
        }
        else if(direction == "L"){
            QPropertyAnimation *animation = new QPropertyAnimation(this, "x");
            animation->setDuration((1000/speed)*distance);
            animation->setEndValue(tempX-distance*PIXELS);
            if(group->animationCount() == 0){
                firstDir = L;
                setPixmap(*leftPix);
            }
            else
                QObject::connect(group->animationAt(group->animationCount()-1), SIGNAL(finished()), this, SLOT(left()));
            group->addAnimation(animation);
            tempX -= distance*PIXELS;
        }
        else if(direction == "R"){
            QPropertyAnimation *animation = new QPropertyAnimation(this, "x");
            animation->setDuration((1000/speed)*distance);
            animation->setEndValue(tempX+distance*PIXELS);
            if(group->animationCount() == 0){
                firstDir = R;
                setPixmap(*rightPix);
            }
            else
                QObject::connect(group->animationAt(group->animationCount()-1), SIGNAL(finished()), this, SLOT(right()));
            group->addAnimation(animation);
            tempX += distance*PIXELS;
        }
    }

    if(firstDir == U)
        QObject::connect(group->animationAt(group->animationCount()-1), SIGNAL(finished()), this, SLOT(up()));
    else if(firstDir == D)
        QObject::connect(group->animationAt(group->animationCount()-1), SIGNAL(finished()), this, SLOT(down()));
    else if(firstDir == L)
        QObject::connect(group->animationAt(group->animationCount()-1), SIGNAL(finished()), this, SLOT(left()));
    else if(firstDir == R)
        QObject::connect(group->animationAt(group->animationCount()-1), SIGNAL(finished()), this, SLOT(right()));

    group->setLoopCount(-1);
    group->start();
}

void PathMonsterEntity::up(){
    setPixmap(*upPix);
}

void PathMonsterEntity::down(){
    setPixmap(*downPix);
}

void PathMonsterEntity::left(){
    setPixmap(*leftPix);
}

void PathMonsterEntity::right(){
    setPixmap(*rightPix);
}

PathMonsterEntity::~PathMonsterEntity(){
    delete upPix;
    delete downPix;
    delete leftPix;
    delete rightPix;

    group->stop();
    delete group;
}
