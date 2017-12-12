#include "mygame.h"
#include "mySDL.h"

Wall :: Wall(int posX, int posY) {
    x = posX;
    y = posY;
    //cout<<"Generating bare ground terrain...\n";
}

Wall :: ~Wall() {}

void Wall :: draw(){
    //Render wall sprite
    spriteSheetTexture.render(x, y, TERRAIN_WALL);
}