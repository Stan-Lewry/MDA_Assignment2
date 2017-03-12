#include "Game.h"

Game::Game(){
	sdlUtils = new SDLUtils();
	input = new Input();
	globalRunning = sdlUtils->initSDL();
	world = new World();
	//world->initBlankMap();
	//world->initMap();
	world->loadMap("Levels/newLevel02.level");
	renderer = new Renderer(sdlUtils->rend);
	ui = new UI();
	ui->initMainMenuElements();
	initCharacters();
	selectedCharacter = activeCharacterList[0];
}


void Game::initCharacters(){
	activeCharacterList[0] = new Character(2, 7, 2 * tileSize, 7 * tileSize, 0, KNIGHT, "Blue Knight");
	activeCharacterList[1] = new Character(3, 2, 3 * tileSize, 2 * tileSize,  2, WIZARD, "Blue Wizard");
	activeCharacterList[2] = new Character(2, 13, 2 * tileSize, 13 * tileSize, 4, FIGHTER, "Blue Fighter");

	inactiveCharacterList[0] = new Character(13, 6, 13 * tileSize, 6 * tileSize, 1, KNIGHT, "Red Knight");
	inactiveCharacterList[1] = new Character(12, 13, 12 * tileSize, 13 * tileSize, 3, WIZARD, "Red Wizard");
	inactiveCharacterList[2] = new Character(9, 12, 9 * tileSize, 12 * tileSize, 5, FIGHTER, "Red Fighter");
}

void Game::switchCharacterLists(){ //NEEDS FIXING
	//Character* tempCharacterList[teamSize] = activeCharacterList;
	//activeCharacterList = inactiveCharacterList;
	//inactiveCharacterList = tempCharacterList;
	std::swap(activeCharacterList, inactiveCharacterList);
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
		if (activeCharacterList[i]->clickedOn(mouseX, mouseY, renderer->getRenderOffsetX(), renderer->getRanderOffsetY()) && activeCharacterList[i]->isDead() == false){
			selectedCharacter = activeCharacterList[i];
			return true;
		}
	}
	return false;
}

void Game::getRanges(Character* c){

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

	if (currentState == GAMEPLAY){
		if (inputState.mouseButtonDown){
			mapTile selectedTile = world->getTile(inputState.mouseX, inputState.mouseY, renderer->getRenderOffsetX(),renderer->getRanderOffsetY() );
				
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

		if (inputState.up){
			renderer->addOffsetY(scrollSpeed);
		}
		if (inputState.down){
			renderer->addOffsetY(-scrollSpeed);
		}
		if (inputState.left){
			renderer->addOffsetX(scrollSpeed);
		}
		if (inputState.right){
			renderer->addOffsetX(-scrollSpeed);
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
	else if (currentState == MAINMENU){

		ui->hover(input->getCurrentInputState().mouseX, input->getCurrentInputState().mouseY);

		if (input->getCurrentInputState().mouseButtonDown){
			if (ui->getAction(input->getCurrentInputState().mouseX, input->getCurrentInputState().mouseY) == CHANGESTATE_GAMEPLAY){
				changeState(GAMEPLAY);
			}
			else if (ui->getAction(input->getCurrentInputState().mouseX, input->getCurrentInputState().mouseY) == QUIT){
				globalRunning = false;
			}
		}

	}
	
}


void Game::changeState(GameState newState){
	if (newState == GAMEPLAY){
		ui->initGameplayElements();
		currentState = GAMEPLAY;
	}
	else if (newState == MAINMENU){
		//do the shit when needed;
	}
}


void Game::gameLoop(){
	//world->loadMap("Levels/test.level");


	//ui->initGameplayElements();



	while (globalRunning){

		oldTime = currentTime;
		currentTime = SDL_GetTicks();
		ftime = (currentTime - oldTime) / 1000.0f;
	
		frames++;
		timer += ftime;
		if (timer > 1){
			std::cout << frames << std::endl;
			frames = 0;
			timer = 0;
		}


		input->handleEvents();
		update(input->getCurrentInputState()); 
		//renderMap();
		if (currentState == GAMEPLAY){
			renderer->renderGame(world->map, activeCharacterList, inactiveCharacterList, selectedCharacter, ui->getElementList(), input->getCurrentInputState().mouseX, input->getCurrentInputState().mouseY);
		}
		else if (currentState == MAINMENU){
			renderer->renderMainMenu(ui->getElementList(), input->getCurrentInputState().mouseX, input->getCurrentInputState().mouseY);
		}
	}
}