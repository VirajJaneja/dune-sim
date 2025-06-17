#include <cmath>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics/Image.hpp>
#include <iostream>
#include <random>

#include "buttonPanel.h"
#include "GameManager.h"
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
const static int FACTOR = 5; //scales down the game to a smaller size



//registries
    //background, game window,
vector<vector<uint8_t>> static pixels; //pixels array
vector<sf::Texture> static textures; //texture array
vector<sf::Sprite> static sprites;

//for images and buttons
string static paths[1] = {"../lib/bg.png"};
buttonPanel buttons = buttonPanel(890, 100);


int main() {
    sf::RenderWindow static window(sf::VideoMode({WIDTH, HEIGHT}), "Dune Sim", sf::Style::Close);
    GameManager *gm = new GameManager(WIDTH, HEIGHT, FACTOR);

    gm->getBoard();

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
    window.draw(buttons.sprite);

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

    sf::Image bgPreset(paths[0]);
    for (int i = 0; i<WIDTH;i++) {
        for (int j =0;j<HEIGHT;j++) {
            setGridPixel(0, i, j, WIDTH, HEIGHT, bgPreset.getPixel(sf::Vector2u(i, j)));
        }
    }

    for (int i = 16; i<GWIDTH+24; i++) { //fills border
        for (int j = 16 ; j<GHEIGHT+24; j++) {
            setGridPixel(0, i, j, WIDTH, HEIGHT, sf::Color(0, 0, 0));
        }
    }

    textures[0].update(pixels[0].data());
    sprites[0].setTexture(textures[0]);

    updateTS(0);

    //fills gameviewer
    sf::Color gameViewerPixelated[GWIDTH/FACTOR][GHEIGHT/FACTOR]; //scales the pixels down a bit for display purposes

    int options = 3;
    sf::Color sand_options[options] = {sf::Color(202,160,106), sf::Color(71,56,45), sf::Color(187,168,143)};
    int min[3] = {168,152,130};
    int max[3] = {185,166,141};
    int difference[3];
    for (int i = 0; i<3;i++) {
        difference[i] = max[i] - min[i];
    }

    for (int i = 0; i < GWIDTH/FACTOR; i++) {
        int r = min[0] + rand() % difference[0];
        int g = min[1] + rand() % difference[1];
        int b = min[2] + rand() % difference[2];
        sand_options[1] = sf::Color(r, g, b);
        for (int j = 0; j < GHEIGHT/FACTOR; j++) {
            gameViewerPixelated[i][j] = sf::Color(sand_options[rand()%options]);
        }
    }



    for (int i = 0; i<GHEIGHT; i++) {
        for (int j = 0; j<GWIDTH; j++) {
            setGridPixel(1, j, i, GWIDTH, GHEIGHT, gameViewerPixelated[i/FACTOR][j/FACTOR]);
        }
    }

    updateTS(1);


    //inits and adds buttons
    int startW = 890;
    int startH = 100;

}