#include "Animation.h"
#include <SFML/Graphics.hpp>

Animation::Animation()
    : window(nullptr), spritesheet(nullptr), noOfSprites(0), width(0), height(0), deltaTime(0), ends(false)
{
}

Animation::Animation(sf::RenderWindow* window, sf::Sprite* spritesheet, int noOfSprites, int width, int height, bool ends)
    : window(window), spritesheet(spritesheet), noOfSprites(noOfSprites), width(width), height(height), deltaTime(0), ends(ends)
{

}

bool Animation::animate(float x, float y)
{
    // Stepping the animation on function call
    spritesheet->setTextureRect(sf::IntRect(deltaTime * width, 0, width, height));
    spritesheet->setPosition(x, y);
    window->draw(*spritesheet);

    deltaTime += 1;
    deltaTime %= noOfSprites;

    // Checking the animation ending condition
    if (noOfSprites == deltaTime + 1)
        return ends;

    return false;
}
