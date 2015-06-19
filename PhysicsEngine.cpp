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
	//sf::Vector2f normalForce = sys1.mass * gravity * cos(sys1.theta);		
	//// find tension force
	//// gravity private member data
	//// if sliding										// if it doesn't break static calc static else calc kinetic
	//// find kinetic
	//sf::Vector2f kineticFriction = normalForce * (sys1.mu + sys2.mu);
	//// else find static
	////sf::Vector2f staticFriction = -sys1.force;
	//// sum netforce

	//// reutrn netforce
	//return gravity + normalForce + kineticFriction;

	if (sys1.acc.x > 0)
		return sys1.acc - sf::Vector2f{3, 0};
	else if (sys1.acc.x < 0)
		return sys1.acc + sf::Vector2f{3, 0};
	else
		return { 0, 0 };

	return sys1.acc;
}