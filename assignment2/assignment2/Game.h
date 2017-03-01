#ifndef GAME_HEADER
#define GAME_HEADER

#include "SDLUtils.h"
#include "Input.h"

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
};

class Game{
public:
	Game();

	
	void initTextures();					

	void initMap();											

	void buildMapFromTypes();

	void checkClick(int clickX, int clickY);				

	void clearSelection();

	void checkMovementRange(int moveDist, int originX, int originY);

	bool isTraversable(int x, int y);

	void handleEvents();									

	void renderMap();						

	void update(InputState inputState);

	void gameLoop();
private:
	//const int mapW = 15;
	//const int mapH = 15;
	//const int mapSize = mapW * mapH;
	
	SDLUtils* sdlUtils;
	Input* input;

	bool globalRunning;
	SDL_Texture* mapTileTexture = NULL;
	int spriteSize = 32;
	SDL_Event evnt;
	int tileSize = 32;
	mapTile map[mapW][mapH];
	int mapTypes[15][15];
	
};

#endif