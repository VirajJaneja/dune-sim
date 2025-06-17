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
    sf::Image combinedImage = sf::Image(sf::Vector2u{100, buttonCount*(100+30)}, sf::Color::Transparent);
    for (int i = 0; i < buttonCount;i ++) {
        combinedImage.copy(images[i], sf::Vector2u(0, counter));
        counter += 100;
    }
    texture.loadFromImage(combinedImage);
}

