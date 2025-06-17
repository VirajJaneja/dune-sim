//
// Created by Viraj on 6/15/2025.
//

#include "buttonPanel.h"
#include "SFML/Window/Mouse.hpp"
using namespace std;

buttonPanel::buttonPanel(int x, int y): placement(x, y), texture({(unsigned)width, (unsigned)((width*5)+(50*5))}), sprite(texture) {
    // pixels.emplace(width * (width*5)+(50*5)));
    initButtons();
}

void buttonPanel::initButtons() {
    texture.loadFromFile(temp);

    sprite.setPosition(sf::Vector2f(placement[0], placement[1]));
}
