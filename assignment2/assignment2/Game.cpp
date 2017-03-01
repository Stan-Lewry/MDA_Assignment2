#include "Game.h"

Game::Game(){
	sdlUtils = new SDLUtils();
	globalRunning = sdlUtils->initSDL();
}

void Game::initTextures(){
	mapTileTexture = sdlUtils->loadPNG("Assets/tiles01.png");
}

void Game::initMap(){
	for (int i = 0; i < mapH; i++){
		for (int j = 0; j < mapW; j++){
			mapTile newTile;
			newTile.screenX = j * tileSize;
			newTile.screenY = i * tileSize;
			newTile.typeX = 0;
			newTile.typeY = 0;
			newTile.blocked = false;
			newTile.selected = false;
			newTile.moveRange = false;
			newTile.attackRange = false;
			map[i][j] = newTile;
		}
	}
}

void Game::checkClick(int clickX, int clickY){
	for (int i = 0; i < mapH; i++){
		for (int j = 0; j < mapW; j++){
			map[i][j].selected = false;
			if (clickX > map[i][j].screenX && clickX < map[i][j].screenX + tileSize){
				if (clickY > map[i][j].screenY && clickY < map[i][j].screenY + tileSize){
					map[i][j].selected = true;
				}
			}
		}
	}
}

void Game::handleEvents(){
	while (SDL_PollEvent(&evnt)){
		switch (evnt.type){
		case SDL_QUIT:
			globalRunning = false;
			break;
		case SDL_MOUSEBUTTONDOWN:
			int x, y;
			SDL_GetMouseState(&x, &y);
			checkClick(x, y);
			break;
		default:
			break;
		}
	}
}

void Game::renderMap(){
	SDL_RenderClear(sdlUtils->rend);

	SDL_Rect sRect = { 0, 0, 32, 32 };
	SDL_Rect dRect = { 0, 0, tileSize, tileSize };
	for (int i = 0; i < mapH; i++){
		for (int j = 0; j < mapW; j++){
			dRect.x = map[i][j].screenX;
			dRect.y = map[i][j].screenY;

			sRect.x = map[i][j].typeX;
			sRect.y = map[i][j].typeY;

			SDL_RenderCopy(sdlUtils->rend, mapTileTexture, &sRect, &dRect);

			if (map[i][j].selected == true){
				sRect.y = 9 * 32;
				SDL_RenderCopy(sdlUtils->rend, mapTileTexture, &sRect, &dRect);
			}
		}
	}

	SDL_RenderPresent(sdlUtils->rend);
}

void Game::gameLoop(){
	while (globalRunning){
		handleEvents();
		renderMap();
	}
}