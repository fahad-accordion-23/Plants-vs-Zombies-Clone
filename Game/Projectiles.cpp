#include "Projectiles.h"
#include "Animation.h"
#include "Zombies.h"

Pea::Pea()
    : animation(nullptr), x(0), y(0), step(0), damage(0)
{
}

Pea::Pea(Animation* animation, float x, float y, float step, int damage)
    : animation(animation), x(x), y(y), step(step), damage(damage)
{
}

void Pea::move()
{
    x += step;
}

void Pea::animate()
{
    animation->animate(x, y);
}

bool Pea::attack(Zombie* zombie)
{
    zombie->takeDamage(damage);
    return zombie->isAlive();
}
