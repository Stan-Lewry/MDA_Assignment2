#include <iostream>
#include <fstream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#define screenW 1280
#define screenH 720
#define mapW 15
#define mapH 15
#define tileSize 64
#define spriteSize 32


SDL_Window* window;
SDL_Renderer* rend;
SDL_Texture* tiles;
SDL_Texture* ui;
SDL_Event evnt;

int renderOffsetX = 0; 
int renderOffsetY = 0;

int paletteX = screenW - 340;
int paletteY = 35;

int currentType = 1;

bool gRunning = false;

struct tile{
	int worldX;
	int worldY;
	int screenX;
	int screenY;
	int type;
};

struct paletteButton{
	int x;
	int y;
	int w;
	int h;
	int tileType;
};

struct Button{
	int x, y, w, h;
};

Button trash = { screenW - 108 - 32, screenH - 55 - 32, 32, 32 };
Button save = { 1076, screenH - 55 - 32, 32, 32 };
Button exit_program = { 1012, screenH - 55 - 32, 32, 32 };

tile map[mapH][mapW];

paletteButton paletteButtons[10][10]; 

bool initSDL(){
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();
	IMG_Init(IMG_INIT_PNG);
	window = SDL_CreateWindow("Level Editor", 100, 100, screenW, screenH, SDL_WINDOW_BORDERLESS);
	if (window != NULL){
		printf("Window Initialized\n");
		rend = SDL_CreateRenderer(window, 0, SDL_RENDERER_ACCELERATED);
		if (rend != NULL){
			printf("Renderer Initialized\n");
			return true;
		}
		else{
			return false;
		}
	}
	else{
		return false;
	}
}

SDL_Texture* loadPNG(char* path){
	printf("loading: %s\n", path);
	SDL_Surface* tempSurface = IMG_Load(path);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(rend, tempSurface);
	SDL_FreeSurface(tempSurface);
	printf("Done!\n");
	return texture;
}

void initTextures(){
	tiles = loadPNG("Assets/2d_tiles.png");
	ui = loadPNG("Assets/ui.png");
}

void initMap(){
	for (int i = 0; i < mapH; i++){
		for (int j = 0; j < mapW; j++){
			tile newTile = { j, i, j * tileSize, i * tileSize, 1 };
			map[i][j] = newTile;
		}
	}
}

void initPaletteButtons(){
	int type = 0;
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++){
			paletteButton pb = { j * spriteSize + paletteX, i * spriteSize + paletteY, spriteSize, spriteSize, type };
			paletteButtons[i][j] = pb;
			type++; 
		}
	}
}

