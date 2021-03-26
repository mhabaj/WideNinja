#include "entity.h"

Entity::Entity(int x, int y)
{
    setX(x*PIXELS);
    setY(y*PIXELS);
}
