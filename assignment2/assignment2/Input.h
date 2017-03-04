#ifndef INPUT_HEADER
#define INPUT_HEADER

#include "SDLUtils.h"

struct InputState{
	bool mouseButtonDown;
	int mouseX;
	int mouseY;
	bool quit;
	bool space;
};


class Input{
public:
	Input();
	void handleEvents();
	InputState getCurrentInputState();

private:
	SDL_Event evnt;
	InputState inputState;

};

#endif