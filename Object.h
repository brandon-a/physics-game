//  Object.h file - pure virtual class 

#ifndef OBJECT_H
#define OBJECT_H

#include <SFML\Graphics.hpp>
#include <string>
#include <iostream>

//enum direction { Down, Left, Right, Up };			

class Object
{
protected:
	sf::Sprite sprite;
	sf::Texture texture;
	sf::Vector2f size;
	sf::Vector2u sourcePos;
	float mass;
	float mu;
	sf::Vector2f forceA;


public:
	Object() {};
	Object(std::string fileName, sf::Vector2f size, sf::Vector2f pos, float mu = 1, sf::Vector2f forceA = { 0, 0 });
	~Object() {};
	virtual void load() {};
	virtual void unload() {};
	virtual void update(float &frameCounter, float switchFrame) = 0;			// parameters will go away when we move the temporary code out
	virtual void draw(sf::RenderWindow &window) { window.draw(sprite); }
	sf::Sprite getSprite() const { return sprite; }
	sf::Texture getTexture() const { return texture; }
	sf::Vector2f getScale() const { return sprite.getScale(); }
	sf::Vector2f getSize() const { return size; }
	sf::Vector2u getSourcePos() const { return sourcePos; }
	unsigned int getSourcePosX() const { return sourcePos.x; }
	unsigned int getSourcePosY() const { return sourcePos.y; }
	sf::Vector2f getForceA() const { return forceA; }
	float getMass() const { return mass; }
	void setSprite(sf::Sprite sprite) { this->sprite = sprite; }
	void setTexture(sf::Texture texture) { this->texture = texture; }
	void setScale(float x, float y) { sprite.setScale( x , y ); }
	void setSize(sf::Vector2f size) { this->size = size; }
	void setSourcePos(sf::Vector2u source) { this->sourcePos = source; }
	void setSourcePosX(unsigned int source) { this->sourcePos.x = source; }
	void setSourcePosY(unsigned int source) { this->sourcePos.y = source; }
	void setForceA(sf::Vector2f acc) { this->forceA = acc; }
	void setMass(float mass) { this->mass = mass; }
};

#endif  // OBJECT_H