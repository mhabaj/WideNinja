#include "warpentity.h"

WarpEntity::WarpEntity(QString image, int x, int y, int ind)
    :Entity(image, x, y)
{
    setId(ind);
}

int WarpEntity::getId() const
{
    return id;
}

void WarpEntity::setId(int value)
{
    id = value;
}
