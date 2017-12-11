#ifndef MY_SDL_H
#define MY_SDL_H

#include <SDL.h>
#include <SDL_image.h>
#include <string>

/*
    CONSTANTS
+-------------------------------------------------------------------------------+
*/

//Window title
extern const char* TITLE;

//constants for screen width and height
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 360;

/*
    CLASSES
+-------------------------------------------------------------------------------+
*/

//Texture wrapper class
class WTexture {
    public:
    //Initializes variables
    WTexture();
    //Deallocates memory
    ~WTexture();
    //Loads image at specified path
    bool loadFromFile(const char*);
    //Deallocates texture
    void free();
    //Renders texture at given point
    void render(int x, int y, SDL_Rect* clip = NULL);
    //Gets image dimensions
    int getWidth();
    int getHeight();

    private:
    //Actual hardware texture
    SDL_Texture* hwTexture;
    //Image dimensions
    int hwWidth;
    int hwHeight;
};

/*
    VARIABLES
+-------------------------------------------------------------------------------+
*/

//window
extern SDL_Window* window;

//window surface
extern SDL_Surface* windowSurface;

//Window renderer
extern SDL_Renderer* renderer;

//Current displayed texture
extern SDL_Texture* currentTexture;

//Bare ground image surface
extern SDL_Surface* baregroundSurface;

//Scene sprites
extern SDL_Rect spriteClips[4];
extern WTexture spriteSheetTexture;

/*
    FUNCTIONS
+-------------------------------------------------------------------------------+
*/

//SDL initialization function
bool init();

//Load game assets
bool loadMedia();

//Load BMP images and return surface
SDL_Surface* loadImage(const char*);

//Load images as texture
SDL_Texture* loadTexture(const char*);

//Close and exit SDL
void close();


#endif