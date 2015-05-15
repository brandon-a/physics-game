// MobileObject.h header file for movable objects derived from the Object class


#ifndef MOBILEOBJECT_H
#define MOBILEOBJECT_H

#include "Object.h"

class MobileObject : public Object
{
protected:
	sf::Vector2f velocity;
	

public:
	MobileObject();
	~MobileObject();
	void loadObj();
	void unloadObj();
	void updateObj();
	void drawObj();





};


#endif // MOBILEOBJECT_H