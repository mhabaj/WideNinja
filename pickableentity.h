#ifndef PICKABLEENTITY_H
#define PICKABLEENTITY_H

#include "entity.h"

class PickableEntity : public Entity
{
private:
    bool picked;
    QString key;
    QPixmap *pix;

public:
    PickableEntity(QString image, int x, int y, QString key);
    ~PickableEntity();

    QString getKey() const;
    void setKey(QString newKey);

    bool getPicked() const;
    void setPicked(bool value);

    int type() const override
    {
        return PICKABLEENTITY;
    }

};

#endif // PICKABLEENTITY_H
