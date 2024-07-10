#ifndef Plants_h
#define Plants_h

/* Forward Declarations
 */
namespace sf
{
    class Sprite;
}
class Animation;
class Pea;

class Plant
{
protected:
    Animation* animation;
    int x;
    int y;
    int health;
    int damage;

public:
    Plant();
    Plant(Animation* animation, int x, int y, int health, int damage);
    virtual bool animate() = 0;
    virtual void takeDamage(float damage) = 0;
    bool isAlive();
};

class Peashooter : public Plant
{
protected:
    Pea* peasShot;
    int deltaTime;
    int interval;

public:
    Peashooter(Animation* animation, int x, int y, int health, int damage, int interval);
    bool animate() override;
    void takeDamage(float damage) override;
    Pea* shoot();
};

#endif