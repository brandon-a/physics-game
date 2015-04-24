// This is the start of our Physics Game
// Brandon and Jamie

#include <iostream>
#include <iomanip>
#include <string>
#include <SFML/Graphics.hpp>



int main()
{
	std::cout << "This is the best Physics game ever!\n";
	std::cout << "I AGREE!\n";
	std::cout << "The game will now exit!\n";
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}
	return 0;
}