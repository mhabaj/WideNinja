#include "warpentity.h"

WarpEntity::WarpEntity(int ind)
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
