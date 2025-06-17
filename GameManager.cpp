//
// Created by Viraj on 6/13/2025.
//

#include "GameManager.h"





GameManager::GameManager(int iWidth, int iHeight, int factor) { //constructor
    screenSize[0] = iWidth;
    screenSize[1] = iHeight;
    this->factor = factor;
    width = screenSize[0]/factor;
    height = screenSize[1]/factor;
    board.resize(width, vector<int>(height, 0));

}


void GameManager::updateBoard(){}; //just updates board using worm registry values

void GameManager::placeTerrain(){}; //places terrain focused around a specific point

void GameManager::placeThumper(){}; //places thumper and enacts movement changes

vector<vector<int>> GameManager::getBoard() { //returns the board - 0 = empty, 1 = terrain, 2 = worm head, 3 = worm body
    return board;
};

void GameManager::moveSandworm(){}; //moves the head of a sadnworm -CHANGE THIS

void GameManager::pathSandworm(){}; //changes the pathing of a sandworm -CHANGE THIS