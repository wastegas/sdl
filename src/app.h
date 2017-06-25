#ifndef APP_H
#define APP_H

#include <SDL.h>
#include <SDL_image.h>
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
		  SDL_Texture**, 
		  SDL_Renderer**);	// startup SDL and create window
bool load_media(SDL_Texture**, SDL_Renderer**);			// loads media	
void quit(SDL_Window*, SDL_Texture*, SDL_Renderer*);					// free media and shutdown SDL
//SDL_Surface* load_surface(std::string); // load individual image
SDL_Texture* load_texture(std::string, SDL_Renderer**);

#endif // APP_H
