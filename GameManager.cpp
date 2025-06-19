//
// Created by Viraj on 6/13/2025.
//

#include "GameManager.h"





GameManager::GameManager(int iWidth, int iHeight, int factor, int iTerrainModifier) { //constructor

    screenSize[0] = iWidth;
    screenSize[1] = iHeight;
    this->factor = factor;
    width = screenSize[0]/factor;
    height = screenSize[1]/factor;
    board.resize(width, vector<int>(height, 0));
    terrainModifier = iTerrainModifier;
    terrainSize[0] = width/terrainModifier;
    terrainSize[1] = height/terrainModifier;

}


void GameManager::updateBoard(){}; //just updates board using worm registry values

void GameManager::placeTerrain(int x, int y) {
    cout << x << " " << y << endl;
    cout << width << " " << height << endl;
    board[x][y] = 1;
    int halfX = terrainSize[0]/2;
    int halfY = terrainSize[1]/3;
    for (int i = x-halfX; i < x+halfX; i++) {
        for (int j = y-halfY; j < y+halfY; j++) {
            if (isWithinBounds(i, j)) {
                board[i][j] = 1;
            }
        }
    }
}; //places terrain focused around a specific point

bool GameManager::isWithinBounds(int x, int y) {
    return ((x >= 0 && x < width) && (y >=0 && y < height));
}

void GameManager::placeThumper(){}; //places thumper and enacts movement changes

void GameManager::clearTerrain() {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            if (board[i][j] == 1) {
                board[i][j] = 0;
            }
        }
    }
}

vector<vector<int>> GameManager::getBoard() { //returns the board - 0 = empty, 1 = terrain, 2 = worm head, 3 = worm body
    return board;
};

void GameManager::moveSandworm(){}; //moves the head of a sadnworm -CHANGE THIS

void GameManager::pathSandworm(){}; //changes the pathing of a sandworm -CHANGE THIS