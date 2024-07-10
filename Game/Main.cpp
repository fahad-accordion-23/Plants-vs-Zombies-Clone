#include <SFML/Graphics.hpp>
#include "Zombies.h"
#include "Plants.h"
#include "Projectiles.h"
#include "Animation.h"
#include <ctime>

using namespace sf;
using namespace std;

// GAME PROPERTIES
#define WIDTH 1200
#define HEIGHT 600
const int MULTIPLIER = 1;
const int FPS = 15;
const int COLS = 9;
const int ROWS = 5;

//Drawing the background
void createBack(RenderWindow& window) {
    //Drawing the background
    Image map_image;
    map_image.loadFromFile("./../assets/Background/bgday.jpg");
    Texture map;
    map.loadFromImage(map_image);
    Sprite s_map;
    s_map.setTexture(map);
    s_map.setPosition(0, 0);
    window.draw(s_map);
}

int main()
{
    // Creating a window
    RenderWindow window(VideoMode(WIDTH, HEIGHT), "Plants Vs Zombies");
    window.setFramerateLimit(FPS);

    //Game icon
    Image icon;
    if (!icon.loadFromFile("./../assets/Inventory-GameScreen/icon.jpg"))
    {
        return 1;
    }
    window.setIcon(32, 32, icon.getPixelsPtr());

    // Creating a zombie
    Texture normalZombieWalk;
    normalZombieWalk.loadFromFile("./../assets/spritesheets/nZombWalk.png");
    Sprite nZombWalk;
    nZombWalk.setTexture(normalZombieWalk);

    Texture wZDie;
    wZDie.loadFromFile("./../assets/spritesheets/nZombDie.png");
    Sprite walkZombieDie;
    walkZombieDie.setTexture(wZDie);

    Animation* animations = new Animation[4];
    animations[0] = Animation(&window, &nZombWalk, 22, 166, 144, false);
    animations[3] = Animation(&window, &walkZombieDie, 10, 166, 144, true, 0.5);
    Zombie* myZombie = new NormalZombie(animations, 970 - 166, 0, -1 * MULTIPLIER, 100, 100);


    // Creating a pea
    Texture normalPea;
    normalPea.loadFromFile("./../assets/Bullets/PeaNormal/pea.png");
    Sprite normalPeaSprite;
    normalPeaSprite.setTexture(normalPea);
    Animation* animation = new Animation(&window, &normalPeaSprite, 1, 28, 28, false);
    Pea* myPea = new Pea(animation, 500, 500, -10 * MULTIPLIER, 4);

    while (window.isOpen())
    {
         Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        //Create a background
        createBack(window);

        if (myZombie->isAlive())
            myZombie->move();
        myZombie->animate();

        myPea->move();
        myPea->attack(myZombie);
        myPea->animate();

        window.display();
    }

    return 0;
}