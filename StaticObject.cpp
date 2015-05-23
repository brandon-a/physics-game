// StaticObject Implementation File

#include "StaticObject.h"

// Update Funtion -
// Currently updates the TextureRect to new position when framecounter exceeds switchFame threshold
void StaticObject::update(float &frameCounter, float switchFrame)
{
	sprite.setTextureRect(sf::IntRect(sourcePos.x * size.y / 2, sourcePos.y * size.y / 2, size.y / 2, size.y / 2));
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