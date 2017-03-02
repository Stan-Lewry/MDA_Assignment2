#ifndef GAME_HEADER
#define GAME_HEADER

#include "SDLUtils.h"
#include "Input.h"
//#include "World.h"
#include "Renderer.h"

class Game{
public:
	Game();

	
	void initTextures();											

	void renderMap();						

	void update(InputState inputState);

	void gameLoop();
private:

	
	SDLUtils* sdlUtils;
	Input* input;
	Renderer* renderer;	
	World* world;


	bool globalRunning;
	SDL_Texture* mapTileTexture = NULL;
	int spriteSize = 32;
	//SDL_Event evnt;
	int tileSize = 32;

	
};

#endif