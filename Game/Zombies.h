#ifndef Zombies_h
#define Zombies_h

/* Forward Declarations
 */
class Animation;

class Zombie
{
protected:
    Animation** animations;
    float health;
    float step;
    int state;

public:
    virtual void move() = 0;
    virtual void die() = 0;
    virtual bool takeDamage(float damage) = 0;
    virtual void animate() = 0;
};

#endif
