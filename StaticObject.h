//  StaticObject.h header file for non movable objects derived from the Object class

#ifndef STATICOBJECT_H
#define STATICOBJECT_H

#include "Object.h"

class StaticObject : public Object
{
protected:

public:
	StaticObject(const sf::Texture &texture, sf::Vector2f size, sf::Vector2f pos): Object(texture, size, pos) {};
	
	~StaticObject() {};
	void update(float &frameCounter, float switchFrame);
};

#endif // STATICOBJECT_H