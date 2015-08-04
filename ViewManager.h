// ViewManager.h file for controlling what is on the screen

#ifndef VIEWMANAGER_H
#define VIEWMANAGER_H

#include "GameEngine.h"

class ViewManager : public GameEngine
{
protected:
	sf::View view;
public:
	void setView();
	void setViewPort();
};

#endif // VIEWMANAGER_H