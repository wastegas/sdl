#include "app.h"

SDL_Surface* load_surface(std::string path)
{
  std::cout << "load_surface(" << path << ")\n";
  //Load images from specified path
  SDL_Surface* loaded_surface = SDL_LoadBMP(path.c_str());

  if(loaded_surface == nullptr) {
	std::cerr << "Unable to loade image " 
	  << path.c_str() << " SDL_Error: " << SDL_GetError() << '\n';
  }
  return loaded_surface;
}

bool load_media(SDL_Surface* gKeyPressSurfaces[])
{
  std::cout << "starting load_media\n";
  //loading success flag
  bool success = true;

  std::cout << "loading press\n";
  //load default surface
  gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT] = load_surface("../data/press.bmp");
  if(gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT] == nullptr) {
	  std::cerr << "Failed to load default image\n";
	  success = false;
  }

  std::cout << "loading up\n";
  //load up surface
  gKeyPressSurfaces[KEY_PRESS_SURFACE_UP] = load_surface("../data/up.bmp");
  if(gKeyPressSurfaces[KEY_PRESS_SURFACE_UP] == nullptr) {
	  std::cerr << "Failed to load up image\n";
	  success = false;
  }

  std::cout << "loading down\n";
  //load down surface
  gKeyPressSurfaces[KEY_PRESS_SURFACE_DOWN] = load_surface("../data/down.bmp");
  if(gKeyPressSurfaces[KEY_PRESS_SURFACE_DOWN] == nullptr) {
	  std::cerr << "Failed to load down image\n";
	  success = false;
  }

  std::cout << "loading left\n";
  //load left surface
  gKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT] = load_surface("../data/left.bmp");
  if(gKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT] == nullptr) {
	  std::cerr << "Failed to load left image\n";
	  success = false;
  }

  std::cout << "loading right\n";
  //load right surface
  gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT] = load_surface("../data/right.bmp");
  if(gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT] == nullptr) {
	  std::cerr << "Failed to load right image\n";
	  success = false;
  }

  std::cout << "done loading media\n";
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
	  std::cout << "gWindow's address" << static_cast<void*>(gWindow) << '\n'; 
  }
  if(gWindow == nullptr) {
	  std::cerr << "Window could not be created! SDL_Error: "
		<< SDL_GetError() << '\n';
	  success = false;
  } else {
	  std::cout << "gWindow created\n";
	  *gScreenSurface = SDL_GetWindowSurface(*gWindow);
	  std::cout << "gScreenSurface in init is at " << static_cast<void*>(gScreenSurface)
		<< '\n';
	  if(gScreenSurface == nullptr) {
		  std::cerr << "Unable to get handle for surface! SDL_Error: "
			<< SDL_GetError() << '\n';
		  success = false;
	  } else {
		  std::cout << "gScreenSurface handle created\n";
		  load_media(gKeyPressSurfaces);
		  std::cout << "init complete\n";
	  }
  }

  return success;
}

void quit(SDL_Window* gWindow)
{
  SDL_DestroyWindow(gWindow);
  SDL_Quit();
} 
