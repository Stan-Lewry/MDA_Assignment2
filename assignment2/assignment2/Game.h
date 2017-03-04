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
	bool selectCharacter(int mouseX, int mouseY);
	void update(InputState inputState);
	void switchCharacterLists();
	void endTurn();
	void gameLoop();
private:

	
	SDLUtils* sdlUtils;
	Input* input;
	Renderer* renderer;	
	World* world;
	Character* activeCharacterList[1];
	Character* inactiveCharacterList[1];
	Character* selectedCharacter;

	bool globalRunning;
	SDL_Texture* mapTileTexture = NULL;
	int spriteSize = 32;
	//SDL_Event evnt;
	int tileSize = 64;

	
};

#endif