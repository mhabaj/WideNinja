#include "pathmonsterentity.h"

#include <QPropertyAnimation>

PathMonsterEntity::PathMonsterEntity(QString image, int x, int y, double speed, int maxHealth, QString path):
    LivingEntity(image, x, y, speed, maxHealth)
{
    group = new QSequentialAnimationGroup();

    int tempX = x*PIXELS;
    int tempY = y*PIXELS;

    QListIterator<QString> iterator(path.split(":"));

    while(iterator.hasNext()){
        QString direction = iterator.next();

        int distance = iterator.next().toInt();

        if(direction == "U"){
            QPropertyAnimation *animation = new QPropertyAnimation(this, "y");
            animation->setDuration((1000/speed)*distance);
            animation->setEndValue(tempY-distance*PIXELS);
            group->addAnimation(animation);
            tempY -= distance*PIXELS;
        }
        else if(direction == "D"){
            QPropertyAnimation *animation = new QPropertyAnimation(this, "y");
            animation->setDuration((1000/speed)*distance);
            animation->setEndValue(tempY+distance*PIXELS);
            group->addAnimation(animation);
            tempY += distance*PIXELS;
        }
        else if(direction == "L"){
            QPropertyAnimation *animation = new QPropertyAnimation(this, "x");
            animation->setDuration((1000/speed)*distance);
            animation->setEndValue(tempX-distance*PIXELS);
            group->addAnimation(animation);
            tempX -= distance*PIXELS;
        }
        else if(direction == "R"){
            QPropertyAnimation *animation = new QPropertyAnimation(this, "x");
            animation->setDuration((1000/speed)*distance);
            animation->setEndValue(tempX+distance*PIXELS);
            group->addAnimation(animation);
            tempX += distance*PIXELS;
        }
    }

    group->setLoopCount(-1);
    group->start();
}

PathMonsterEntity::~PathMonsterEntity(){
    group->stop();
    delete group;
}
