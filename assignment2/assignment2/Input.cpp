#include "Input.h"

Input::Input(){
	inputState = { false, 0, 0, false };
}

void Input::handleEvents(){

}

InputState Input::getCurrentInputState(){
	return inputState;
}