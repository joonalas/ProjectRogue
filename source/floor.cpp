#include <iostream>
#include "mygame.h"

//Constructor
Floor :: Floor() {
    std::cout<<"Creating new floor.\n";

    //set floor dimensions
    x = 5;
    y = 5;

    //Needed length for the blueprint
    blueprintLength = x * y; 

    //allocate memory for blueprint
    blueprint = new Terrain*[blueprintLength];

    //Fill blueprint with terrain
    for(int i = 0; i < blueprintLength; i++) {
        blueprint[i] = new BareGround();
    }
}

Floor :: ~Floor() {
    std::cout<<"Deleting blueprint...\n";
    //Delete blueprint terrain
    for(int i = 0; i < blueprintLength; i++) {
        std::cout<<"Deleting "<<(i+1)<<". terrain piece...\n";
        delete blueprint[i];
    }
    //Delete blueprint
    std::cout<<"Deleting blueprint...\n";
    delete[] blueprint;
}