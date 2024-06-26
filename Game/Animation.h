#ifndef Animation_h
#define Animation_h

/* Forward Declarations
 */
namespace sf
{
    class RenderWindow;
    class Sprite;
}

/* Animation Class:
 * This class will be used by the concrete zombie classes for animations.
 */
class Animation
{
private:
    sf::RenderWindow* window;
    sf::Sprite* spritesheet;
    int noOfSprites;
    int width;
    int height;
    int deltaTime;
    bool ends;
    float multiplier;

public:
    Animation();
    Animation(sf::RenderWindow* window, sf::Sprite* spritesheet, int noOfSprites, int width, int height, bool ends, float multiplier = 1);
    bool animate(float x, float y);
};

#endif
