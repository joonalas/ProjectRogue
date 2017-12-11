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

            //Update window
            SDL_UpdateWindowSurface(window);
        }
    }
    
    //Quit SDL and exit
    close();
    return 0;
}