#include "Game.h"

Game::Game(){
	sdlUtils = new SDLUtils();
	input = new Input();
	globalRunning = sdlUtils->initSDL();
	world = new World();
	world->initMap();
	renderer = new Renderer(sdlUtils->rend);
	initCharacters();
	selectedCharacter = NULL;
}


void Game::initCharacters(){
	activeCharacterList[0] = new Character(2, 7, 2 * tileSize, 7 * tileSize, 3, 1, "knight");
	inactiveCharacterList[0] = new Character(12, 6, 12 * tileSize, 7 * tileSize, 3, 1, "knight");
}

void Game::switchCharacterLists(){
	Character* tempCharacterList = *activeCharacterList;
	*activeCharacterList = *inactiveCharacterList;
	*inactiveCharacterList = tempCharacterList;
}

void Game::endTurn(){
	switchCharacterLists();
}

bool Game::selectCharacter(int mouseX, int mouseY){
	for (int i = 0; i < 1; i++){
		if (activeCharacterList[i]->clickedOn(mouseX, mouseY)){
			selectedCharacter = activeCharacterList[i];
			return true;
		}
	}
	return false;
}

void Game::update(InputState inputState){
	
	if (inputState.quit){
		globalRunning = false;
	}
	else if (inputState.mouseButtonDown){
		mapTile selectedTile = world->getTile(inputState.mouseX, inputState.mouseY);

		if (selectedCharacter == NULL){
			if (selectCharacter(inputState.mouseX, inputState.mouseY)){
				world->clearAll();
				world->checkMovementRange(selectedCharacter->getMoveRange(), selectedCharacter->getWorldX(), selectedCharacter->getWorldY());
				world->checkAttackRange(selectedCharacter->getAttkRange(), selectedCharacter->getWorldX(), selectedCharacter->getWorldY());
			}
			else{
				world->clearAll();
				world->selectTile(selectedTile.worldX, selectedTile.worldY);
			}
		}
		else if (selectedCharacter != NULL){
			if (selectCharacter(inputState.mouseX, inputState.mouseY)){
				world->clearAll();
				world->checkMovementRange(selectedCharacter->getMoveRange(), selectedCharacter->getWorldX(), selectedCharacter->getWorldY());
				world->checkAttackRange(selectedCharacter->getAttkRange(), selectedCharacter->getWorldX(), selectedCharacter->getWorldY());
			}
			else if (selectedTile.moveRange){
				world->clearAll();
				selectedCharacter->moveTo(selectedTile.worldX, selectedTile.worldY);
				world->checkMovementRange(selectedCharacter->getMoveRange(), selectedCharacter->getWorldX(), selectedCharacter->getWorldY());
				world->checkAttackRange(selectedCharacter->getAttkRange(), selectedCharacter->getWorldX(), selectedCharacter->getWorldY());
			}
			else{
				world->clearAll();
				world->selectTile(selectedTile.worldX, selectedTile.worldY);
			}
		}
		
	}
	else if (inputState.space){
		endTurn();
	}
	
}



void Game::gameLoop(){
	while (globalRunning){
		input->handleEvents();
		update(input->getCurrentInputState()); 
		//renderMap();
		renderer->render(world->map, activeCharacterList, inactiveCharacterList);
		
	}
}