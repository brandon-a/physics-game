//Object.h file for any type of game object except backgrounds

#ifndef OBJECT_H
#define OBJECT_H

#include <SFML\Graphics.hpp>


class Object
{
protected:
	sf::Vector2f pos;
	sf::Sprite sprite;
	sf::Texture texture;
	sf::Vector2f scale;
	float mass;

public:
	Object();
	~Object();
	virtual void loadObj();
	virtual void unloadObj();
	virtual void updateObj();
	virtual void drawObj();



};








#endif  // OBJECT_H