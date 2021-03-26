#include "warpentity.h"

WarpEntity::WarpEntity(QString image, int x, int y, int ind, int dx, int dy)
    :Entity(x, y)
{
    setId(ind);
    setDx(dx);
    setDy(dy);

    pix = new QPixmap(image);
    setPixmap(*pix);
}

int WarpEntity::getDx() const
{
    return dx;
}

void WarpEntity::setDx(int value)
{
    dx = value;
}

int WarpEntity::getDy() const
{
    return dy;
}

void WarpEntity::setDy(int value)
{
    dy = value;
}

int WarpEntity::getId() const
{
    return id;
}

void WarpEntity::setId(int value)
{
    id = value;
}

WarpEntity::~WarpEntity()
{
    delete pix;
}
