//
// Created by Viraj on 6/13/2025.
//

#ifndef SANDWORM_H
#define SANDWORM_H
#include <iostream>
#include <vector>

#include "SFML/System/Vector2.hpp"

using namespace std;


class Sandworm {
public:
    // vector<int[2]> *body;
    int head[2];
    int len;
    int size;

    Sandworm(int len, int size);
    Sandworm(int len, int size, int startX, int startY);
};




#endif //SANDWORM_H
