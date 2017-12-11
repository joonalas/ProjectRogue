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
            SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
            SDL_RenderClear(renderer);
            
            //render floor
            floor1.renderFloor();

            //Update screen
            SDL_RenderPresent(renderer);
        }
    }

    //Quit SDL and exit
    close();
    return 0;
}