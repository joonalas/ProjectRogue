#ifndef MY_SDL_H
#define MY_SDL_H

#include <SDL.h>
#include <SDL_image.h>
#include <string>

//Window title
extern const char* TITLE;

//constants for screen width and height
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 360;

//window
extern SDL_Window* window;

//window surface
extern SDL_Surface* windowSurface;

//Bare ground image surface
extern SDL_Surface* baregroundSurface;

//SDL initialization function
bool init();

//Load BMP images and return surface
SDL_Surface* loadImage(const char*);

//Close and exit SDL
void close();

#endif