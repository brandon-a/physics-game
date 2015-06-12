//  StaticObject.h header file for non movable objects derived from the Object class

#ifndef STATICOBJECT_H
#define STATICOBJECT_H

#include "Object.h"

class StaticObject : public Object
{
protected:

public:
	StaticObject(std::string fileName, sf::Vector2f size, sf::Vector2f pos, float mu = 1, sf::Vector2f forceA = { 0, 0 }) : Object(fileName, size, pos, mu) {};
	~StaticObject() {};
	void update(float &frameCounter, float switchFrame);
};

#endif // STATICOBJECT_H