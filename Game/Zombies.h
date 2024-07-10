#ifndef Zombies_h
#define Zombies_h

/* Forward Declarations
 */
class Animation;
class Plant;

/* Abstract Zombie Class
 */
class Zombie
{
protected:
    Animation* animations;
    float x;
    float y;
    float step;
    int health;
    int damage;
    int currentAnimation;
    char state;

public:
    Zombie();
    Zombie(Animation* animations, float x, float y, float step, int health, int damage);
    virtual void move() = 0;
    virtual bool animate() = 0;
    virtual void attack(Plant* plant) = 0;
    virtual void takeDamage(int damage) = 0;
    virtual bool isAlive() = 0;
};

class NormalZombie : public Zombie
{
public:
    NormalZombie(Animation* animations, float x, float y, float step, int health, int damage);
    void move() override;
    bool animate() override;
    void attack(Plant* plant) override;
    void takeDamage(int damage) override;
    bool isAlive() override;
};

#endif
