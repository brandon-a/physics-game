//  MobileObject.h header file for non movable objects derived from the Object class

#ifndef MOBILEOBJECT_H
#define MOBILEOBJECT_H

#include "Object.h"

class MobileObject : public Object
{
protected:


public:
	MobileObject(std::string fileName, sf::Vector2f size, sf::Vector2f pos, float mass = 30, float mu = 1, sf::Vector2f forceA = { 0.5, 0 }, float theta = 0, sf::Vector2f velC = { -5, 0 }, float maxAForce = 5)
		: Object(fileName, size, pos, mass, mu, forceA, theta, velC, maxAForce){};
	~MobileObject() {};
	void update(float &frameCounter, float switchFrame);
	
	
};

#endif // MOBILEOBJECT_H