void renderSelectedTile(){
	SDL_Rect sRect = { 0, 0, spriteSize, spriteSize };
	SDL_Rect dRect = { screenW - 230, screenH - 295, 100, 100 };
	switch (currentType){
	case 0:
		sRect.x = 0 * spriteSize;
		sRect.y = 0 * spriteSize;
		SDL_RenderCopy(rend, tiles, &sRect, &dRect);
		break;
	case 1:
		sRect.x = 1 * spriteSize;
		sRect.y = 0 * spriteSize;
		SDL_RenderCopy(rend, tiles, &sRect, &dRect);
		break;
	case 2:
		sRect.x = 2 * spriteSize;
		sRect.y = 0 * spriteSize;
		SDL_RenderCopy(rend, tiles, &sRect, &dRect);
		break;
	case 3:
		sRect.x = 3 * spriteSize;
		sRect.y = 0 * spriteSize;
		SDL_RenderCopy(rend, tiles, &sRect, &dRect);
		break;
	case 4:
		sRect.x = 4 * spriteSize;
		sRect.y = 0 * spriteSize;
		SDL_RenderCopy(rend, tiles, &sRect, &dRect);
		break;
	case 5:
		sRect.x = 5 * spriteSize;
		sRect.y = 0 * spriteSize;
		SDL_RenderCopy(rend, tiles, &sRect, &dRect);
		break;
	case 6:
		sRect.x = 6 * spriteSize;
		sRect.y = 0 * spriteSize;
		SDL_RenderCopy(rend, tiles, &sRect, &dRect);
		break;
	case 7:
		sRect.x = 7 * spriteSize;
		sRect.y = 0 * spriteSize;
		SDL_RenderCopy(rend, tiles, &sRect, &dRect);
		break;
	case 8:
		sRect.x = 8 * spriteSize;
		sRect.y = 0 * spriteSize;
		SDL_RenderCopy(rend, tiles, &sRect, &dRect);
		break;
	case 9:
		sRect.x = 9 * spriteSize;
		sRect.y = 0 * spriteSize;
		SDL_RenderCopy(rend, tiles, &sRect, &dRect);
		break;
	case 10:
		sRect.x = 0 * spriteSize;
		sRect.y = 1 * spriteSize;
		SDL_RenderCopy(rend, tiles, &sRect, &dRect);
		break;
	case 11:
		sRect.x = 1 * spriteSize;
		sRect.y = 1 * spriteSize;
		SDL_RenderCopy(rend, tiles, &sRect, &dRect);
		break;
	case 12:
		sRect.x = 2 * spriteSize;
		sRect.y = 1 * spriteSize;
		SDL_RenderCopy(rend, tiles, &sRect, &dRect);
		break;
	case 13:
		sRect.x = 3 * spriteSize;
		sRect.y = 1 * spriteSize;
		SDL_RenderCopy(rend, tiles, &sRect, &dRect);
		break;
	case 14:
		sRect.x = 4 * spriteSize;
		sRect.y = 1 * spriteSize;
		SDL_RenderCopy(rend, tiles, &sRect, &dRect);
		break;
	case 15:
		sRect.x = 5 * spriteSize;
		sRect.y = 1 * spriteSize;
		SDL_RenderCopy(rend, tiles, &sRect, &dRect);
		break;
	case 16:
		sRect.x = 6 * spriteSize;
		sRect.y = 1 * spriteSize;
		SDL_RenderCopy(rend, tiles, &sRect, &dRect);
		break;
	case 20:
		sRect.x = 0 * spriteSize;
		sRect.y = 2 * spriteSize;
		SDL_RenderCopy(rend, tiles, &sRect, &dRect);
		break;
	case 21:
		sRect.x = 1 * spriteSize;
		sRect.y = 2 * spriteSize;
		SDL_RenderCopy(rend, tiles, &sRect, &dRect);
		break;
	case 22:
		sRect.x = 2 * spriteSize;
		sRect.y = 2 * spriteSize;
		SDL_RenderCopy(rend, tiles, &sRect, &dRect);
		break;
	case 23:
		sRect.x = 3 * spriteSize;
		sRect.y = 2 * spriteSize;
		SDL_RenderCopy(rend, tiles, &sRect, &dRect);
		break;
	case 24:
		sRect.x = 4 * spriteSize;
		sRect.y = 2 * spriteSize;
		SDL_RenderCopy(rend, tiles, &sRect, &dRect);
		break;
	case 25:
		sRect.x = 5 * spriteSize;
		sRect.y = 2 * spriteSize;
		SDL_RenderCopy(rend, tiles, &sRect, &dRect);
		break;
	case 26:
		sRect.x = 6 * spriteSize;
		sRect.y = 2 * spriteSize;
		SDL_RenderCopy(rend, tiles, &sRect, &dRect);
		break;
	case 27:
		sRect.x = 7 * spriteSize;
		sRect.y = 2 * spriteSize;
		SDL_RenderCopy(rend, tiles, &sRect, &dRect);
		break;
	case 28:
		sRect.x = 8 * spriteSize;
		sRect.y = 2 * spriteSize;
		SDL_RenderCopy(rend, tiles, &sRect, &dRect);
		break;
	case 29:
		sRect.x = 9 * spriteSize;
		sRect.y = 2 * spriteSize;
		SDL_RenderCopy(rend, tiles, &sRect, &dRect);
		break;
	case 30:
		sRect.x = 0 * spriteSize;
		sRect.y = 3 * spriteSize;
		SDL_RenderCopy(rend, tiles, &sRect, &dRect);
		break;
	case 31:
		sRect.x = 1 * spriteSize;
		sRect.y = 3 * spriteSize;
		SDL_RenderCopy(rend, tiles, &sRect, &dRect);
		break;
	case 32:
		sRect.x = 2 * spriteSize;
		sRect.y = 3 * spriteSize;
		SDL_RenderCopy(rend, tiles, &sRect, &dRect);
		break;
	}
}

