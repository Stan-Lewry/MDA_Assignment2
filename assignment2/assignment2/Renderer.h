#ifndef RENDERER_HEADER
#define RENDERER_HEADER

#include "SDLUtils.h"
//#include "Game.h"
#include "World.h"
class Renderer{
public:
	Renderer(SDL_Renderer* _rend, SDL_Texture* _worldSpriteSheet);
	void render(mapTile map[mapH][mapW]);
	void renderCharacters();
	void renderUI();
	void renderWorld(mapTile map[mapH][mapW]);

private:
	SDL_Renderer* rend;
	SDL_Texture* worldSpriteSheet;
	int spriteSize = 32;
	int tileSize = 32;
};

#endif