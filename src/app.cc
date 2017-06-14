#include "app.h"

SDL_Surface* load_surface(std::string path, SDL_Surface* gScreenSurface)
{

  //The final optimized image will be returned
  SDL_Surface* optimized_surface = NULL;

  //Load images from specified path
  SDL_Surface* loaded_surface = SDL_LoadBMP(path.c_str());

  if(loaded_surface == nullptr) {
	std::cerr << "Unable to load image " 
	  << path.c_str() << " SDL_Error: " << SDL_GetError() << '\n';
  } else {
	//Convert image to screen format
	optimized_surface = SDL_ConvertSurface(loaded_surface,
							  gScreenSurface->format, 0);
	if(optimized_surface == nullptr) {
		std::cerr << "Unable to optimize image "
		  << path.c_str() << " SDL_Error: " << SDL_GetError() << '\n';
	}

	//Get rid of old loaded surface
	SDL_FreeSurface(loaded_surface);
  }
  return optimized_surface;
}

bool load_media(SDL_Surface* gKeyPressSurfaces[], SDL_Surface** gScreenSurface)
{
  //loading success flag
  bool success = true;

  //load default surface
  gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT] = load_surface("../data/press.bmp", *gScreenSurface);
  if(gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT] == nullptr) {
	  std::cerr << "Failed to load default image\n";
	  success = false;
  }

  //load up surface
  gKeyPressSurfaces[KEY_PRESS_SURFACE_UP] = load_surface("../data/up.bmp",*gScreenSurface);
  if(gKeyPressSurfaces[KEY_PRESS_SURFACE_UP] == nullptr) {
	  std::cerr << "Failed to load up image\n";
	  success = false;
  }

  //load down surface
  gKeyPressSurfaces[KEY_PRESS_SURFACE_DOWN] = load_surface("../data/down.bmp",*gScreenSurface);
  if(gKeyPressSurfaces[KEY_PRESS_SURFACE_DOWN] == nullptr) {
	  std::cerr << "Failed to load down image\n";
	  success = false;
  }

  //load left surface
  gKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT] = load_surface("../data/left.bmp",*gScreenSurface);
  if(gKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT] == nullptr) {
	  std::cerr << "Failed to load left image\n";
	  success = false;
  }

  //load right surface
  gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT] = load_surface("../data/right.bmp",*gScreenSurface);
  if(gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT] == nullptr) {
	  std::cerr << "Failed to load right image\n";
	  success = false;
  }

  return success;
}

bool init(SDL_Window** gWindow, 
		  SDL_Surface** gScreenSurface,
		  SDL_Surface* gKeyPressSurfaces[])
{
  bool success = true;
  
  //Initialize SDL
  if(SDL_Init(SDL_INIT_VIDEO) < 0) {
	  std::cerr << "SDL could not be initialized! SDL_Error: "
		<< SDL_GetError() << '\n';
	  success = false;
  } else {
	  //create window
	  *gWindow = SDL_CreateWindow("SDL Key Pressed Events",
								 SDL_WINDOWPOS_UNDEFINED,
								 SDL_WINDOWPOS_UNDEFINED,
								 SCREEN_WIDTH,
								 SCREEN_HEIGHT,
								 SDL_WINDOW_SHOWN);
  }
  if(gWindow == nullptr) {
	  std::cerr << "Window could not be created! SDL_Error: "
		<< SDL_GetError() << '\n';
	  success = false;
  } else {
	  *gScreenSurface = SDL_GetWindowSurface(*gWindow);
	  if(gScreenSurface == nullptr) {
		  std::cerr << "Unable to get handle for surface! SDL_Error: "
			<< SDL_GetError() << '\n';
		  success = false;
	  } else {
		  load_media(gKeyPressSurfaces, gScreenSurface);
	  }
  }

  return success;
}

void quit(SDL_Window* gWindow)
{
  SDL_DestroyWindow(gWindow);
  SDL_Quit();
} 
