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
	PlayerObject *p1;
	Object *allobjects;		// this pointer will point to an array of all the objects in the game

	sf::Vector2f screenSize;		// keep elsewhere do not delete
	StaticObject *background;
	float frameCounter;				// for animations isanimatable
	float switchFrame;			// for animations isanimatable
	float frameSpeed;				// for animations isanimatable

	sf::RenderWindow *window;
	sf::Clock deltaClock;
	sf::Time timeSincelastUpdate;

public:
	GameEngine();
	~GameEngine();
	void gameLoop();



};



#endif  // GAMEENGINE_H