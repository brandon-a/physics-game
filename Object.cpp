// Object Implementation File

#include "Object.h"

void Object::load(const sf::Texture &texture, sf::Vector2f size, sf::Vector2f pos)
{
	sprite = new sf::Sprite;
	this->size = size;
	sprite->setTexture(texture);
	sprite->setScale(2.0f, 2.0f);
	sourcePos = { 0, 0 };
	sprite->setPosition(pos);
	this->setSystem();

};

void Object::setSystem()
{
	this->system.mass = 1;
	this->system.mu = 1;
	this->system.force = { 5, 0 };
	this->system.theta = 0;
};