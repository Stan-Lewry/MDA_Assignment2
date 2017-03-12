#include "Character.h"

Character::Character(int _worldX, int _worldY, int _screenX, int _screenY, int _spriteID, Profession _profession, char* _name) {
	worldX = _worldX;
	worldY = _worldY;
	screenX = (worldX - worldY) * 128 / 2;
	screenY = (worldX + worldY) * 128 / 4;
	spriteID = _spriteID;
	name = _name;
	selected = false;
	dead = false;
	animationFrame = 2;

	profession = _profession;
	
	switch (profession){
	case KNIGHT:
		hp = 100;
		movePoints = 1;
		attkPoints = 1;
		moveRange = 2;
		attkRange = 1;

		armour = 12;
		attk = 15;
		break;
	case WIZARD:
		hp = 70;
		movePoints = 1;
		attkPoints = 2;
		moveRange = 3;
		attkRange = 5;

		armour = 8;
		attk = 15;
		break;
	case FIGHTER:
		hp = 50;
		movePoints = 2;
		attkPoints = 1;
		moveRange = 5;
		attkRange = 1;

		armour = 6;
		attk = 20;
		break;
	default:
		break;
	}
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
		animationFrame = 1;
	}
	else{
		movePoints = 1;
		attkPoints = 1;
		idle = false;
		animationFrame = 2;
	}
	

}


void Character::setDead(bool d){
	dead = d;
	animationFrame = 0;
}

bool Character::isDead(){
	return dead;
}

bool Character::clickedOn(int x, int y, int rendererOffsetX, int rendererOffsetY){
	std::cout << "character->clickedOn" << std::endl;
	if (x >= screenX + rendererOffsetX && x < screenX + rendererOffsetX + 128){
		if (y >= screenY + rendererOffsetY && y < screenY + rendererOffsetY + 128){
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
	screenX = (worldX - worldY) * 128 / 2;
	screenY = (worldX + worldY) * 128 / 4;
	movePoints -= 1;
	//attkPoints -= 1; //TEMPORARY _ FOR TESTING PURPOSES ONLY
}