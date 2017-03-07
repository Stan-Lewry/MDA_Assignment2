#ifndef CHARACTER_HEADER
#define CHARACTER_HEADER
//#include <iostream>
#include "SDLUtils.h"

class Character{
public:
	Character(int _worldX, int _worldY, int _screenX, int _screenY, int _moveRange, int _attkRange, char* _name, int _spriteID, int _movePoints, int _attkPoints);
	int getWorldX();
	void setWorldX(int _worldX);
	int getWorldY();
	void setWorldY(int _worldY);
	int getScreenX();
	void setScreenX(int _screenX);
	int getScreenY();
	void setScreenY(int _screenY);
	int getMoveRange();
	int getAttkRange();
	int getHP();
	char* getName();
	int getSpriteID();
	int getMovePoints();
	void setMovePoints(int p);
	int getAttkPoints();
	void setAttkPoints(int p);

	int getAnimationFrame();
	void setAnimationFrame(int frame);

	bool isIdle();
	void setIdle(bool i);
	
	void moveTo(int _worldX, int _worldY);

	bool clickedOn(int x, int y, int renderOffsetX, int renderOffsetY);



private:
	int worldX;
	int worldY;
	int screenX;
	int screenY;
	int hp;

	int movePoints;
	int attkPoints;

	char* name;
	int moveRange;
	int attkRange;
	int spriteID;
	bool selected;

	int animationFrame;

	bool idle;
};

#endif