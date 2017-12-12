#include "mygame.h"
#include "mySDL.h"

BareGround :: BareGround(int posX, int posY) {
    x = posX;
    y = posY;
    //cout<<"Generating bare ground terrain...\n";
}

BareGround :: ~BareGround() {}

void BareGround :: draw(){
    //Render bare ground sprite
    spriteSheetTexture.render(x, y, TERRAIN_BAREGROUND);
}