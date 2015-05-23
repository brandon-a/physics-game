// Object Implementation File

#include "Object.h"

// Constructor -
// Creates the texture and sprite for the object.  
// Sets the inital scale, source position, and screen position.
Object::Object(std::string fileName, sf::Vector2f size, sf::Vector2f pos)
{
	this->size = size;
	if (!texture.loadFromFile(fileName))
		std::cout << fileName << " failed to open!\n";
	sprite.setTexture(texture);
	sprite.setScale(2.0f, 2.0f);
	sourcePos = { 0, 0 };
	sprite.setPosition(pos);
};