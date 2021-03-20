#include "entity.h"

Entity::~Entity()
{
 ~QGraphicsPixmapItem();
}

Entity::Entity(QString image, int x, int y)
{
    setX(x*PIXELS);
    setY(y*PIXELS);
    QPixmap qp(image);
    setPixmap(qp);
}
