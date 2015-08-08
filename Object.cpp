// Object Implementation File

#include "Object.h"

// Constructor -
// Creates the texture and sprite for the object.  
// Sets the inital scale, source position, and screen position.
Object::Object(const sf::Texture &texture, sf::Vector2f size, sf::Vector2f pos, float mass, float mu, sf::Vector2f forceA, float theta, sf::Vector2f velC, float maxAForce)
{
	sprite = new sf::Sprite;
	this->size = size;
	sprite->setTexture(texture);
	sprite->setScale(2.0f, 2.0f);
	sourcePos = { 0, 0 };
	sprite->setPosition(pos);
	this->system.mass = mass;
	this->system.mu = mu;
	this->system.force = forceA;
	this->system.theta = theta;
	this->maxAForce = maxAForce;

};