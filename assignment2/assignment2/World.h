#ifndef WORLD_HEADER
#define WORLD_HEADER

#include "SDLUtils.h"
struct mapTile{
	int screenX;
	int screenY;
	int worldX;
	int worldY;
	int typeX;
	int typeY;
	bool blocked;
	bool selected;
	bool moveRange;
	bool attackRange;
};

class World{
public:	
	mapTile map[mapH][mapH];
	//World();
	mapTile* getMap();
	void initMap();
	bool isTraversable(int x, int y);
	void checkMovementRange(int moveDist, int originX, int originY);
	void checkAttackRange(int attackDist, int originX, int originY);
	mapTile selectTile(int clickX, int clickY);
	void loadMap();
private:

	int spriteSize = 32;
	int tileSize = 64;
};


#endif