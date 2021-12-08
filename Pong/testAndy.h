#pragma once
#include "Andy.h"
class TestAndy
{
public:
	TestAndy();
	void testSpray();
};
TestAndy::TestAndy()
{

}
void TestAndy::testSpray()
{
	sf::RenderWindow window(sf::VideoMode(500, 500), "Your Doom!");
	spaceShip spaceship(15, sf::Color::Black, sf::Vector2f(window.getSize().x / 2, window.getSize().y - 90));
	sf::Texture t;
	t.loadFromFile("Space-Free-PNG-Image.png");
	sf::Sprite background(t);
	int andy_timer = 0;
	Bullet bullet1(5, sf::Color::Yellow, sf::Vector2f(600, 600), 1);
	Andy andy(25, sf::Color::Cyan, sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2), 150);
	while (window.isOpen())
	{
		sf::Event event;
		window.draw(background);
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		/*if (spaceship.getHP() == 0)
		{
			std::cout << std::endl << "You have perished" << std::endl;
			window.close();
		}*/
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && spaceship.isInbounds('r'))
		{
			spaceship.move(0.11, 0);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && spaceship.isInbounds('l'))
		{
			spaceship.move(-0.11, 0);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && bullet1.getPosition() == sf::Vector2f(600, 600))
		{
			sf::Vector2f center = sf::Vector2f(spaceship.getPosition().x + 11, spaceship.getPosition().y);
			bullet1.setPosition(center);
			bullet1.move(0, -0.4);
		}
		if (!bullet1.isInbounds('u'))
		{
			bullet1.setPosition(sf::Vector2f(600, 600));
		}
		if (bullet1.getPosition() != sf::Vector2f(600, 600))
		{
			bullet1.move(0, -0.4);
		}

			if (andy.hit(bullet1))
			{
				bullet1.setPosition(sf::Vector2f(600, 600));
				andy.updateHealthBar();
			};

		if (andy.getHP() > 0)
		{
			if (andy_timer % 10000 == 0)
			{
				andy.setPosition(sf::Vector2f((rand() % (400 - 100 + 1) + 100), (rand() % (200 - 100 + 1) + 100)));
			}
			if (andy_timer % 5000 == 0)
			{
				andy.spray();
			}
			if (!andy.reloaded())
			{
				andy.getAmmo()[0].move(-0.06, 0.07);
				andy.getAmmo()[1].move(-0.03, 0.07);
				andy.getAmmo()[2].move(0, 0.07);
				andy.getAmmo()[3].move(0.03, 0.07);
				andy.getAmmo()[4].move(0.06, 0.07);
			}
			for (int i = 0; i < 5; i++)
			{
				if (!andy.getAmmo()[i].isInbounds('d'))
				{
					for (int i = 0; i < 5; i++)
					{
						andy.getAmmo()[i].setPosition(sf::Vector2f(-600, -600));
					}
				}
			}
			for (int i = 0; i < 5; i++)
			{
				window.draw(andy.getAmmo()[i]);
				spaceship.hit(andy.getAmmo()[i]);
			}
			window.draw(andy);
			window.draw(andy.getHealthBar());
		}

		window.draw(bullet1);
		window.draw(spaceship);
		window.display();
		window.clear();
		andy_timer++;
	}
}