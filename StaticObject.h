//  StaticObject.h header file for non movable objects derived from the Object class

#ifndef STATICOBJECT_H
#define STATICOBJECT_H

#include "Object.h"

class StaticObject : public Object
{
protected:

public:
	StaticObject(const sf::Texture &texture, sf::Vector2f size, sf::Vector2f pos, float mass = 999999, float mu = 1, sf::Vector2f forceA = { 0, 0 }, float theta = 0, sf::Vector2f velC = { 0, 0 }, float maxAForce = 0)
		: Object(texture, size, pos, mass, mu, forceA, theta, velC, maxAForce) {};
	~StaticObject() {};
	void update(float &frameCounter, float switchFrame);
};

#endif // STATICOBJECT_H