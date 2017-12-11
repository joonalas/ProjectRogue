#include <iostream>
#include "mygame.h"

void Floor :: setDimensionX(int x) {
    this -> x = x;
}

void Floor :: setDimensionY(int y) {
    this -> y = y;
}

int Floor :: getDimensionX() {
    return this -> x;
}

int Floor :: getDimensionY() {
    return this -> y;
}

//Constructor
Floor :: Floor() {
    //set floor dimensions
    setDimensionX(5);
    setDimensionY(5);

    //allocate memory for blueprint
    this -> blueprint = new Terrain*[7];
}