#ifndef SDLUTILS_HEADER
#define SDLUTILS_HEADER

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <iostream>
#include <vector>
#include <string>

#define screenW 640
#define screenH 480

const int mapW = 15;
const int mapH = 15;
const int mapSize = mapW * mapH;

//bool globalRunning = true;

class SDLUtils{
public: 
	SDL_Window* window;
	SDL_Renderer* rend;

	bool initSDL();
	SDL_Texture* loadPNG(char path[]);
};

#endif