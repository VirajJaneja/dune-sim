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
    int const width = 100;
    int const static buttonCount = 5;

    sf::Image const images[buttonCount] = {sf::Image("../lib/pointer.png"), //pointer button
        sf::Image("../lib/sample.png"), //viewshift button
        sf::Image("../lib/sample.png"), //terain button
        sf::Image("../lib/sample.png"), //thumper button
        sf::Image("../lib/sample.png") //clear terrain button
    };

    bool modes[buttonCount] = {false, false, false, false, false};

    string temp = "../lib/sample.png";

    sf::Texture texture;
    vector<uint8_t> pixels; //pixels array
    sf::Sprite sprite;
    sf::Image combinedImage = sf::Image(sf::Vector2u{100, 600}, sf::Color::Transparent);

    buttonPanel(int x, int y);
    void initButtons();
    void loadCombinedImage();
};



#endif //BUTTONPANEL_H
