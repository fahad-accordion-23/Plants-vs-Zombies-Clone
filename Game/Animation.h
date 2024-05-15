#ifndef Animation_h
#define Animation_H

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

public:
    Animation(sf::RenderWindow* window, sf::Sprite* spritesheet, int noOfSprites, int width, int height, bool ends);
    bool animate(float x, float y);
};

#endif
