#include "Input.h"

Input::Input(){
	inputState = { false, 0, 0, false };
}

void Input::handleEvents(){
	inputState = { false, 0, 0, false };
	while (SDL_PollEvent(&evnt)){
		switch (evnt.type){
		case SDL_QUIT:
			inputState.quit = true;
			break;
		case SDL_MOUSEBUTTONDOWN:
			inputState.mouseButtonDown = true;
			SDL_GetMouseState(&inputState.mouseX, &inputState.mouseY);
			break;
		default:
			break;
		}
	}
}

InputState Input::getCurrentInputState(){
	return inputState;
}