#include "pickableentity.h"

PickableEntity::PickableEntity(QString image, int x, int y, QString key)
    : Entity(x, y)
{
    pix = new QPixmap(image);
    setPixmap(*pix);
    setKey(key);
}

QString PickableEntity::getKey() const
{
    return key;
}

void PickableEntity::setKey(QString newKey)
{
    this->key = newKey;
}

bool PickableEntity::getPicked() const
{
    return picked;
}

void PickableEntity::setPicked(bool value)
{
    picked = value;
}

PickableEntity::~PickableEntity()
{
    delete pix;
}

