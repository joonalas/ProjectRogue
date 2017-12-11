#include <iostream>
#include "mygame.h"

Room::Room(int posX, int posY) {
    std::cout<<"Creating new new Room.\n";
    //set floor position
    x = posX;
    y = posY;

    //set floor dimensions
    w = 5;
    h = 5;

    //allocate memory for blueprint
    blueprint = new Terrain*[w*h];

    //Fill blueprint with terrain
    for(int k = 0; k < h; k++) {
        for(int j = 0; j < w; j++) {
            blueprint[(k*w + j)] = new BareGround(j*TILE_WIDTH+x, k*TILE_HEIGHT+y);
        }
    }
}

Room::~Room() {
    std::cout<<"Deleting room blueprint...\n";
    //Delete blueprint terrain
    for(int i = 0; i < w*h; i++) {
        std::cout<<"Deleting "<<(i+1)<<". terrain piece...\n";
        delete blueprint[i];
    }
    //Delete blueprint
    std::cout<<"Deleting blueprint...\n";
    delete[] blueprint;
}

void Room::drawRoom() {
    //Iterate blueprint and render each terrain tile
    for(int i = 0; i < w*h; i++) {
        blueprint[i]->draw();
    }
}