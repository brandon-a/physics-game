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
	sf::Vector2f getPos() const { return pos; }
	sf::Sprite getSprite() const { return sprite; }
	sf::Texture getTexture() const { return texture; }
	sf::Vector2f getScale() const { return scale; }
	sf::Vector2f getSize() const { return size; }
	sf::Vector2f getSource() const { return source; }
	void setPos(sf::Vector2f pos)  { this->pos = pos; }
	void setSprite(sf::Sprite sprite) { this->sprite = sprite; }
	void setTextiure(sf::Texture texture) { this->pos = pos; }
	void setScale(sf::Vector2f scale) { this->scale = scale; }
	void setSize(sf::Vector2f size) { this->size = size; }
	void setSource(sf::Vector2f source) { this->source = source; }


};








#endif  // OBJECT_H