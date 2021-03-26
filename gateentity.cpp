#include "gateentity.h"

QString GateEntity::getKey() const
{
    return key;
}

void GateEntity::setKey(const QString &value)
{
    key = value;
}

GateEntity::GateEntity(QString imageClosed, int x, int y, int id, int dx, int dy, QString imageOpened, QString key, bool oppened)
    :WarpEntity(imageClosed,  x,  y,  id,  dx,  dy)
{
    openPix = new QPixmap(imageOpened);

    setOpened(oppened);
    setKey(key);
}

bool GateEntity::getOpened() const
{
    return opened;
}

void GateEntity::setOpened(bool value)
{
    opened = value;
    if(value)
        setPixmap(*openPix);
}
