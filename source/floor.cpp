#include "mygame.h"

//Constructor
Floor :: Floor(int w, int h) {
    cout<<"Creating new floor.\n";

    this->w = w;
    this->h = h;

    //Initialize random seed
    srand(time(NULL));

    //Initialize number of rooms, something between 1-4
    //Number of tries for placing random rooms
    roomCount = 8/*rand() % 4 + 1*/;

    //allocate memory for blueprint
    blueprint = new Room*[roomCount];

    //Fill blueprint with Rooms
    for(int i = 0; i < roomCount; i++) {
        int roomX = rand() % 1200 + 1;
        int roomY = rand() % 960 + 1;

        //randomize room dimensions
        int roomW = rand() % 8 + 3; //width 3-10 tiles
        int roomH = rand() % 8 + 3; //height 3-10 tiles

        //check that new room doesn't overlap with existing one
        for(int j = 0; j < roomCount; j++) {
            if(blueprint[j]==NULL) {
                cout<<"Tyhjä!"<<"\n";
            } else {
                cout<<blueprint[j]->getWidth()<<", "<<blueprint[j]->getHeight()<<"\n";
            }
        }

        blueprint[i] = new Room(roomX, roomY, roomW, roomH);
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