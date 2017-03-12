#include "Renderer.h"

Renderer::Renderer(SDL_Renderer* _rend){
	rend = _rend;
	//worldSpriteSheet = _worldSpriteSheet;
	//worldSpriteSheet = loadPNG("Assets/tiles01.png");
	initTextures();
}

void Renderer::renderGame(mapTile map[mapH][mapW], Character* renderableCharacters1[teamSize], Character* renderableCharacters2[teamSize], Character* currentCharacter, UIElement renderableUIElements[1], int mouseX, int mouseY){
	SDL_RenderClear(rend);
	renderMapBackground();
	renderWorld(map, currentCharacter);
	renderCharacters(renderableCharacters1);
	renderCharacters(renderableCharacters2); 
	renderUI(renderableUIElements, currentCharacter);
	renderCursor(mouseX, mouseY);
	SDL_RenderPresent(rend);
}

void Renderer::renderWorld(mapTile map[mapH][mapW], Character* currentCharacter){
	SDL_Rect sRect = { 0, 0, spriteSize, spriteSize };
	SDL_Rect dRect = { 0, 0, tileSize, tileSize };
	
	for (int i = 0; i < mapH; i++){
		for (int j = 0; j < mapW; j++){
			dRect.x = map[i][j].screenX + renderOffsetX;
			dRect.y = map[i][j].screenY + renderOffsetY;
			sRect.x = map[i][j].typeX;
			sRect.y = map[i][j].typeY;
			SDL_RenderCopy(rend, worldSpriteSheet, &sRect, &dRect); 


			if (currentCharacter->getAttkRange() > currentCharacter->getMoveRange()){
				if (map[i][j].moveRange){

					sRect.y = 1 * spriteSize;
					sRect.x = 9 * spriteSize;
					SDL_RenderCopy(rend, worldSpriteSheet, &sRect, &dRect);
				}
				else if (map[i][j].attackRange){

					sRect.y = 1 * spriteSize;
					sRect.x = 8 * spriteSize;
					SDL_RenderCopy(rend, worldSpriteSheet, &sRect, &dRect);
				}
			}
			else if (currentCharacter->getAttkRange() < currentCharacter->getMoveRange()){
				if (map[i][j].moveRange){
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

			if (map[i][j].selected){
				sRect.y = 1 * spriteSize;
				sRect.x = 7 * spriteSize;
				SDL_RenderCopy(rend, worldSpriteSheet, &sRect, &dRect);
			}
		}
	}
}

void Renderer::renderCharacters(Character* renderableCharacters[teamSize]){
	//std::cout << "render characters called" << std::endl;
	for (int i = 0; i < teamSize; i++){
		SDL_Rect sRect = { renderableCharacters[i]->getAnimationFrame() * spriteSize, renderableCharacters[i]->getSpriteID() * spriteSize, spriteSize, spriteSize };
		SDL_Rect dRect = { renderableCharacters[i]->getScreenX() + renderOffsetX, renderableCharacters[i]->getScreenY() + renderOffsetY, tileSize, tileSize };
		SDL_RenderCopy(rend, characterSpriteSheet, &sRect, &dRect);
	}
}

void Renderer::renderUI(UIElement renderableUIElements[1], Character* currentCharacter){
	SDL_Rect sRect;
	SDL_Rect dRect;
	for (int i = 0; i < 1; i++){
		sRect = { renderableUIElements[i].sourceX, renderableUIElements[i].sourceY, renderableUIElements[i].width, renderableUIElements[i].height };
		dRect = { renderableUIElements[i].screenX, renderableUIElements[i].screenY, renderableUIElements[i].width, renderableUIElements[i].height };
		SDL_RenderCopy(rend, uiSpriteSheet, &sRect, &dRect);
	}

	sRect = { 2 * spriteSize, currentCharacter->getSpriteID() * spriteSize, spriteSize, spriteSize };
	dRect = { 75, 70, 150, 150 };
	SDL_RenderCopy(rend, characterSpriteSheet, &sRect, &dRect);
}


void Renderer::renderMapBackground(){
	SDL_Rect dRect = { 0, 0, screenW, screenH };
	SDL_SetRenderDrawColor(rend, 102, 204, 255, 1);
	SDL_RenderFillRect(rend, &dRect);
}


void Renderer::renderCursor(int mouseX, int mouseY){
	SDL_Rect sRect = { 300, 0, 64, 64 };
	SDL_Rect dRect = { mouseX, mouseY, 32, 32 };
	SDL_RenderCopy(rend, uiSpriteSheet, &sRect, &dRect);

}


void Renderer::renderMainMenu(UIElement renderableUIElements[4], int mouseX, int mouseY){
	
	SDL_RenderClear(rend);

	SDL_Rect bgSource = { 0, 0, screenW, screenH };
	SDL_Rect bgDest = { 0, 0, screenW, screenH };
	SDL_RenderCopy(rend, titleScreen, &bgSource, &bgDest);

	SDL_Rect sRect, dRect;
	for (int i = 0; i < 4; i++){
		if (renderableUIElements[i].hover){
			sRect = { renderableUIElements[i].sourceX + 300, renderableUIElements[i].sourceY, renderableUIElements[i].width, renderableUIElements[i].height };
		}
		else{
			sRect = { renderableUIElements[i].sourceX, renderableUIElements[i].sourceY, renderableUIElements[i].width, renderableUIElements[i].height };
		}
		dRect = { renderableUIElements[i].screenX, renderableUIElements[i].screenY, renderableUIElements[i].width, renderableUIElements[i].height };
		SDL_RenderCopy(rend, mainMenuButtons, &sRect, &dRect);
	}
	
	renderCursor(mouseX, mouseY);

	SDL_RenderPresent(rend);
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
	worldSpriteSheet = loadPNG("Assets/iso_tiles.png");
	characterSpriteSheet = loadPNG("Assets/characters_large.png");
	uiSpriteSheet = loadPNG("Assets/ui.png");
	titleScreen = loadPNG("Assets/title_screen.png");
	mainMenuButtons = loadPNG("Assets/main_menu_buttons.png");
}

int Renderer::getRenderOffsetX(){
	return renderOffsetX;
}

int Renderer::getRanderOffsetY(){
	return renderOffsetY;
}

void Renderer::addOffsetX(int a){
	renderOffsetX += a;
}

void Renderer::addOffsetY(int a){
	renderOffsetY += a;
}

int Renderer::getMapSpaceOffset(){
	return mapSpaceOffset;
}