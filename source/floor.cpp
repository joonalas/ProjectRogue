#include <iostream>
#include "mygame.h"

//Constructor
Floor :: Floor() {
    std::cout<<"Creating new floor.\n";

    //Initialize number of rooms
    roomCount = 2;

    //set floor dimensions
    w = 5;
    h = 5;

    //allocate memory for blueprint
    blueprint = new Room*[roomCount];

    //Fill blueprint with Rooms
    for(int i = 0; i < roomCount; i++) {
        blueprint[i] = new Room(i*100+5, i*100+5);
    }
}

Floor :: ~Floor() {
    std::cout<<"Deleting floor blueprint...\n";
    //Delete blueprint rooms
    for(int i = 0; i < roomCount; i++) {
        blueprint[i]->~Room();
    }
    //Delete blueprint
    delete[] blueprint;
}

void Floor :: renderFloor() {
    //Iterate blueprint and render each room
    for(int i = 0; i < roomCount; i++) {
        blueprint[i]->drawRoom();
    }
}