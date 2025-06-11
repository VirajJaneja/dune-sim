#include <cmath>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics/Image.hpp>
#include <iostream>
using namespace std;


void drawScreen(sf::RenderWindow &window); //draws the entirety of the sprites onto the creen
void initGraphics(); //initializes the screen on startup
void setGridPixel(int i, int x, int y, int w, int h, sf::Color color); //used for setting pixel on texture;
void setGridPixel(vector<uint8_t> customPixels, int x, int y, sf::Color color); //overloaded ^

const static int WIDTH = 1000;
const static int HEIGHT = 700;
const static int GWIDTH = 850;
const static int GHEIGHT = 660;
const static int GX = 20;
const static int GY = 20;

sf::Texture bgtexture(sf::Vector2u{WIDTH, HEIGHT});
sf::Sprite bgSprite(bgtexture);


//registries
    //background, game window,
vector<vector<uint8_t>> static pixels; //pixels array
vector<sf::Texture> static textures; //texture array
vector<sf::Sprite> static sprites;


int main() {
    sf::RenderWindow static window(sf::VideoMode({WIDTH, HEIGHT}), "Dune Sim", sf::Style::Close);

    initGraphics();
    drawScreen(window);

    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);
    while (window.isOpen()) {
        drawScreen(window);
        while (const optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }
        window.display();
    }
}

//DRAWS SPRITES ONTO SCREEN
void drawScreen(sf::RenderWindow &window) {
    window.clear();
    for (int i = 0; i<sprites.size(); i++) {
        window.draw(sprites[i]); //loops thru and draws sprites
    }
}

//===== BASE COLOR SET IN WINDOW FUNCTION =====
void setGridPixel(int i, int x, int y, int w, int h, sf::Color color) {
    int val = ((w*(y))+(x))*4;
    pixels[i][val] = color.r;
    pixels[i][val+1] = color.g;
    pixels[i][val+2] = color.b;
    pixels[i][val+3] = color.a;
}

void setGridPixel(vector<uint8_t> customPixels, int x, int y, sf::Color color) { //overloaded for custom pixelset
    int val = ((WIDTH*(y))+(x))*4;
    customPixels[val] = color.r;
    customPixels[val+1] = color.g;
    customPixels[val+2] = color.b;
    customPixels[val+3] = color.a;
}

//====UPDATE SPRITE/TEXTURE=======
void updateTS(int i) {
    textures[i].update(pixels[i].data()); //basically adds pixel data to each texture
    sprites[i].setTexture(textures[i]);
}

void setSpriteLocation(sf::Sprite &sprite, int x, int y) {
    sprite.setPosition(sf::Vector2f(x, y));
}

//====STARTUP FUNCTIONS===
void initGraphics() {
    //initializing each of the graphic components

    //initializing textures
    textures.emplace_back(sf::Vector2u{WIDTH, HEIGHT}); //bg
    textures.emplace_back(sf::Vector2u{GWIDTH, GHEIGHT}); //game_screen

    //initializing pixels
    pixels.emplace_back(WIDTH * HEIGHT * 4);
    pixels.emplace_back(GWIDTH * GHEIGHT * 4);

    //connecting pixels to textures, and also inits sprites
    for (int i = 0; i<textures.size(); i++) {
        textures[i].update(pixels[i].data()); //basically adds pixel data to each texture
        sprites.emplace_back(textures[i]);
    }

    //sets sprite locations
    setSpriteLocation(sprites[1], GX, GY);

    //fills windowviewer


    //fills gameviewer
    // sf::Color sand_options[6] = {sf::Color(202,160,106), sf::Color(134,99,65), sf::Color(71,56,45), sf::Color(187,168,143), sf::Color(122,96,72), sf::Color(146,127,104)};
    int min[3] = {143,127,105};
    int max[3] = {185,166,141};
    int difference[3];
    for (int i = 0; i<3;i++) {
        difference[i] = max[i] - min[i];
    }

    for (int i = 0; i<GWIDTH; i++) {
        for (int j = 0; j<GHEIGHT; j++) {
            setGridPixel(1, i, j, GWIDTH, GHEIGHT, sf::Color((min[0] + rand() % difference[0]), (min[1] + rand() % difference[1]), (min[2] + rand() % difference[2])));
        }
    }
    updateTS(1);
}