#ifndef WORLD_HEADER
#define WORLD_HEADER

#include "SDLUtils.h"


class World{
public:	
	mapTile map[mapH][mapH];
	//World();
	mapTile* getMap();
	void initMap();
	bool isTraversable(int x, int y);
	void checkMovementRange(int moveDist, int originX, int originY);
	void checkAttackRange(int attackDist, int originX, int originY);
	void selectTile(int worldX, int worldY);
	mapTile getTile(int clickX, int clickY, int renderOffsetX, int renderOffsetY);
	void clearAll();
	void loadMap();


private:

	int spriteSize = 32;
	int tileSize = 64;
};


#endif