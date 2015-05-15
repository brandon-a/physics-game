//Object.h file for any type of game object except backgrounds

#ifndef OBJECT_H
#define OBJECT_H

#include <SFML\Graphics.hpp>
#include <string>
#include <iostream>


class Object
{
protected:
	sf::Vector2f pos;
	sf::Sprite sprite;
	sf::Texture texture;
	sf::Vector2f scale;
	sf::Vector2f size;
	sf::Vector2f source; // locations for animations (at the moment) think of better name
	float mass;
	enum direction { Down, Left, Right, Up };			// pull up to global?

public:
	Object() {};
	Object(std::string fileName, sf::Vector2f size, sf::Vector2f pos);
	~Object() {};
	virtual void loadObj() {};
	virtual void unloadObj() {};
	virtual void updateObj() {};
	virtual void drawObj() {};



};








#endif  // OBJECT_H