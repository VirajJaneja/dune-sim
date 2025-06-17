//
// Created by Viraj on 6/13/2025.
//

#include "Sandworm.h"

Sandworm::Sandworm(int len, int size) {
    this->len =  len;
    this->size = size;
}

Sandworm::Sandworm(int Len, int size, int X, int Y){
    this->len = Len;
    this->size = size;
    head[0] = X;
    head[1] = Y;
    // body = new vector<int[2]>(len);

    // body->assign()
}


