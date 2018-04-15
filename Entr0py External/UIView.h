#ifndef UIVIEW_H
#define UIVIEW_H

#include <Framework.h>
#include "CheatBase.h"

class UIView
{
public:
	UIView(Graphics* g)
	{
		this->graphics = g;
	}

	void Init();

	std::vector<UIElement*> gui;

private:
	Graphics* graphics;
};


#endif // !UIVIEW_H