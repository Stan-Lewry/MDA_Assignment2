#ifndef CHARACTER_HEADER
#define CHARACTER_HEADER
#include <iostream>
//#include "SDLUtils.h"

enum Profession{KNIGHT, WIZARD, FIGHTER};

class Character{
public:
	Character(int _worldX, int _worldY, int _screenX, int _screenY, int _spriteID, Profession _profession, char* _name);
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

	void setDead(bool d);
	bool isDead();
private:
	int worldX;
	int worldY;
	int screenX;
	int screenY;
	
	
	char* name;
	int animationFrame;
	bool dead;
	bool idle;
	int spriteID;
	bool selected;

	Profession profession;

	int hp;

	int movePoints;
	int maxMovePoints;
	int attkPoints;
	int maxAttkPoints;
	int moveRange;
	int maxMoveRange;
	int attkRange;
	int maxAttkRange;

	int armour;
	int attk;
	


};

#endif