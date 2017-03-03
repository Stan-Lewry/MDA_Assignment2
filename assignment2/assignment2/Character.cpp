#include "Character.h"

Character::Character(int _worldX, int _worldY, int _screenX, int _screenY, int _moveRange, int _attkRange){
	worldX = _worldX;
	worldY = _worldY;
	screenX = _screenX;
	screenY = _screenY;
	moveRange = _moveRange;
	attkRange = _attkRange;
	spriteID = 0;
	selected = false;
}

int Character::getWorldX(){
	return worldX;
}
void Character::setWorldX(int _worldX){
	worldX = _worldX;
}
int Character::getWorldY(){
	return worldY;
}
void Character::setWorldY(int _worldY){
	worldY = _worldY;
}
int Character::getScreenX(){
	return screenX;
}
void Character::setScreenX(int _screenX){
	screenX = _screenX;
}
int Character::getScreenY(){
	return screenY;
}
void Character::setScreenY(int _screenY){
	screenY = _screenY;
}
int Character::getMoveRange(){
	return moveRange;
}
int Character::getAttkRange(){
	return attkRange;
}
int Character::getHP(){
	return hp;
}
char* Character::getName(){
	return name;
}

int Character::getSpriteID(){
	return spriteID;
}

bool Character::clickedOn(int x, int y){
	std::cout << "character->clickedOn" << std::endl;
	if (x >= screenX && x < screenX + 64){
		if (y >= screenY && y < screenY + 64){
			return true;
		}
		else return false;
	}
	else return false;
}