#include "livingentity.h"

LivingEntity::LivingEntity(int x, int y, double speed, int maxHealth):
    Entity(x, y)
{
    setSpeed(speed);
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

int LivingEntity::getSpeed() const
{
    return speed;
}

void LivingEntity::setSpeed(int value)
{
    speed = value;
}
