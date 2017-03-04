#ifndef CHARACTER_HEADER
#define CHARACTER_HEADER

#include "SDLUtils.h"

class Character{
public:
	Character(int _worldX, int _worldY, int _screenX, int _screenY, int _moveRange, int _attkRange, char* _name);
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

	void moveTo(int _worldX, int _worldY);

	bool clickedOn(int x, int y);

private:
	int worldX;
	int worldY;
	int screenX;
	int screenY;
	int hp;

	//int movePoints;
	//int attkPoints;

	char* name;
	int moveRange;
	int attkRange;
	int spriteID;
	bool selected;
};

#endif