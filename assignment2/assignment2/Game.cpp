#include "Game.h"

Game::Game(){
	sdlUtils = new SDLUtils();
	input = new Input();
	globalRunning = sdlUtils->initSDL();
	world = new World();
	world->initMap();
	renderer = new Renderer(sdlUtils->rend);
	initCharacters();
	selectedCharacter = activeCharacterList[0];
}


void Game::initCharacters(){
	activeCharacterList[0] = new Character(2, 7, 2 * tileSize, 7 * tileSize, 3, 1, "knight", 0, 1, 1);
	activeCharacterList[1] = new Character(3, 2, 3 * tileSize, 2 * tileSize, 2, 3, "wizard", 2, 1, 1);

	inactiveCharacterList[0] = new Character(12, 6, 12 * tileSize, 6 * tileSize, 3, 1, "knight", 1, 1, 1);
	inactiveCharacterList[1] = new Character(12, 13, 12 * tileSize, 13 * tileSize, 2, 3, "wizard", 3, 1, 1);
}

void Game::switchCharacterLists(){ //NEEDS FIXING
	Character* tempCharacterList = *activeCharacterList;
	*activeCharacterList = *inactiveCharacterList;
	*inactiveCharacterList = tempCharacterList;
}

void Game::endTurn(){
	for (int i = 0; i < teamSize; i++){
		activeCharacterList[i]->setIdle(false);
		inactiveCharacterList[i]->setIdle(false);
	}
	switchCharacterLists();
	world->clearAll();
}

bool Game::selectCharacter(int mouseX, int mouseY){
	for (int i = 0; i < teamSize; i++){
		if (activeCharacterList[i]->clickedOn(mouseX, mouseY)){
			selectedCharacter = activeCharacterList[i];
			return true;
		}
	}
	return false;
}

void Game::getRanges(Character* c){
	/*
	if (c->getAttkRange() > c->getMoveRange()){
		world->checkAttackRange(c->getAttkRange(), c->getWorldX(), c->getWorldY());
		world->checkMovementRange(c->getMoveRange(), c->getWorldX(), c->getWorldY());
	}
	else{
		world->checkMovementRange(c->getMoveRange(), c->getWorldX(), c->getWorldY());
		world->checkAttackRange(c->getAttkRange(), c->getWorldX(), c->getWorldY());
	}
	*/

	if (c->getMovePoints() > 0){
		world->checkMovementRange(c->getMoveRange(), c->getWorldX(), c->getWorldY());
	}
	if (c->getAttkPoints() > 0){
		world->checkAttackRange(c->getAttkRange(), c->getWorldX(), c->getWorldY());
	}
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
				getRanges(selectedCharacter);
			}
			else{
				world->clearAll();
				world->selectTile(selectedTile.worldX, selectedTile.worldY);
			}
		}
		else if (selectedCharacter != NULL){
			if (selectCharacter(inputState.mouseX, inputState.mouseY)){
				world->clearAll();
				getRanges(selectedCharacter);
			}
			else if (selectedTile.moveRange){
				world->clearAll();
				if (selectedCharacter->getMovePoints() > 0){
					selectedCharacter->moveTo(selectedTile.worldX, selectedTile.worldY);
					if (selectedCharacter->getMovePoints() > 0){
						getRanges(selectedCharacter);
					}
					
				}

				//getRanges(selectedCharacter);
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

	for (int i = 0; i < teamSize; i++){
		if (!activeCharacterList[i]->isIdle() && activeCharacterList[i]->getMovePoints() < 1 && activeCharacterList[i]->getAttkPoints() < 1 ){
			activeCharacterList[i]->setIdle(true);
		}
		if (!inactiveCharacterList[i]->isIdle() && inactiveCharacterList[i]->getMovePoints() < 1 && activeCharacterList[i]->getAttkPoints() < 1){
			inactiveCharacterList[i]->setIdle(true);
		}
	}
	
}



void Game::gameLoop(){
	while (globalRunning){
		input->handleEvents();
		update(input->getCurrentInputState()); 
		//renderMap();
		renderer->render(world->map, activeCharacterList, inactiveCharacterList, selectedCharacter);
		
	}
}