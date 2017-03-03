#include "Game.h"

Game::Game(){
	sdlUtils = new SDLUtils();
	input = new Input();
	globalRunning = sdlUtils->initSDL();
	world = new World();
	world->initMap();
	//renderer = new Renderer(sdlUtils->rend, sdlUtils->loadPNG("Assets/tiles01.png"));
	renderer = new Renderer(sdlUtils->rend);
	initCharacters();
}


void Game::initCharacters(){
	characterList[0] = new Character(2, 7, 2 * tileSize, 7 * tileSize, 3, 1);
}

void Game::update(InputState inputState){
	if (inputState.quit == true){
		globalRunning = false;
	}
	else if (inputState.mouseButtonDown == true){
		//clearSelection();
		//checkClick(inputState.mouseX, inputState.mouseY);
		world->selectTile(inputState.mouseX, inputState.mouseY);
		for (int i = 0; i < 1; i++){
			if (characterList[i]->clickedOn(inputState.mouseX, inputState.mouseY)){
				std::cout << "clicked on character" << std::endl;
				world->checkAttackRange(characterList[i]->getAttkRange(), characterList[i]->getWorldX(), characterList[i]->getWorldY());				
				world->checkMovementRange(characterList[i]->getMoveRange(), characterList[i]->getWorldX(), characterList[i]->getWorldY());

			}
		}
	}
}



void Game::gameLoop(){
	while (globalRunning){
		input->handleEvents();
		update(input->getCurrentInputState()); 
		//renderMap();
		renderer->render(world->map, characterList);
	}
}