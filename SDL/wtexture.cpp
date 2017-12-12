#include "mySDL.h"
#include "mygame.h"

//Texture wrapper class

WTexture::WTexture() {
    //Init
    hwTexture = NULL;
    spriteCount = 0;
    rows = 0;
    columns = 0;
    hwWidth = 0;
    hwHeight = 0;
}

WTexture::~WTexture() {
    //Deallocate
    free();
}

bool WTexture::loadFromFile(const char* filepath, int newColumns, int newRows) {
    //Get rid of preexisting texture
    free();

    //Init rows and columns
    rows = newRows; columns = newColumns;
    //Init number of spites in the sheet
    spriteCount = rows*columns;

    //Initialize sprite clips
    spriteClips = new SDL_Rect[spriteCount];

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

void WTexture::addSpriteClips(int w, int h) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            spriteClips[i*columns+j].w = w;
            spriteClips[i*columns+j].h = h;
            spriteClips[i*columns+j].x = j*w;
            spriteClips[i*columns+j].y = i*h;
        }
    }
}

void WTexture::free() {
    //Free texture if it exists
    if(hwTexture != NULL) {
        SDL_DestroyTexture(hwTexture);
        hwTexture = NULL;
        hwWidth = 0;
        hwHeight = 0;
    }
    //Free clip information
    delete[] spriteClips; 
    spriteClips = NULL;
    spriteCount = 0;
}

void WTexture::render(int x, int y, int clip) {
    //Set rendering space and render to screen
    SDL_Rect renderQuad = {x, y, hwWidth, hwHeight};

    //Set clip rendering dimensions
    if( &spriteClips[clip] != NULL ) {
        renderQuad.w = TILE_WIDTH;
        renderQuad.h = TILE_HEIGHT;
    }

    //Render to screen
    SDL_RenderCopy(renderer, hwTexture, &spriteClips[clip], &renderQuad);
}

int WTexture::getWidth() {
    return hwWidth;
}

int WTexture::getHeight() {
    return hwHeight;
}