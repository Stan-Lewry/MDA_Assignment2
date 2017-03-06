#ifndef RENDERER_HEADER
#define RENDERER_HEADER

#include "SDLUtils.h"
//#include "Game.h"
#include "World.h"
#include "Character.h"
class Renderer{
public:
	Renderer(SDL_Renderer* _rend);
	void render(mapTile map[mapH][mapW], Character* renderableCharacters1[teamSize], Character* renderableCharacters2[teamSize], Character* currentCharacter);
	void renderCharacters(Character* renderableCharacters[teamSize]);
	void renderUI();
	void renderWorld(mapTile map[mapH][mapW], Character* currentCharacter);
	void initTextures();
	SDL_Texture* loadPNG(char path[]);

private:
	SDL_Renderer* rend;
	SDL_Texture* worldSpriteSheet;
	SDL_Texture* characterSpriteSheet;
	int spriteSize = 32;
	int tileSize = 64;
};

#endif