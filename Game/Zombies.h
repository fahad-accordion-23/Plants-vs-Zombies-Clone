#ifndef Zombies_h
#define Zombies_h

/* Forward Declarations
 */
class Animation;
class Plant;

class Zombie
{
protected:
    Animation* animations;
    float x;
    float y;
    float step;
    float deltaTime;
    int health;
    int damage;
    int currentAnimation;
    char state;

public:
    Zombie(Animation* animations, float x, float y, float step);
    virtual void move() = 0;
    virtual bool animate() = 0;
    virtual void attack(Plant* plant) = 0;
    virtual void takeDamage(float damage) = 0;
};

class NormalZombie : public Zombie
{
public:
    NormalZombie(Animation* animations, float x, float y, float step);
    void move() override;
    bool animate() override;
    void attack(Plant* plant) override;
    void takeDamage(float damage) override;
};

#endif
