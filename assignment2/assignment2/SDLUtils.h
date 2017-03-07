#ifndef SDLUTILS_HEADER
#define SDLUTILS_HEADER

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


#define screenW 960
#define screenH 960

//#define screenW 640
//#define screenH 480

#define teamSize 3

const int mapW = 15;
const int mapH = 15;
const int mapSize = mapW * mapH;


//int renderOffsetX = -200;
//int renderOffsetY = -200;

//int spriteSize = 32;
//int tileSize = 32;
//bool globalRunning = true;


struct mapTile{
	int screenX;
	int screenY;
	int worldX;
	int worldY;
	int typeX;
	int typeY;
	bool blocked;
	bool selected;
	bool moveRange;
	bool attackRange;
	//bool rangedAttackRange
};


class SDLUtils{
public: 
	SDL_Window* window;
	SDL_Renderer* rend;

	bool initSDL();
	//SDL_Texture* loadPNG(char path[]);
};

#endif