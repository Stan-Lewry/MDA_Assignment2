#ifndef CHARACTER_HEADER
#define CHARACTER_HEADER

class Character{
public:
	Character(int _worldX, int _worldY, int _screenX, int _screenY, int _moveRange, int _attkRange);
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


private:
	int worldX;
	int worldY;
	int screenX;
	int screenY;
	int hp;
	char* name;
	int moveRange;
	int attkRange;
}

#endif