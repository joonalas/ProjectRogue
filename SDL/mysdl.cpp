#include <stdio.h>
#include "mySDL.h"

//Title
const char* TITLE = "ProjectRogue";

/*
    VARIABLE DEFINITIONS
+-------------------------------------------------------------------------------+
*/

//window
SDL_Window* window = NULL;

//window surface
SDL_Surface* windowSurface = NULL;

//renderer
SDL_Renderer* renderer = NULL;

//current displayed texture
SDL_Texture* currentTexture = NULL;

//Bare ground surface
SDL_Surface* baregroundSurface = NULL;

//Scene sprites
SDL_Rect spriteClips[1];
WTexture spriteSheetTexture;

/*
    FUNCTION DEFINITIONS
+-------------------------------------------------------------------------------+
*/

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
            //Create renderer for the window
            renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );
            if(renderer == NULL) {
                printf( "Renderer could not be created! SDL Error: \n%s\n", SDL_GetError() );
                success = false;
            } else {
                //Initialize renderer color
                SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

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
    }

    return success;
}

//Load game assets
bool loadMedia() {
    //Success flag
    bool success = true;

    //Load terrain sprite sheet texture
    if(!spriteSheetTexture.loadFromFile("../Textures/Terrain/terrainsheet.png", 4, 12)) {
        printf( "Failed to load sprite sheet texture!\n" );
        success = false;
    } else {
        //Init individual sprite clipping data, provide width and height of a single sprite as arguments
        spriteSheetTexture.addSpriteClips(64, 64);
    }

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

SDL_Texture* loadTexture(const char* filepath) {
    //final texture
    SDL_Texture* newTexture = NULL;

    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load(filepath);
    if(loadedSurface == NULL) {
        printf("Unable to load image %s! SDL_image Error: \n%s\n", filepath, IMG_GetError());
    } else {
        //Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
        if(newTexture == NULL) {
            printf("Unable to create texture from %s! SDL Error: \n%s\n", filepath, SDL_GetError());
        }

        //Get rid of old loaded surface
        SDL_FreeSurface(loadedSurface);
    }

    return newTexture;
}

void close() {
    //Free loaded images
    spriteSheetTexture.free();

    //Deallocate terrain surfaces
    SDL_FreeSurface(baregroundSurface);
    baregroundSurface = NULL;

    //Destroy textures
    SDL_DestroyTexture(currentTexture);
    currentTexture = NULL;

    //Destroy window
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    renderer = NULL;
    window = NULL;

    //quit SDL subsystems
    IMG_Quit();
    SDL_Quit();

}