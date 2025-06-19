//
// Created by Viraj on 6/15/2025.
//

#include "buttonPanel.h"

#include <iostream>

#include "SFML/Window/Mouse.hpp"
using namespace std;

buttonPanel::buttonPanel(int x, int y): placement(x, y), texture({(unsigned)width, (unsigned)((width*5)+(50*5))}), sprite(texture) {
    initButtons();
}

void buttonPanel::initButtons() {
    loadCombinedImage();
    sprite.setPosition(sf::Vector2f(placement[0], placement[1]));
}

void buttonPanel::loadCombinedImage() {
    int counter = 0;
    sf::Image temp;
    sf::Image combinedImage = sf::Image(sf::Vector2u{100, buttonCount*(100+30)}, sf::Color::Transparent);
    for (int i = 0; i < buttonCount;i ++) {
        temp = images[i];
        if (mode == i) {
            sf::Vector2u size = temp.getSize();
            int w = size.x;
            int h = size.y;

            //left and top border case
            for (int j = 0; j < 5; j ++) {
                for (int k = 0; k < w; k++) {
                    temp.setPixel(sf::Vector2u(j, k), sf::Color(255,0,255));
                    temp.setPixel(sf::Vector2u(k, j), sf::Color(255,0,255));
                }
            }

            //bottom and right border case
            for (int j = w-5; j < w; j ++) {
                for (int k = 0; k < w; k++) {
                    temp.setPixel(sf::Vector2u(j, k), sf::Color(255,0,255));
                    temp.setPixel(sf::Vector2u(k, j), sf::Color(255,0,255));
                }
            }


        }
        combinedImage.copy(temp, sf::Vector2u(0, counter));
        counter += 100;
    }
    texture.loadFromImage(combinedImage);
    sprite.setTexture(texture);
}

int buttonPanel::takeInput(int x, int y) {
    int check = y%100;
    if (check <= 90) {
        mode = y/100;
    }
    cout << check << endl;
    loadCombinedImage();
    return mode;
}

