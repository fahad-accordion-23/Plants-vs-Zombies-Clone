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
    int row;
    int col;
    int health;
    int damage;

public:
    Plant();
    Plant(Animation* animation, int row, int col, int health, int damage);
    virtual bool animate() = 0;
    virtual void takeDamage(float damage) = 0;
};

class Peashooter : public Plant
{
public:
    Peashooter(Animation* animation, int row, int col, int health, int damage);
    bool animate() override;
    void takeDamage(float damage) override;
    Pea* shoot();
};

#endif