#include "Renderer.h"

Renderer::Renderer(SDL_Renderer* _rend){
	rend = _rend;
	//worldSpriteSheet = _worldSpriteSheet;
	//worldSpriteSheet = loadPNG("Assets/tiles01.png");
	initTextures();
}

void Renderer::render(mapTile map[mapH][mapW], Character* renderableCharacters[1]){
	SDL_RenderClear(rend);
	renderWorld(map);
	renderCharacters(renderableCharacters);
	SDL_RenderPresent(rend);
}

void Renderer::renderWorld(mapTile map[mapH][mapW]){
	SDL_Rect sRect = { 0, 0, spriteSize, spriteSize };
	SDL_Rect dRect = { 0, 0, tileSize, tileSize };
	for (int i = 0; i < mapH; i++){
		for (int j = 0; j < mapW; j++){
			dRect.x = map[i][j].screenX;
			dRect.y = map[i][j].screenY;
			sRect.x = map[i][j].typeX;
			sRect.y = map[i][j].typeY;
			SDL_RenderCopy(rend, worldSpriteSheet, &sRect, &dRect);
			if (map[i][j].selected){
				sRect.y = 1 * spriteSize;
				sRect.x = 7 * spriteSize;
				SDL_RenderCopy(rend, worldSpriteSheet, &sRect, &dRect);
			}
			else if (map[i][j].moveRange){
				sRect.y = 1 * spriteSize;
				sRect.x = 9 * spriteSize;
				SDL_RenderCopy(rend, worldSpriteSheet, &sRect, &dRect);
			}
			if (map[i][j].attackRange){
				sRect.y = 1 * spriteSize;
				sRect.x = 8 * spriteSize;
				SDL_RenderCopy(rend, worldSpriteSheet, &sRect, &dRect);
			}
		}
	}
}

void Renderer::renderCharacters(Character* renderableCharacters[1]){
	//std::cout << "render characters called" << std::endl;
	for (int i = 0; i < 1; i++){
		SDL_Rect sRect = { 0, renderableCharacters[i]->getSpriteID(), spriteSize, spriteSize };
		SDL_Rect dRect = { renderableCharacters[i]->getScreenX(), renderableCharacters[i]->getScreenY(), tileSize, tileSize };
		SDL_RenderCopy(rend, characterSpriteSheet, &sRect, &dRect);
	}
}

SDL_Texture* Renderer::loadPNG(char path[]){
	printf("loading: %s\n", path);
	SDL_Surface* tempSurface = IMG_Load(path);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(rend, tempSurface);
	SDL_FreeSurface(tempSurface);
	printf("Done!\n");
	return texture;
}

void Renderer::initTextures(){
	worldSpriteSheet = loadPNG("Assets/tiles01.png");
	characterSpriteSheet = loadPNG("Assets/knight.png");
}