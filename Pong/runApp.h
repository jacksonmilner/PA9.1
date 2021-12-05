#pragma once
#include "mainShip.h"

class RunApp
{
public:
	RunApp();
	~RunApp();

private:

};

RunApp::RunApp()
{
	sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");
	bool previousShootKeyState;
	spaceShip spaceship(25, sf::Color::Yellow, sf::Vector2f(window.getSize().x / 2, window.getSize().y - 90));
	while (window.isOpen())
	{
		window.clear();
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


		Bullet bullet1(20, sf::Color::Yellow, spaceship.getPosition());
		window.draw(bullet1);
		bullet1.move(0, -0.05);



		//window.clear();
		window.draw(spaceship);
		window.display();
	}
}