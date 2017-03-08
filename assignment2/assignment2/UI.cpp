#include "UI.h"

UI::UI(){
	initElements();
}



void UI::initElements(){
	
	UIElement mainWindow = { 0, 0, 300, 720, 0, 0, A };
	elements[0] = mainWindow;

}

UIElement* UI::getElementList(){
	return elements;
}