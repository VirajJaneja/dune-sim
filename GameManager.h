//
// Created by Viraj on 6/13/2025.
//

#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H


#include <vector>
#include "Sandworm.h"
using namespace std;

class GameManager {
public:
    vector<vector<int>> board;
    int screenSize[2];
    int factor;
    int width;
    int height;
    vector<Sandworm> worm_registry;

    GameManager(int width, int height, int factor); //constructor

    void updateBoard(); //just updates board using worm registry values

    void placeTerrain(); //places terrain focused around a specific point

    void placeThumper(); //places thumper and enacts movement changes

    vector<vector<int>> getBoard(); //returns board

    void moveSandworm(); //moves the head of a sadnworm -CHANGE THIS

    void pathSandworm(); //changes the pathing of a sandworm -CHANGE THIS



};



#endif //GAMEMANAGER_H
