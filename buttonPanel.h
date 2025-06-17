//
// Created by Viraj on 6/15/2025.
//

#ifndef BUTTONPANEL_H
#define BUTTONPANEL_H
#include "SFML/Graphics/Image.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"
using namespace std;

class buttonPanel {
public:
    int placement[2]{};
    int const width = 70;

    sf::Image const images[5] = {sf::Image("../lib/sample.png"), //pointer button
        sf::Image("../lib/sample.png"), //viewshift button
        sf::Image("../lib/sample.png"), //terain button
        sf::Image("../lib/sample.png"), //thumper button
        sf::Image("../lib/sample.png") //clear terrain button
    };

    string temp = "../lib/sample.png";

    sf::Texture texture;
    vector<vector<uint8_t>> static pixels; //pixels array
    sf::Sprite sprite;

    buttonPanel(int x, int y);
    void initButtons();
};



#endif //BUTTONPANEL_H
