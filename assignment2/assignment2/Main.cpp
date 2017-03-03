
#include "Game.h"




Game* game;


int main(int argv, char* argc[]){

	game = new Game();


	//game->initMap();
	
	//game->buildMapFromTypes();
	//game->initTextures();

	game->gameLoop();

	return 0;
}