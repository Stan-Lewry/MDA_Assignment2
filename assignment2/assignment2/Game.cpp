#include "Game.h"

Game::Game(){
	sdlUtils = new SDLUtils();
	input = new Input();
	globalRunning = sdlUtils->initSDL();
	world = new World();
	world->initMap();
	renderer = new Renderer(sdlUtils->rend, sdlUtils->loadPNG("Assets/tiles01.png"));
}

void Game::initTextures(){
	mapTileTexture = sdlUtils->loadPNG("Assets/tiles01.png");
}






void Game::update(InputState inputState){
	if (inputState.quit == true){
		globalRunning = false;
	}
	else if (inputState.mouseButtonDown == true){
		//clearSelection();
		//checkClick(inputState.mouseX, inputState.mouseY);
		world->selectTile(inputState.mouseX, inputState.mouseY);
	}
}

void Game::renderMap(){

	
	SDL_RenderClear(sdlUtils->rend);

	SDL_Rect sRect = { 0, 0, 32, 32 };
	SDL_Rect dRect = { 0, 0, tileSize, tileSize };
	for (int i = 0; i < mapH; i++){
		for (int j = 0; j < mapW; j++){
			dRect.x = world->map[i][j].screenX;
			dRect.y = world->map[i][j].screenY;

			sRect.x = world->map[i][j].typeX;
			sRect.y = world->map[i][j].typeY;

			SDL_RenderCopy(sdlUtils->rend, mapTileTexture, &sRect, &dRect);

			if (world->map[i][j].selected == true){
				sRect.y = 1 * spriteSize;
				sRect.x = 7 * spriteSize;
				SDL_RenderCopy(sdlUtils->rend, mapTileTexture, &sRect, &dRect);
			}
			else if (world->map[i][j].moveRange == true){
				sRect.y = 1 * 32;
				sRect.x = 7 * spriteSize;
				SDL_RenderCopy(sdlUtils->rend, mapTileTexture, &sRect, &dRect);
			}
		}
	}

	SDL_RenderPresent(sdlUtils->rend);
}

void Game::gameLoop(){
	while (globalRunning){
		input->handleEvents();
		update(input->getCurrentInputState()); 
		//renderMap();
		renderer->render(world->map);
	}
}