//  Object.h file - pure virtual class 

#ifndef OBJECT_H
#define OBJECT_H

#include <string>
#include <iostream>
#include "PhysicsEngine.h"
#include <SFML/Graphics.hpp>

class Object 
{
protected:
	sf::Sprite *sprite;
	sf::Vector2f size;	///////////////////////////////// animatable
	sf::Vector2u sourcePos;	///////////////////////////////// animatable
	System system;

public:
	Object(){};
	Object(const sf::Texture &texture, sf::Vector2f size, sf::Vector2f pos){ load(texture, size, pos); };
	~Object() { unload(); }

	virtual void load(const sf::Texture &texture, sf::Vector2f size, sf::Vector2f pos);
	virtual void unload() { delete sprite; }

	virtual void draw(sf::RenderWindow &window) { window.draw(*sprite); }
	void draw(sf::RenderTarget &, sf::RenderStates) const {};	


	const sf::Texture* getTexture(){ return sprite->getTexture(); }
	void setScale(float x, float y) { sprite->setScale( x , y ); }
	
	
	virtual void update(float &frameCounter, float switchFrame) = 0;			///////////////////////////////// animatable
	//sf::Vector2f getSize() const { return size; }						///////////////////////////////// animatable
	//sf::Vector2u getSourcePos() const { return sourcePos; }				///////////////////////////////// animatable
	//unsigned int getSourcePosX() const { return sourcePos.x; }			///////////////////////////////// animatable
	//unsigned int getSourcePosY() const { return sourcePos.y; }			///////////////////////////////// animatable
	
	void setSize(sf::Vector2f size) { this->size = size; }					///////////////////////////////// animatable
	void setSourcePos(sf::Vector2u source) { this->sourcePos = source; }		///////////////////////////////// animatable
	void setSourcePosX(unsigned int source) { this->sourcePos.x = source; }	///////////////////////////////// animatable
	void setSourcePosY(unsigned int source) { this->sourcePos.y = source; }	///////////////////////////////// animatable


	

	// PHYSICS STUFF	
	virtual void setSystem();
	System getSystem() const { return system; }
	//void setForceA(sf::Vector2f acc) { this->system.force = acc; }
	//void setMass(float mass) { this->system.mass = mass; }
	//void setMu(float mu) { this->system.mu = mu; }	
	sf::Vector2f getForceA() const { return system.force; }
	//float getMass() const { return system.mass; }
	
	//float getMu() const { return system.mu; }
};

#endif  // OBJECT_H