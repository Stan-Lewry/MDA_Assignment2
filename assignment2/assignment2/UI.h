#ifndef UI_HEADER
#define UI_HEADER

#include "SDLUtils.h"

class UI{
public:
	UI();
	void initElements();
	UIElement* getElementList();

private:
	UIElement elements[1];
};

#endif