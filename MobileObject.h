//  MobileObject.h header file for non movable objects derived from the Object class

#ifndef MOBILEOBJECT_H
#define MOBILEOBJECT_H

#include "Object.h"

class MobileObject : public Object
{
protected:
	sf::Vector2f velC;		// current velocity
	float maxAForce;		// max applied force (magnitude only)		DOES NOT GOING INTO PHYSICS ENGINE, LIMIT ON OBJECT APPLIED FORCE

public:
	MobileObject() {};
	MobileObject(const sf::Texture &texture, sf::Vector2f size, sf::Vector2f pos) : Object(texture, size, pos)
	{
		this->maxAForce = 5;
		this->velC = { 0, 0 };
	};
	virtual void load(const sf::Texture &texture, sf::Vector2f size, sf::Vector2f pos);
	~MobileObject() {};
	void update(float &frameCounter, float switchFrame);
	virtual void setSystem();
	void setVelC(sf::Vector2f vel) { this->velC = vel; }
	void setMaxAForce(float maxAForce) { this->maxAForce = maxAForce; }
	sf::Vector2f getVelC() const { return velC; }
	float getMaxAForce() const { return maxAForce; }
	
	
};

#endif // MOBILEOBJECT_H