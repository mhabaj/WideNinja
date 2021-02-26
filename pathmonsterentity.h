#ifndef PATHMONSTERENTITY_H
#define PATHMONSTERENTITY_H

#include "livingentity.h"
#include <QSequentialAnimationGroup>

class PathMonsterEntity: public QObject, public LivingEntity
{
    Q_OBJECT
    Q_PROPERTY(int x READ x WRITE setX)
    Q_PROPERTY(int y READ y WRITE setY)
private:
    QSequentialAnimationGroup *group;
public:
    PathMonsterEntity(QString image, int x, int y, double speed, int maxHealth, QString path);
    ~PathMonsterEntity();

    int type() const override
    {
        return PATHMONSTERENTITY;
    }
};

#endif // PATHMONSTERENTITY_H
