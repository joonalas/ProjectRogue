#include <stdio.h>
#include "mySDL.h"

//Title
const char* TITLE = "ProjectRogue";

//window
SDL_Window* window = NULL;

//window surface
SDL_Surface* windowSurface = NULL;

//Bare ground surface
SDL_Surface* baregroundSurface = NULL;

bool init() {
    //init flag
    bool success = true;

    //init SDL
    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error:\n%s\n", SDL_GetError());
        success = false;
    } else {
        //create window
        window = SDL_CreateWindow(
            TITLE,
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            SCREEN_WIDTH, SCREEN_HEIGHT,
            SDL_WINDOW_SHOWN
        );
        //test errors
        if(window == NULL) {
            printf("Window could not be created! SDL_Error:\n%s\n", SDL_GetError());
            success = false;
        } else {
            //Initialize PNG loading
            int imgFlags = IMG_INIT_PNG;
            if(!( IMG_Init( imgFlags ) & imgFlags )) {
                printf( "SDL_image could not initialize! SDL_image Error: \n%s\n", IMG_GetError() );
                success = false;
            } else {
                //get window surface
                windowSurface = SDL_GetWindowSurface(window);
            }
        }
    }

    return success;
}

//Load game assets
bool loadMedia() {
    //Success flag
    bool success = true;

    return success;
}

SDL_Surface* loadImage(const char* filepath) {
    //Final optimized image
    SDL_Surface* optimizedSurface = NULL;

    //load splash image
    SDL_Surface* loadedSurface = IMG_Load(filepath);
    if(loadedSurface == NULL) {
        printf("Unable to load image %s! SDL_image Error: \n%s\n", filepath, IMG_GetError());
    } else {
        //Convert surface to screen format
        optimizedSurface = SDL_ConvertSurface( loadedSurface, windowSurface->format, NULL );
        if( optimizedSurface == NULL ) {
            printf("Unable to optimize image %s! SDL Error: \n%s\n", filepath, SDL_GetError());
        }

        //Get rid of old loaded surface
        SDL_FreeSurface( loadedSurface );
    }

    return optimizedSurface;
}

void close() {
    //Deallocate terrain surfaces
    SDL_FreeSurface(baregroundSurface);
    baregroundSurface = NULL;

    //Destroy window
    SDL_DestroyWindow(window);
    window = NULL;

    //quit SDL subsystems
    IMG_Quit();
    SDL_Quit();

}