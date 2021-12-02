// This example will use SFML libraries to implement
// the game of Pong

// History: 4/16 - Started from the SFML tutorial code that draws
//                a circle in the window.

#include <SFML/Graphics.hpp>

#include "pacMan.hpp"

int main()
{
	sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");

	spaceShip spaceship(25, sf::Color::Yellow, sf::Vector2f(window.getSize().x / 2, window.getSize().y - 55));
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}


		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			spaceship.move(0.02, 0);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			spaceship.move(-0.02, 0);
		}


		window.clear();
		window.draw(spaceship);
		window.display();
	}

	return 0;
}
}