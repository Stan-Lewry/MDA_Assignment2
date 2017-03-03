#ifndef GAME_HEADER
#define GAME_HEADER

#include "SDLUtils.h"
#include "Input.h"
//#include "World.h"
#include "Renderer.h"
#include "Character.h"

class Game{
public:
	Game();

	
	void initCharacters();

	void update(InputState inputState);

	void gameLoop();
private:

	
	SDLUtils* sdlUtils;
	Input* input;
	Renderer* renderer;	
	World* world;
	Character* characterList[1];
	

	bool globalRunning;
	SDL_Texture* mapTileTexture = NULL;
	int spriteSize = 32;
	//SDL_Event evnt;
	int tileSize = 64;

	
};

#endif