void renderMap(){
	SDL_Rect bg = { 0, 0, screenW, screenH };
	SDL_SetRenderDrawColor(rend, 102, 204, 255, 1);
	SDL_RenderFillRect(rend, &bg);

	SDL_Rect sRect = { 0, 0, spriteSize, spriteSize };
	SDL_Rect dRect = { 0, 0, tileSize, tileSize };
	for (int i = 0; i < mapH; i++){
		for (int j = 0; j < mapW; j++){
			//printf("rendering tile\n");

			if (map[i][j].type == 0){
				sRect.x = 0;
				sRect.y = 0;
			}
			if (map[i][j].type == 1){
				sRect.x = 1 * spriteSize;
				sRect.y = 0;
			}
			if (map[i][j].type == 2){
				sRect.x = 2 * spriteSize;
				sRect.y = 0;
			}
			if (map[i][j].type == 3){
				sRect.x = 3 * spriteSize;
				sRect.y = 0;
			}
			if (map[i][j].type == 4){
				sRect.x = 4 * spriteSize;
				sRect.y = 0;
			}
			if (map[i][j].type == 5){
				sRect.x = 5 * spriteSize;
				sRect.y = 0;
			}
			if (map[i][j].type == 6){
				sRect.x = 6 * spriteSize;
				sRect.y = 0;
			}
			if (map[i][j].type == 7){
				sRect.x = 7 * spriteSize;
				sRect.y = 0;
			}
			if (map[i][j].type == 8){
				sRect.x = 8 * spriteSize;
				sRect.y = 0;
			}
			if (map[i][j].type == 9){
				sRect.x = 9 * spriteSize;
				sRect.y = 0;
			}
			if (map[i][j].type == 10){
				sRect.x = 0 * spriteSize;
				sRect.y = 1 * spriteSize;
			}
			if (map[i][j].type == 11){
				sRect.x = 1 * spriteSize;
				sRect.y = 1 * spriteSize;
			}
			if (map[i][j].type == 12){
				sRect.x = 2 * spriteSize;
				sRect.y = 1 * spriteSize;
			}
			if (map[i][j].type == 13){
				sRect.x = 3 * spriteSize;
				sRect.y = 1 * spriteSize;
			}
			if (map[i][j].type == 14){
				sRect.x = 4 * spriteSize;
				sRect.y = 1 * spriteSize;
			}
			if (map[i][j].type == 15){
				sRect.x = 5 * spriteSize;
				sRect.y = 1 * spriteSize;
			}
			if (map[i][j].type == 16){
				sRect.x = 6 * spriteSize;
				sRect.y = 1 * spriteSize;
			}
			if (map[i][j].type == 16){
				sRect.x = 6 * spriteSize;
				sRect.y = 1 * spriteSize;
			}
			if (map[i][j].type == 20){
				sRect.x = 0 * spriteSize;
				sRect.y = 2 * spriteSize;
			}
			if (map[i][j].type == 21){
				sRect.x = 1 * spriteSize;
				sRect.y = 2 * spriteSize;
			}
			if (map[i][j].type == 22){
				sRect.x = 2 * spriteSize;
				sRect.y = 2 * spriteSize;
			}
			if (map[i][j].type == 23){
				sRect.x = 3 * spriteSize;
				sRect.y = 2 * spriteSize;
			}
			if (map[i][j].type == 24){
				sRect.x = 4 * spriteSize;
				sRect.y = 2 * spriteSize;
			}
			if (map[i][j].type == 25){
				sRect.x = 5 * spriteSize;
				sRect.y = 2 * spriteSize;
			}
			if (map[i][j].type == 26){
				sRect.x = 6 * spriteSize;
				sRect.y = 2 * spriteSize;
			}
			if (map[i][j].type == 27){
				sRect.x = 7 * spriteSize;
				sRect.y = 2 * spriteSize;
			}
			if (map[i][j].type == 28){
				sRect.x = 8 * spriteSize;
				sRect.y = 2 * spriteSize;
			}
			if (map[i][j].type == 29){
				sRect.x = 9 * spriteSize;
				sRect.y = 2 * spriteSize;
			}
			if (map[i][j].type == 30){
				sRect.x = 0 * spriteSize;
				sRect.y = 3 * spriteSize;
			}
			if (map[i][j].type == 31){
				sRect.x = 1 * spriteSize;
				sRect.y = 3 * spriteSize;
			}
			if (map[i][j].type == 32){
				sRect.x = 2 * spriteSize;
				sRect.y = 3 * spriteSize;
			}
			dRect.x = map[i][j].screenX + renderOffsetX;
			dRect.y = map[i][j].screenY + renderOffsetY;
			SDL_RenderCopy(rend, tiles, &sRect, &dRect);
		}
	}

}

