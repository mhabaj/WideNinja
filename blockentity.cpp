#include "blockentity.h"

BlockEntity::BlockEntity(QString image, int x, int y)
    :Entity(x, y)
{
    pix = new QPixmap(image);
    setPixmap(*pix);
}

BlockEntity::~BlockEntity()
{
    delete pix;
}
