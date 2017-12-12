#include "mygame.h"

//Constructor
Floor :: Floor() {
    cout<<"Creating new floor.\n";

    //Initialize random seed
    srand(time(NULL));

    //Initialize number of rooms, something between 1-4
    roomCount = 1/*rand() % 4 + 1*/;

    //allocate memory for blueprint
    blueprint = new Room*[roomCount];

    //Fill blueprint with Rooms
    for(int i = 0; i < roomCount; i++) {
        blueprint[i] = new Room(5, 5);
    }
}

Floor :: ~Floor() {
    cout<<"Deleting floor blueprint...\n";
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