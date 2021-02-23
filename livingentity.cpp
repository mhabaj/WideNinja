#include "livingentity.h"

LivingEntity::LivingEntity(double speed, int maxHealth):
    MovableEntity(speed)
{
    setMaxHealth(maxHealth);
    setHealth(maxHealth);
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
