#include <iostream>
#include "mygame.h"
#include "mySDL.h"

using namespace std;

BareGround :: BareGround(int posX, int posY) {
    x = posX;
    y = posY;
    cout<<"Generating bare ground terrain...\n";
}

BareGround :: ~BareGround() {

}

void BareGround :: draw(){
    //bare ground
    spriteSheetTexture.render(x, y, &spriteClips[0]);
}