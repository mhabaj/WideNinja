#include "entity.h"

Entity::Entity(QString image, int x, int y)
{
    setX(x*PIXELS);
    setY(y*PIXELS);
    setPixmap(*new QPixmap(image));
}
