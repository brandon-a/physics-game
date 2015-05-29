//GameEngine.h file to manage game functions

#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "PlayerObject.h"
#include "StaticObject.h"

enum direction { Down, Left, Right, Up };

class GameEngine
{
private:
	bool movR;
	bool movL;
	bool movU;
	bool movD;
	sf::Clock clock;
	sf::Time timePerFrame;

public:
	GameEngine();
	~GameEngine();
	void gameLoop();



};



#endif  // GAMEENGINE_H