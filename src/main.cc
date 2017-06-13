#include <iostream>
#include "app.h"

int main(int argc, char** argv)
{

  SDL_Window* gWindow = NULL;			// window that will be rendered
  SDL_Surface* gScreenSurface = NULL;	// surface in our window
  SDL_Surface* gCurrentSurface = NULL;			// current displayed image
  SDL_Surface* gKeyPressSurfaces[KEY_PRESS_SURFACE_TOTAL];

  if(!init(&gWindow, &gScreenSurface, gKeyPressSurfaces)) {
	  return 1;
  } else {

		std::cout << "declaring in main\n";
		//event handler
		SDL_Event e;
		std::cout << "coloring surface\n";
		//Fill the surface with white
		if (gScreenSurface == nullptr ) {
			std::cout << "gScreenSurface at " << static_cast<void*>(gScreenSurface) << " is null cannot continue\n";
			return 1;
		}
		SDL_FillRect(gScreenSurface, NULL,
					 SDL_MapRGB(gScreenSurface->format,
								0xFF, 0xFF, 0xFF));
		
		std::cout << "updating surface\n";
		//Update the surface
		if (gWindow == nullptr) {
			std::cout << "gWindow is null\n";
			return 1;
		}
		SDL_UpdateWindowSurface(gWindow);

		bool quit_app = false;

		std::cout << "setting default surface\n";
		// set default surface
		gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT];

		std::cout << "entering main loop\n";
		while(!quit_app) {

			while(SDL_PollEvent(&e) != 0) {
			  
				//User request quit
				if(e.type == SDL_QUIT) {
					quit_app = true;
				} else if(e.type == SDL_KEYDOWN) {  // user pressed a key
					// select surfaces based on key pressed
					switch(e.key.keysym.sym) {
					  case SDLK_UP:
						gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_UP];
						break;
					  case SDLK_DOWN:
						gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_DOWN];
						break;
					  case SDLK_LEFT:
						gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT];
						break;
					  case SDLK_RIGHT:
						gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT];
						break;
					  default:
						gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT];
						break;
					}

			  }
			}

			//Apply current image
			SDL_BlitSurface(gCurrentSurface, NULL, gScreenSurface, NULL);

			//Update the surface
			SDL_UpdateWindowSurface(gWindow);

		}		  
  }

  quit(gWindow);

  return 0;
}
