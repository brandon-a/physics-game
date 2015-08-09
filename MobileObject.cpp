// MobileObject.cpp Implementation File

#include "MobileObject.h"

// Update Funtion -
// Currently updates the TextureRect to new position when framecounter exceeds switchFame threshold
// Will update the object's screen position
void MobileObject::update(float &frameCounter, float switchFrame)		///////////////////////////////// animatable
{
	sprite->setTextureRect(sf::IntRect(sourcePos.x * size.y / 2, sourcePos.y * size.y / 2, size.y / 2, size.y / 2));
	sprite->move(velC);
	if (frameCounter >= switchFrame)							///// FIX ME TEMPORARY !!!!! ************
	{
		frameCounter = 0;
		sourcePos.x++;
		if (sourcePos.x * size.y >= sprite->getTexture()->getSize().x)
		{
			sourcePos.x = 0;
		}
	}
}

void MobileObject::load(const sf::Texture &texture, sf::Vector2f size, sf::Vector2f pos) 
{
	sprite = new sf::Sprite;
	this->size = size;
	sprite->setTexture(texture);
	sprite->setScale(2.0f, 2.0f);
	sourcePos = { 0, 0 };
	sprite->setPosition(pos);
	this->setSystem();
	this->maxAForce = 5;
	this->velC = { 0, 0 };

};

void MobileObject::setSystem()
{
	this->system.mass = 1;
	this->system.mu = 1;
	this->system.force = { 5, 0 };
	this->system.theta = 0;
};
