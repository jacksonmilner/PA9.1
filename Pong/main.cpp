// This example will use SFML libraries to implement
// the game of Pong

// History: 4/16 - Started from the SFML tutorial code that draws
//                a circle in the window.

#include <SFML/Graphics.hpp>
#include "mainShip.h"
#include "bullet.h"
#include "runApp.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");
	bool previousShootKeyState;
	spaceShip spaceship(15, sf::Color::Yellow, sf::Vector2f(window.getSize().x / 2, window.getSize().y - 90));
	spaceShip bug1(15, sf::Color::Blue, sf::Vector2f(window.getSize().x / 2, window.getSize().y - 500));
	spaceShip bug2(15, sf::Color::Blue, sf::Vector2f(window.getSize().x / 2, window.getSize().y - 500));
	spaceShip bug3(15, sf::Color::Blue, sf::Vector2f(window.getSize().x / 2, window.getSize().y - 500));
	spaceShip bug4(15, sf::Color::Blue, sf::Vector2f(window.getSize().x / 2, window.getSize().y - 500));
	spaceShip bug5(15, sf::Color::Blue, sf::Vector2f(window.getSize().x / 2, window.getSize().y - 500));
	spaceShip bug6(15, sf::Color::Blue, sf::Vector2f(window.getSize().x / 2, window.getSize().y - 500));

	while (window.isOpen())
	{
		//window.clear();
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && spaceship.isInbounds('r'))
		{
			spaceship.move(0.11, 0);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && spaceship.isInbounds('l'))
		{
			spaceship.move(-0.11, 0);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			Bullet bullet1(5, sf::Color::Yellow, spaceship.getPosition());
			while (bullet1.isInbounds('u'))
			{
				window.clear();
				bullet1.move(0, -0.4);
				window.draw(bullet1);
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && spaceship.isInbounds('r'))
				{
					spaceship.move(0.11, 0);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && spaceship.isInbounds('l'))
				{
					spaceship.move(-0.11, 0);
				}
				window.draw(spaceship);
				window.display();
			}
			
		}
		window.clear();
		window.draw(spaceship);
		window.draw(bug1);
		window.display();
	}

	return 0;
}
