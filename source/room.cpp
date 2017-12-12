#include "mygame.h"

Room::Room(int posX, int posY) {
    cout<<"Creating new Room.\n";

    //Initialize random seed
    srand(time(NULL));

    //set floor position
    x = posX;
    y = posY;

    //set floor dimensions
    w = rand() % 8 + 3; //width 3-10 tiles
    h = rand() % 8 + 3; //height 3-10 tiles

    //allocate memory for blueprint
    blueprint = new Terrain*[w*h];

    //Fill blueprint with terrain
    for(int k = 0; k < h; k++) {
        for(int j = 0; j < w; j++) {
            //walls
            if(k == 0 || k == (h-1) || j == 0 || j == (w-1)) {
                cout<< "wall created\n";
                blueprint[(k*w + j)] = new Wall(j*TILE_WIDTH+x, k*TILE_HEIGHT+y);
            } else {
                blueprint[(k*w + j)] = new BareGround(j*TILE_WIDTH+x, k*TILE_HEIGHT+y);
            }
        }
    }
}

Room::~Room() {
    cout<<"Deleting room blueprint...\n";
    //Delete blueprint terrain
    for(int i = 0; i < w*h; i++) {
        delete blueprint[i];
    }
    //Delete blueprint
    //std::cout<<"Deleting blueprint...\n";
    delete[] blueprint;
}

void Room::drawRoom() {
    //Iterate blueprint and render each terrain tile
    for(int i = 0; i < w*h; i++) {
        blueprint[i]->draw();
    }
}