void renderUI(){
	SDL_Rect sRect = { 0, 0, screenW, screenH };
	SDL_Rect dRect = { 0, 0, screenW, screenH };
	SDL_RenderCopy(rend, ui, &sRect, &dRect);


	sRect = { 0, 0, 320, 320 };
	dRect = {paletteX, paletteY, 320, 320 };
	SDL_RenderCopy(rend, tiles, &sRect, &dRect);
}

void renderAll(){
	SDL_RenderClear(rend);
	renderMap();
	renderUI();
	renderSelectedTile();
	SDL_RenderPresent(rend);
}

void selectTile(int inputX, int inputY){
	for (int i = 0; i < mapH; i++){
		for (int j = 0; j < mapW; j++){
			if (inputX >= map[i][j].screenX + renderOffsetX && inputX < map[i][j].screenX + tileSize + renderOffsetX){
				if (inputY >= map[i][j].screenY + renderOffsetY && inputY < map[i][j].screenY + tileSize + renderOffsetY){
					map[i][j].type = currentType;
				}
			}
		}
	}
}

void exportMap(){
	std::ofstream levelFile;
	levelFile.open("newLevel05.level");

	for (int i = 0; i < mapH; i++){
		for (int j = 0; j < mapW; j++){
			levelFile << map[i][j].type << "\n";
		}
		levelFile << "\n";
	}
	levelFile.close();
}

void clearMap(){
	for (int i = 0; i < mapH; i++){
		for (int j = 0; j < mapW; j++){
			map[i][j].type = 1;
		}
	}
}

bool selectOptionsButton(int inputX, int inputY){
	if (inputX >= save.x && inputX <= save.x + 32 && inputY >= save.y && inputY <= save.y + 32){
		exportMap();
		printf("save button hit\n");
		return true;
	}
	if (inputX >= trash.x && inputX <= trash.x + 32 && inputY >= trash.y && inputY <= trash.y + 32){
		clearMap();
		printf("trash button hit\n");
		return true;
	}
	if (inputX >= exit_program.x && inputX <= exit_program.x + 32 && inputY >= exit_program.y && inputY <= exit_program.y + 32){
		gRunning = false;
		printf("exit program button hit\n");
		return true;
	}
	return false;
}

bool selectPaletteButton(int inputX, int inputY){
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++){
			if (inputX >= paletteButtons[i][j].x && inputX < paletteButtons[i][j].x + spriteSize){
				if (inputY >= paletteButtons[i][j].y && inputY < paletteButtons[i][j].y + spriteSize){
					currentType = paletteButtons[i][j].tileType;
					return true;
				}
			}
		}
	}
	return false; 
}

void handleInputs(){
	while (SDL_PollEvent(&evnt)){
		switch (evnt.type){
		case SDL_QUIT:
			gRunning = false;
			break;
		case SDL_MOUSEBUTTONDOWN:
			int mouseX, mouseY;
			SDL_GetMouseState(&mouseX, &mouseY);
			if (!selectPaletteButton(mouseX, mouseY)){
				if (!selectOptionsButton(mouseX, mouseY)){
					selectTile(mouseX, mouseY);
				}
			}
			//selectTile(mouseX, mouseY);
			break;
		case SDL_KEYDOWN:
			switch (evnt.key.keysym.sym){
			case SDLK_w:
				renderOffsetY += 20;
				break;
			case SDLK_s:
				renderOffsetY -= 20;
				break;
			case SDLK_a:
				renderOffsetX += 20;
				break;
			case SDLK_d:
				renderOffsetX -= 20;
				break;
			default: 
				break;
			}
			break;
		default:
			break;
		}
	}
}


int main(int argv, char* argc[]){
	gRunning = initSDL();
	initTextures();
	initPaletteButtons();
	initMap();

	while (gRunning){
		handleInputs();
		renderAll();
	}
	

	SDL_Quit();
	
	
	
	return 0;
}