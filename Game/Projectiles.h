#ifndef Projectiles_h
#define Projectiles_h

/* Forward Declarations
 */
class Animation;
class Zombie;

class Pea
{
private:
    Animation* animation;
    float x;
    float y;
    float step;
    int damage;

public:
    Pea();
    Pea(Animation* animation, float x, float y, float step, int damage);
    virtual int* getCoordinates();
    virtual void move();
    virtual void animate();
    virtual bool attack(Zombie* zombie);
};
#endif