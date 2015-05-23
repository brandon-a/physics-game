//  MobileObject.h header file for non movable objects derived from the Object class

#ifndef MOBILEOBJECT_H
#define MOBILEOBJECT_H

#include "Object.h"

class MobileObject : public Object
{
protected:
	sf::Vector2f velC;		// current velocity
	sf::Vector2f velM;		// max velocity
	float acceleration;
	
public:
	MobileObject(std::string fileName, sf::Vector2f size, sf::Vector2f pos) : Object(fileName, size, pos) { velC = { 0, 0 }; velM = { 10, 10 }; };
	~MobileObject() {};
	void update(float &frameCounter, float switchFrame);
	sf::Vector2f getVelC() const { return velC; };
	sf::Vector2f getVelM() const {return velM;}
	float getAcceleration() const { return acceleration; }
	void setVelC(sf::Vector2f vel) { this->velC = vel; }
	void setVelM(sf::Vector2f vel) { this->velM = vel; }
	void setAcceleration(float acc) { this->acceleration = acc; }
};

#endif // MOBILEOBJECT_H