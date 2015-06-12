// PhysicsEngine.cpp implentation file

#include "PhysicsEngine.h"

// accepts a dynamically allocated array of the type MassForce and the size of the array
// this function requires 2 or more massForces
// it is assumed all objects are in contact
//sf::Vector2f *PhysicsEngine::calcAcceleration(MassForceVelocity *mFV, int num)
//{
//	sf::Vector2f *resultList = new sf::Vector2f[num];
//
//	for (int i = 0; i < num; i++)
//	{
//
//	}
//}

//
sf::Vector2f PhysicsEngine::calcAcceleration(System sys1, System sys2)
{
	sf::Vector2f netForce = calcNetForce(sys1, sys2);
	return netForce / sys1.mass;
}

//
sf::Vector2f PhysicsEngine::calcNetForce(System sys1, System sys2)
{
	// find Normal force
	sf::Vector2f normalForce = sys1.mass * gravity * cos(sys1.theta);		
	// find tension force
	// gravity private member data
	// if sliding 
	// find kinetic
	// else find static
	sf::Vector2f staticFriction = -sys1.force;
	// sum netforce

	// reutrn netforce
	return gravity + normalForce + staticFriction;
}