// Object.cpp file for the Object.h file

#include "Object.h"

Object::Object(std::string fileName, sf::Vector2f size, sf::Vector2f pos)
{
	this->size = size;
	if (!texture.loadFromFile(fileName))
		std::cout << fileName << " failed to open!\n";
	sprite.setTexture(texture);
	sprite.setScale(2.0f, 2.0f);
	source = { 0, 0 };
	this->pos = pos;

};