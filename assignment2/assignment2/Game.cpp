#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <vector>
#include <string>
#include <iostream>

#define screenW 640
#define screenH 480
//#define mapW 10
//#define mapH 10

const int mapW = 15;
const int mapH = 15;
const int mapSize = mapW * mapH;

bool globalRunning;

SDL_Window* window = NULL;
SDL_Renderer* rend = NULL;

SDL_Texture* mapTileTexture = NULL;

SDL_Event evnt;

struct mapTile{
	int screenX;
	int screenY;
	int typeX;
	int typeY;
	bool blocked;
	bool selected;
	bool moveRange;
	bool attackRange;
};


int tileSize = 32;
mapTile map[mapW][mapH];

void init(){
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();
	IMG_Init(IMG_INIT_PNG);
	window = SDL_CreateWindow("Assignment 2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenW, screenH, SDL_WINDOW_SHOWN);
	if (window != NULL){
		printf("Window Initialized\n");
		rend = SDL_CreateRenderer(window, 0, SDL_RENDERER_ACCELERATED);
		if (rend != NULL){
			printf("Renderer Initialized\n");
		}
	}
	globalRunning = true;
}

SDL_Texture* loadPNG(char path[]){
	printf("loading: %s\n", path);
	SDL_Surface* tempSurface = IMG_Load(path);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(rend, tempSurface);
	SDL_FreeSurface(tempSurface);
	printf("Done!\n");
	return texture;
}

void initTextures(){
	mapTileTexture = loadPNG("Assets/tiles01.png");
}

void initMap(){
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

void checkClick(int clickX, int clickY){
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

void handleEvents(){
	while (SDL_PollEvent(&evnt)){
		switch(evnt.type){
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


void renderMap(){

	SDL_RenderClear(rend);

	SDL_Rect sRect = { 0, 0, 32, 32 };
	SDL_Rect dRect = { 0, 0, tileSize, tileSize };
	for (int i = 0; i < mapH; i++){
		for (int j = 0; j < mapW; j++){
			dRect.x = map[i][j].screenX;
			dRect.y = map[i][j].screenY;

			sRect.x = map[i][j].typeX;
			sRect.y = map[i][j].typeY;

			SDL_RenderCopy(rend, mapTileTexture, &sRect, &dRect);

			if (map[i][j].selected == true){
				sRect.y = 9 * 32;
				SDL_RenderCopy(rend, mapTileTexture, &sRect, &dRect);
			}
		}
	}

	SDL_RenderPresent(rend);
}

int main(int argv, char* argc[]){

	init();
	initMap();
	initTextures();


	while (globalRunning){
		handleEvents();
		renderMap();
	}

	return 0;
}