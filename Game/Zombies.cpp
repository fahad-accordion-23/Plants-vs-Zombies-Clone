#include "Zombies.h"
#include "Animation.h"

Zombie::Zombie()
    : animations(nullptr), x(0), y(0), step(0), health(0), damage(0), currentAnimation(0), state(0)
{
}

Zombie::Zombie(Animation* animations, float x, float y, float step, int health, int damage)
    : animations(animations), x(x), y(y), step(step), health(health), damage(damage), currentAnimation(0), state('W')
{
}

NormalZombie::NormalZombie(Animation* animations, float x, float y, float step, int health, int damage)
    : Zombie(animations, x, y, step, health, damage)
{
}

void NormalZombie::move()
{
    x += step;
    currentAnimation = 0;
    state = 'W';
}

bool NormalZombie::animate()
{
    return animations[currentAnimation].animate(x, y);
}

void NormalZombie::attack(Plant* plant)
{
    // TO-DO IMPLEMENT ATTACK
    state = 'A';
    currentAnimation = 1;
}

void NormalZombie::takeDamage(float damage)
{
    health -= damage;

    if (health <= 0)
    {
        if (state = 'W')                // Ideally different death animations for when killed attacking and when killed walking
            currentAnimation = 3;
        else if (state = 'A')
            currentAnimation = 3;
    }
}
