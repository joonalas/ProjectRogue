#include <iostream>
#include <string>
#include "mygame.h"
#include "mySDL.h"

using namespace std;

int main() {
    //Initialize SDL
    if(!init()) {
        cout<<"Failed to initialize!\n";
    } else {
        //Get command intepreter instance
        Intepreter& intepreter = Intepreter :: getInstance();

        //Generate floor
        Floor floor1;

        //test textures TODO:erase
        if(!loadMedia()) {
            cout<<"Failed to load media!\n";
        }
    
        //Main loop flag
        bool quit = false;

        //Event handler
        SDL_Event e;
    
        //Main loop
        while(!quit) {
            //Handle events in the queue
            while(SDL_PollEvent(&e) != 0) {
                //Xing out the window
                if(e.type == SDL_QUIT) {
                    quit = true;
                }
            }

            //Clear screen
            SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
            SDL_RenderClear(renderer);

            //Render top left sprite
            spriteSheetTexture.render(0, 0, &spriteClips[0]);
            //top right
            spriteSheetTexture.render(SCREEN_WIDTH - spriteClips[1].w, 0, &spriteClips[1]);
            //bottom left
            spriteSheetTexture.render(0, SCREEN_HEIGHT - spriteClips[2].h, &spriteClips[2]);
            //bottom right
            spriteSheetTexture.render(SCREEN_WIDTH - spriteClips[3].w, SCREEN_HEIGHT - spriteClips[3].h, &spriteClips[3]);

            //Update screen
            SDL_RenderPresent(renderer);
        }
    }
    
    //Quit SDL and exit
    close();
    return 0;
}