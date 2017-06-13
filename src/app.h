#ifndef APP_H
#define APP_H

#include <SDL.h>
#include <string>
#include <iostream>

//Screen dimensions
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//Key press surface constants
enum KeyPressSurfaces
{
  KEY_PRESS_SURFACE_DEFAULT,
  KEY_PRESS_SURFACE_UP,
  KEY_PRESS_SURFACE_DOWN,
  KEY_PRESS_SURFACE_LEFT,
  KEY_PRESS_SURFACE_RIGHT,
  KEY_PRESS_SURFACE_TOTAL
};

bool init(SDL_Window**, 
		  SDL_Surface**, SDL_Surface* []);	// startup SDL and create window
bool load_media(SDL_Surface*);			// loads media	
void quit(SDL_Window*);					// free media and shutdown SDL
SDL_Surface* load_surface(std::string); // load individual image

#endif // APP_H
