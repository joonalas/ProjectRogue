#include "mySDL.h"

//Texture wrapper class

WTexture::WTexture() {
    //Init
    hwTexture = NULL;
    hwWidth = 0;
    hwHeight = 0;
}

WTexture::~WTexture() {
    //Deallocate
    free();
}

bool WTexture::loadFromFile(const char* filepath) {
    //Get rid of preexisting texture
    free();

    //final texture
    SDL_Texture* newTexture = NULL;

    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load(filepath);
    if(loadedSurface == NULL) {
        printf("Unable to load image %s! SDL_image Error: \n%s\n", filepath, IMG_GetError());
    } else {
        //Color key image
        SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));

        //Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
        if(newTexture == NULL) {
            printf("Unable to create texture from %s! SDL Error: \n%s\n", filepath, SDL_GetError());
        } else {
            //Get image dimensions
            hwWidth = loadedSurface->w;
            hwHeight = loadedSurface->h;
        }

        //Get rid of old loaded surface
        SDL_FreeSurface(loadedSurface);
    }

    hwTexture = newTexture;
    return hwTexture != NULL;
}

void WTexture::free() {
    //Free texture if it exists
    if(hwTexture != NULL) {
        SDL_DestroyTexture(hwTexture);
        hwTexture = NULL;
        hwWidth = 0;
        hwHeight = 0;
    }
}

void WTexture::render(int x, int y, SDL_Rect* clip) {
    //Set rendering space and render to screen
    SDL_Rect renderQuad = {x, y, hwWidth, hwHeight};
    
    //Set clip rendering dimensions
    if( clip != NULL ) {
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }

    //Render to screen
    SDL_RenderCopy(renderer, hwTexture, clip, &renderQuad);
}

int WTexture::getWidth() {
    return hwWidth;
}

int WTexture::getHeight() {
    return hwHeight;
}