#include <iostream>
#include "app.h"

int main(int argc, char** argv)
{

  SDL_Window* gWindow = NULL;			// window that will be rendered
  /*
  SDL_Surface* gScreenSurface = NULL;	// surface in our window
  SDL_Surface* gCurrentSurface = NULL;			// current displayed image
  SDL_Surface* gKeyPressSurfaces[KEY_PRESS_SURFACE_TOTAL];
  */
  SDL_Texture* gTexture = NULL;
  SDL_Renderer* gRenderer = NULL;

  if(!init(&gWindow, &gTexture, &gRenderer)) {
	  return 1;
  } else {

		//event handler
		SDL_Event e;

		/*
		//Fill the surface with white
		SDL_FillRect(gScreenSurface, NULL,
					 SDL_MapRGB(gScreenSurface->format,
								0xFF, 0xFF, 0xFF));
		
		//Update the surface
		if (gWindow == nullptr) {
			std::cout << "gWindow is null\n";
			return 1;
		}
		SDL_UpdateWindowSurface(gWindow);
		*/
		bool quit_app = false;

		// set default surface
		//gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT];

		while(!quit_app) {

			while(SDL_PollEvent(&e) != 0) {
			  
				//User request quit
				if(e.type == SDL_QUIT) {
					quit_app = true;
				}
				/*
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
			  */
			}
			/*
			//Apply the stretched surface
			SDL_Rect stretch_rect;
			stretch_rect.x = 0;
			stretch_rect.y = 0;
			stretch_rect.w = SCREEN_WIDTH;
			stretch_rect.h = SCREEN_HEIGHT;
			SDL_BlitScaled(gCurrentSurface, NULL, gScreenSurface, &stretch_rect);

			//Update the surface
			SDL_UpdateWindowSurface(gWindow);
			*/

			//Clear screen
			SDL_RenderClear(gRenderer);
			
			//Render texture to screen
			//SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);

			//Update screen
			//SDL_RenderPresent(gRenderer);
			SDL_Rect fillRect;
			fillRect.x = SCREEN_WIDTH / 4;
			fillRect.y = SCREEN_HEIGHT / 4;
			fillRect.w = SCREEN_WIDTH / 2;
			fillRect.h = SCREEN_HEIGHT / 2;
			SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );
			SDL_RenderFillRect( gRenderer, &fillRect );

			// draw green outline
			SDL_Rect outlineRect;
			outlineRect.x = SCREEN_WIDTH / 6;
			outlineRect.y = SCREEN_HEIGHT / 6;
			outlineRect.w = SCREEN_WIDTH * 2 / 3;
			outlineRect.h = SCREEN_HEIGHT * 2 / 3;

			SDL_SetRenderDrawColor( gRenderer, 0x00, 0xFF, 0x00, 0xFF );
			SDL_RenderDrawRect( gRenderer, &outlineRect);

			// draw blue horizontal line in the middle
			SDL_SetRenderDrawColor( gRenderer, 0x00, 0x00, 0xFF, 0xFF );
			SDL_RenderDrawLine( gRenderer, 0, SCREEN_HEIGHT / 2, SCREEN_WIDTH,
							   SCREEN_HEIGHT / 2);
			//Update screen
			SDL_RenderPresent(gRenderer);



		}		  
  }

  quit(gWindow, gTexture, gRenderer);

  return 0;
}
