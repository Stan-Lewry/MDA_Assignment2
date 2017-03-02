#include "Renderer.h"

Renderer::Renderer(SDL_Renderer* _rend, SDL_Texture* _worldSpriteSheet){
	rend = _rend;
	worldSpriteSheet = _worldSpriteSheet;
}

void Renderer::render(mapTile map[mapH][mapW]){
	SDL_RenderClear(rend);
	renderWorld(map);
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
				sRect.y = 1 * tileSize;
				sRect.x = 7 * tileSize;
				SDL_RenderCopy(rend, worldSpriteSheet, &sRect, &dRect);
			}
			else if (map[i][j].moveRange){
				sRect.y = 1 * tileSize;
				sRect.x = 9 * tileSize;
				SDL_RenderCopy(rend, worldSpriteSheet, &sRect, &dRect);
			}
		}
	}
}