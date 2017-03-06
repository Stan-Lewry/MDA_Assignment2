#include "Character.h"

Character::Character(int _worldX, int _worldY, int _screenX, int _screenY, int _moveRange, int _attkRange, char* _name, int _spriteID, int _movePoints, int _attkPoints){
	worldX = _worldX;
	worldY = _worldY;
	screenX = _screenX;
	screenY = _screenY;
	moveRange = _moveRange;
	attkRange = _attkRange;
	name = _name;
	spriteID = _spriteID;
	attkPoints = _attkPoints;
	movePoints = _movePoints;
	selected = false;

	animationFrame = 1;
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

int Character::getMovePoints(){
	return movePoints;
}

void Character::setMovePoints(int p){
	movePoints = p;
}

int Character::getAttkPoints(){
	return attkPoints;
}

void Character::setAttkPoints(int p){
	attkPoints = p;
}

int Character::getAnimationFrame(){
	return animationFrame;
}

void Character::setAnimationFrame(int frame){
	animationFrame = frame;
}

bool Character::isIdle(){
	return idle;
}

void Character::setIdle(bool i){
	if (i == true){
		idle = true;
		animationFrame = 0;
	}
	else{
		idle = false;
		animationFrame = 1;
	}
	

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

void Character::moveTo(int _worldX, int _worldY){

	std::cout << "moving character to" << _worldX << "," << _worldY << std::endl;
	worldX = _worldX;
	worldY = _worldY;
	screenX = worldX * 64;
	screenY = worldY * 64;
	movePoints -= 1;
	attkPoints -= 1; //TEMPORARY _ FOR TESTING PURPOSES ONLY
}