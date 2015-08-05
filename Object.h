//  Object.h file - pure virtual class 

#ifndef OBJECT_H
#define OBJECT_H

#include <SFML\Graphics.hpp>
#include <string>
#include <iostream>
#include "PhysicsEngine.h"

//enum direction { Down, Left, Right, Up };		


class Object : public sf::Drawable, public sf::Transformable
{
protected:
	sf::Sprite *sprite;
	sf::Texture texture; /////////////////////////  going to textureManager
	sf::Vector2f size;	///////////////////////////////// animatable
	sf::Vector2u sourcePos;	///////////////////////////////// animatable
	System system;
	sf::Vector2f velC;		// current velocity
	float maxAForce;		// max applied force (magnitude only)		DOES NOT GOING INTO PHYSICS ENGINE, LIMIT ON OBJECT APPLIED FORCE


public:
	Object() {};
	Object(std::string fileName, sf::Vector2f size, sf::Vector2f pos, float mass, float mu, sf::Vector2f forceA, float theta, sf::Vector2f velC, float maxAForce);
	~Object() {};
	virtual void load() {};
	virtual void unload() {};
	virtual void update(float &frameCounter, float switchFrame) = 0;			// parameters will go away when we move the temporary code out	///////////////////////////////// animatable
	virtual void draw(sf::RenderWindow &window) { window.draw(*sprite); }
	//sf::Sprite *getSprite() const { return sprite; }
	sf::Texture getTexture() const { return texture; }
	//sf::Vector2f getScale() const { return sprite->getScale(); }
	//sf::Vector2f getSize() const { return size; }	///////////////////////////////// animatable
	//sf::Vector2u getSourcePos() const { return sourcePos; }	///////////////////////////////// animatable
	//unsigned int getSourcePosX() const { return sourcePos.x; }	///////////////////////////////// animatable
	//unsigned int getSourcePosY() const { return sourcePos.y; }	///////////////////////////////// animatable

	//float getMu() const { return system.mu; }
	sf::Vector2f getForceA() const { return system.force; }
	//float getMass() const { return system.mass; }
	//System getSystem() const { return system; }
	sf::Vector2f getVelC() const { return velC; }
	float getMaxAForce() const { return maxAForce; }

	//void setSprite(sf::Sprite sprite) { this->sprite = sprite; }			not needed
	void setTexture(sf::Texture texture) { this->texture = texture; }
	void setScale(float x, float y) { sprite->setScale( x , y ); }
	void setSize(sf::Vector2f size) { this->size = size; }  ///////////////////////////////// animatable
	void setSourcePos(sf::Vector2u source) { this->sourcePos = source; }	///////////////////////////////// animatable
	void setSourcePosX(unsigned int source) { this->sourcePos.x = source; }	///////////////////////////////// animatable
	void setSourcePosY(unsigned int source) { this->sourcePos.y = source; }	///////////////////////////////// animatable
	//void setForceA(sf::Vector2f acc) { this->system.force = acc; }
	//void setMass(float mass) { this->system.mass = mass; }
	//void setMu(float mu) { this->system.mu = mu; }
	void setVelC(sf::Vector2f vel) { this->velC = vel; }
	void setMaxAForce(float maxAForce) { this->maxAForce = maxAForce; }
	void draw(sf::RenderTarget &, sf::RenderStates) const {};
};

#endif  // OBJECT_H