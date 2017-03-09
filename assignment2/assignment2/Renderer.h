#ifndef RENDERER_HEADER
#define RENDERER_HEADER

#include "SDLUtils.h"
//#include "Game.h"
//#include "World.h"
#include "Character.h"


class Renderer{
public:
	Renderer(SDL_Renderer* _rend);
	void render(mapTile map[mapH][mapW], Character* renderableCharacters1[teamSize], 
		Character* renderableCharacters2[teamSize], Character* currentCharacter, UIElement renderableUIElements[1]);

	void renderCharacters(Character* renderableCharacters[teamSize]);
	void renderUI(UIElement renderableUIElements[1], Character* currentCharacter);
	void renderWorld(mapTile map[mapH][mapW], Character* currentCharacter);
	void initTextures();
	SDL_Texture* loadPNG(char path[]);

	void renderMapBackground();


	int getRenderOffsetX();
	int getRanderOffsetY();

	int getMapSpaceOffset();

	void addOffsetX(int a);
	void addOffsetY(int a);

private:
	SDL_Renderer* rend;
	SDL_Texture* worldSpriteSheet;
	SDL_Texture* characterSpriteSheet;
	SDL_Texture* uiSpriteSheet;
	int spriteSize = 64;
	int tileSize = 64;
	int renderOffsetX = 760;
	int renderOffsetY = 100;


	int mapSpaceOffset = 200;
};

#endif