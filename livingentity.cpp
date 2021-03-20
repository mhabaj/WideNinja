#include "livingentity.h"

LivingEntity::LivingEntity(QString image, int x, int y, double speed, int maxHealth):
    MovableEntity(image,x, y, speed)
{
    setMaxHealth(maxHealth);
    setHealth(maxHealth);
}

LivingEntity::~LivingEntity()
{

}

int LivingEntity::getHealth() const
{
    return health;
}

void LivingEntity::setHealth(int value)
{
    health = value;
}

int LivingEntity::getMaxHealth() const
{
    return maxHealth;
}

void LivingEntity::setMaxHealth(int value)
{
    maxHealth = value;
}
