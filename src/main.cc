#include <iostream>
#include <SDL.h>

//Screen dimensions
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char** argv)
{
  //The window to render
  SDL_Window* window = NULL;

  //The surface in the window
  SDL_Surface* surface = NULL;

  //Initialize SDL
  if(SDL_Init(SDL_INIT_VIDEO) < 0) {
	  std::cout << "SDL could not initialize! SDL_Error: "
		<< SDL_GetError() << '\n';
	  return 1;
  } else {
	  //Create window
	  window = SDL_CreateWindow("SDL Tutorial",	  // window title
								SDL_WINDOWPOS_UNDEFINED, //y pos
								SDL_WINDOWPOS_UNDEFINED, //x pos
								SCREEN_WIDTH,
								SCREEN_HEIGHT,
								SDL_WINDOW_SHOWN);
  }
  if(window == nullptr) {
	  std::cout << "Window could not be created! SDL_Error: "
		<< SDL_GetError() << '\n';
	  return 1;
  } else {
	  //get window surface handle
	  surface = SDL_GetWindowSurface(window);

	  //main loop flag
	  bool quit = false;

	  //event handler
	  SDL_Event e;

	  //Fill the surface with white
	  SDL_FillRect(surface, NULL,
				   SDL_MapRGB(surface->format,
							  0xFF, 0xFF, 0xFF));

	  //Update the surface
	  SDL_UpdateWindowSurface(window);

	  //Show window for 2 seconds the close
	  //SDL_Delay(2000);

	  while(!quit) {

		  while(SDL_PollEvent(&e) != 0) {
			
			  //User request quit
			  if(e.type == SDL_QUIT) {
				  quit = true;
			  }

		  }

	  }		  
  }

  //Destroy window
  SDL_DestroyWindow(window);

  //Quit SDL subsystem
  SDL_Quit();

  return 0;
}
