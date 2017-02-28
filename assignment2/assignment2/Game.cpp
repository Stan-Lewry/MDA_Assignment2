#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <vector>
#include <string>
#include <iostream>

#define screenW 640
#define screenH 480
#define mapW 10
#define mapH 10

SDL_Window* window = NULL;
SDL_Renderer* rend = NULL;

SDL_Texture* mapTileTexture = NULL;


struct mapTile{
	int type;
	bool blocked;
};

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
	for (int i = 0; i < mapW; i++){
		for (int j = 0; j < mapH; j++){
			mapTile newTile = { 0, false };
			map[i][j] = newTile;
		}
	}
}

void renderMap(){
	
}

int main(int argv, char* argc[]){

	init();
	initMap();
	initTextures();

	SDL_Delay(5000);

	

	return 0;
}