#include "Input.h"

Input::Input(){
	inputState = { false, 0, 0, false, false };
}

void Input::handleEvents(){
	inputState = { false, 0, 0, false, false };
	while (SDL_PollEvent(&evnt)){
		switch (evnt.type){
		case SDL_QUIT:
			inputState.quit = true;
			break;
		case SDL_MOUSEBUTTONDOWN:
			inputState.mouseButtonDown = true;
			SDL_GetMouseState(&inputState.mouseX, &inputState.mouseY);
			break;
		case SDL_KEYDOWN:
			std::cout << "space bar" << std::endl;
			inputState.space = true;
			break;
		default:
			break;
		}
	}
}

InputState Input::getCurrentInputState(){
	return inputState;
}