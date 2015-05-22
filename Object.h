//Object.h file for any type of game object except backgrounds

#ifndef OBJECT_H
#define OBJECT_H

#include <SFML\Graphics.hpp>
#include <string>
#include <iostream>


class Object
{
protected:
	sf::Sprite sprite;
	sf::Texture texture;
	sf::Vector2f scale;
	sf::Vector2f size;
	sf::Vector2u sourcePos;
	float mass;
	enum direction { Down, Left, Right, Up };			// pull up to global?

public:
	Object() {};
	Object(std::string fileName, sf::Vector2f size, sf::Vector2f pos);
	~Object() {};
	virtual void load() {};
	virtual void unload() {};
	virtual void update(float &frameCounter, float switchFrame) = 0;			// parameters will go away when we move the temporary code out
	virtual void draw(sf::RenderWindow &window) { window.draw(sprite); }
	sf::Sprite getSprite() const { return sprite; }
	sf::Texture getTexture() const { return texture; }
	sf::Vector2f getScale() const { return scale; }
	sf::Vector2f getSize() const { return size; }
	sf::Vector2u getSourcePos() const { return sourcePos; }
	void setSprite(sf::Sprite sprite) { this->sprite = sprite; }
	void setTexture(sf::Texture texture) { this->texture = texture; }
	void setScale(sf::Vector2f scale) { this->scale = scale; }
	void setSize(sf::Vector2f size) { this->size = size; }
	void setSourcePos(sf::Vector2u source) { this->sourcePos = source; }


};








#endif  // OBJECT_H