// MobileObject.cpp file for the Object.h file

#include "MobileObject.h"

void MobileObject::update(float &frameCounter, float switchFrame)
{
	sprite.setTextureRect(sf::IntRect(sourcePos.x * size.y / 2, sourcePos.y * size.y / 2, size.y / 2, size.y / 2));
	sprite.move(velC);
	//std::cout << frameCounter << '\t' << switchFrame << std::endl;
	if (frameCounter >= switchFrame)							///// FIX ME TEMPORARY !!!!! ************
	{
		frameCounter = 0;
		sourcePos.x++;
		std::cout << '\n' << sourcePos.x << '\n';
		if (sourcePos.x * size.y >= texture.getSize().x)
		{
			sourcePos.x = 0;
			std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
		}

	}
}