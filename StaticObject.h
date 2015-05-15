// StaticObject.h header file for non movable objects derived from the Object class


#ifndef STATICOBJECT_H
#define STATICOBJECT_H

#include "Object.h"

class StaticObject : public Object
{
protected:


public:
	StaticObject(std::string fileName, sf::Vector2f size, sf::Vector2f pos) : Object(fileName, size, pos) {};
	~StaticObject() {};
	void loadObj() {};
	void unloadObj() {};
	void updateObj() {};
	void drawObj() {};





};


#endif // STATICOBJECT_H