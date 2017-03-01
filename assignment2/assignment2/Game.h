#ifndef GAME_HEADER
#define GAME_HEADER

#include "SDLUtils.h"

struct mapTile{
	int screenX;
	int screenY;
	int typeX;
	int typeY;
	bool blocked;
	bool selected;
	bool moveRange;
	bool attackRange;
};

class Game{
public:
	Game();

	//SDL_Texture* loadPNG(SDL_Renderer* rend, char path[]);	//implemented
	void initTextures();					//implemented

	void initMap();											//implemented

	void checkClick(int clickX, int clickY);				//implemented

	void handleEvents();									//implemented

	void renderMap();						//implemented

	void gameLoop();
private:
	//const int mapW = 15;
	//const int mapH = 15;
	//const int mapSize = mapW * mapH;
	
	SDLUtils* sdlUtils;
	
	bool globalRunning;
	SDL_Texture* mapTileTexture = NULL;
	SDL_Event evnt;
	int tileSize = 32;
	mapTile map[mapW][mapH];
	
};

#endif