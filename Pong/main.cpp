// This example will use SFML libraries to implement
// the game of Pong

// History: 4/16 - Started from the SFML tutorial code that draws
//                a circle in the window.

#include <SFML/Graphics.hpp>
#include "mainShip.h"
#include "Alien.h"
#include "bullet.h"
#include <math.h>
#define Pi 3.14159265

int main()
{
	sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");
	bool previousShootKeyState;
	spaceShip spaceship(15, sf::Color::Yellow, sf::Vector2f(window.getSize().x / 2, window.getSize().y - 90));
	Alien bug1(15, sf::Color::Blue, sf::Vector2f(window.getSize().x / 2, window.getSize().y - 500), 1);
	spaceShip bug2(15, sf::Color::Blue, sf::Vector2f(window.getSize().x / 2, window.getSize().y - 500));
	spaceShip bug3(15, sf::Color::Blue, sf::Vector2f(window.getSize().x / 2, window.getSize().y - 500));
	spaceShip bug4(15, sf::Color::Blue, sf::Vector2f(window.getSize().x / 2, window.getSize().y - 500));
	spaceShip bug5(15, sf::Color::Blue, sf::Vector2f(window.getSize().x / 2, window.getSize().y - 500));
	spaceShip bug6(15, sf::Color::Blue, sf::Vector2f(window.getSize().x / 2, window.getSize().y - 500));
	double x = (Pi/2); //bug moving
	
	while (window.isOpen())
	{
		double z = cos((x / 1000) * Pi); //bug moving
		double y = sin((x / 1000) * Pi); //bug moving
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

				if (bug1.getGlobalBounds().intersects(bullet1.getGlobalBounds()))
				{
					if (bug1.getHP() == 1)
					{
						bug1.hit();
					}
				}
				
				if (bug1.getPosition().x != 300)
				{
					int tempx = bug1.getPosition().x;
					int tempy = bug1.getPosition().y;
					sf::Vector2f(bug1.getPosition().x, bug1.getPosition().y);

					bug1.move(0.5*z, 0.5*y); //bug moving

				}
				if (bug1.getPosition().x == 300)
				{

				}
				if (bug1.getHP() == 1)
					window.draw(bug1);
				window.display();
				x++; //bug moving
			}
			
		}
		if (bug1.getPosition().x != 300)
		{
			int tempx = bug1.getPosition().x;
			int tempy = bug1.getPosition().y;
			sf::Vector2f(bug1.getPosition().x, bug1.getPosition().y);

			bug1.move(0.5*z, 0.5*y); //bug moving

		}
		if (bug1.getPosition().x == 300)
		{

		}
		
		window.draw(spaceship);
		if (bug1.getHP() == 1)
			window.draw(bug1);
		window.display();
		window.clear();
		x++; //bug moving
	}

	return 0;
}
