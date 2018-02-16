#include "mygame.h"
#include "mySDL.h"

int main() {
    //Initialize SDL
    if(!init()) {
        cout<<"Failed to initialize!\n";
    } else {

        //Generate floor
        Floor* floor;
        floor = new Floor(FLOOR_WIDTH, FLOOR_HEIGHT);

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
                } else if(e.type == SDL_KEYDOWN) {
                    delete floor;
                    floor = new Floor(FLOOR_WIDTH, FLOOR_HEIGHT);
                }
            }

            //Clear screen
            SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
            SDL_RenderClear(renderer);
            
            //render floor
            floor->renderFloor();

            //Update screen
            SDL_RenderPresent(renderer);
        }
        //Deallocate floor data
        delete floor;
    }

    //Quit SDL and exit
    close();
    return 0;
}