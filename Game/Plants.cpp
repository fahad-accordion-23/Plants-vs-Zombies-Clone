#include "Plants.h"
#include "Animation.h"
#include "Projectiles.h"

Plant::Plant()
    : animation(nullptr), x(0), y(0), health(0), damage(0)
{
}

Plant::Plant(Animation* animation, int x, int y, int health, int damage)
    : animation(animation), x(x), y(y), health(0), damage(damage)
{
}

bool Plant::isAlive()
{
    return health > 0;
}

Peashooter::Peashooter(Animation* animation, int x, int y, int health, int damage, int interval)
    : Plant(animation, x, y, health, damage), interval(interval)
{
}

bool Peashooter::animate()
{
    return animation->animate(x, y);
}

void Peashooter::takeDamage(float damage) 
{
    health -= damage;
}

Pea* Peashooter::shoot()
{
    return nullptr;
}
