#include <SFML/Graphics.hpp>
#include <ctime>

using namespace sf;
using namespace std;

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
    //Create a window, n*n
    RenderWindow window(VideoMode(1200, 700), "Plants Vs Zombies");
    window.setFramerateLimit(60);

    //Game icon
    Image icon;
    if (!icon.loadFromFile("./../assets/Inventory-GameScreen/icon.jpg"))
    {
        return 1;
    }
    window.setIcon(32, 32, icon.getPixelsPtr());

    ///////////////////////////////////////

    //Game field (5*9)
    //Point 137*79 - leftmost point
    //length 41; width 53
    const int ROWS = 5;
    const int COLS = 9;

    bool FIELD_GAME_STATUS[ROWS][COLS];

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            FIELD_GAME_STATUS[i][j] = true;
        }
    }

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

        window.setSize(sf::Vector2u(550, 340));
        window.display();
    }
    return 0;
}