// MobileObject.cpp Implementation File

#include "MobileObject.h"

// Update Funtion -
// Currently updates the TextureRect to new position when framecounter exceeds switchFame threshold
// Will update the object's screen position
void MobileObject::update(float &frameCounter, float switchFrame)		///////////////////////////////// animatable
{
	sprite->setTextureRect(sf::IntRect(sourcePos.x * size.y / 2, sourcePos.y * size.y / 2, size.y / 2, size.y / 2));
	sprite->move(velC);
	if (frameCounter >= switchFrame)							///// FIX ME TEMPORARY !!!!! ************
	{
		frameCounter = 0;
		sourcePos.x++;
		if (sourcePos.x * size.y >= texture.getSize().x)
		{
			sourcePos.x = 0;
		}
	}
}