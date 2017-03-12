#include "UI.h"

UI::UI(){
	//initElements();
}



void UI::initGameplayElements(){
	
	UIElement mainWindow = { 0, 0, 300, 720, 0, 0, A };
	elements[0] = mainWindow;
	
}

void UI::initMainMenuElements(){
	/*
	UIElement playButton = { screenW - 300 - 64, 200, 300, 64, 332, 0, CHANGESTATE_GAMEPLAY };
	elements[0] = playButton;
	*/

	UIElement play = { screenW - 364, 200, 300, 64, 0, 0, false, CHANGESTATE_GAMEPLAY };
	elements[0] = play;

	UIElement editor = { screenW - 364, 328, 300, 64, 0, 64, false, NO_ACTION };
	elements[1] = editor;

	UIElement options = { screenW - 364, 465, 300, 64, 0, 128, false, NO_ACTION };
	elements[2] = options;

	UIElement exit = { screenW - 364, 584, 300, 64, 0, 192, false, QUIT };
	elements[3] = exit;
}

UIElement* UI::getElementList(){
	return elements;
}

UIAction UI::getAction(int mouseX, int mouseY){
	for (int i = 0; i < 4; i++){
		if (mouseX >= elements[i].screenX && mouseX < elements[i].screenX + elements[i].width){
			if (mouseY >= elements[i].screenY && mouseY < elements[i].screenY + elements[i].height){
				return elements[i].action;
			}
		}
	}
	return NO_ACTION;
}

void UI::hover(int mouseX, int mouseY){
	for (int i = 0; i <4; i++){
		if (mouseX >= elements[i].screenX && mouseX < elements[i].screenX + elements[i].width){
			if (mouseY >= elements[i].screenY && mouseY < elements[i].screenY + elements[i].height){
				for (int x = 0; x < 4; x++){
					elements[x].hover = false;
				}
				elements[i].hover = true;
			}
		}
	}
	
}