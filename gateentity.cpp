#include "gateentity.h"



QString GateEntity::getKey() const
{
    return key;
}

void GateEntity::setKey(const QString &value)
{
    key = value;
}

GateEntity::GateEntity(QString image, int x, int y, int id, int dx, int dy, QString key)
    :WarpEntity( image,  x,  y,  id,  dx,  dy)
{
    setOpened(false);
    setKey(key);
}

bool GateEntity::getOpened() const
{
    return opened;
}

void GateEntity::setOpened(bool value)
{
    opened = value;
}
