#pragma once
#include <SFML/Graphics.hpp>
#include <math.h>
#include <vector>
#include "bullet.h"
#include "mainShip.h"
#include "Alien.h"
#include "Andy.h"

using std::vector;

#define Pi 3.14159265

class RunApp
{
public:
	RunApp(int score)
	{
		score = 0;
	}

	void setScore(int newscore)
	{
		mscore = newscore;
	}
	int getScore()
	{
		return mscore;
	}

	void run_app();

	std::vector<Alien> alienlist;
private:
	int mscore;
};

void RunApp::run_app()
{
	sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");
	spaceShip spaceship(15, sf::Color::Yellow, sf::Vector2f(window.getSize().x / 2, window.getSize().y - 90));
	Bullet bullet1(5, sf::Color::Yellow, sf::Vector2f(600, 600), 1);
	Andy andy(25, sf::Color::Cyan, sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2), 25);

	bool previousShootKeyState;
	int getsize = (window.getSize().x - 240) / 12;
	int x1 = -1;
	int x2 = -1;
	int x3 = -1;
	int x4 = -1;
	bool bosstime = false;
	int gameState = 0;
	int x = window.getSize().x / 14;
	for (int j = 0; j < 12; j++)
		alienlist.push_back(Alien(10, sf::Color::Blue, sf::Vector2f((x * j)+ x, window.getSize().y - 400), 1));
	for (int e = 0; e < 12; e++)
		alienlist.push_back(Alien(10, sf::Color::Magenta, sf::Vector2f((x * e) +x, window.getSize().y - 430), 2));
	for (int b = 0; b < 12; b++)
		alienlist.push_back(Alien(10, sf::Color::Red, sf::Vector2f((x * b) + x, window.getSize().y - 460), 3));
	for (int f = 0; f < 12; f++)
		alienlist.push_back(Alien(10, sf::Color::Green, sf::Vector2f((x * f) + x, window.getSize().y - 490), 4));
	

	while (window.isOpen())
	{
		int aliensdead = 0;
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

		for (int j = 0; j < 12; j++)
			alienlist[j].move(x1 * .005, 0);
		for (int b = 12; b < 24; b++)
			alienlist[b].move(x2 * -.008, 0);
		for (int e = 24; e < 36; e++)
			alienlist[e].move(x3 * .01, 0);
		for (int v = 36; v < 48; v++)
			alienlist[v].move(x4 * -0.012, 0);

		if (!alienlist[0].isInbounds('l'))
			x1 *= -1;
		if (!alienlist[11].isInbounds('r'))
			x1 *= -1;
		if (!alienlist[12].isInbounds('l'))
			x2 *= -1;
		if (!alienlist[23].isInbounds('r'))
			x2 *= -1;
		if (!alienlist[24].isInbounds('l'))
			x3 *= -1;
		if (!alienlist[35].isInbounds('r'))
			x3 *= -1;
		if (!alienlist[36].isInbounds('l'))
			x4 *= -1;
		if (!alienlist[47].isInbounds('r'))
			x4 *= -1;

		

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && bullet1.getPosition() == sf::Vector2f(600, 600))
		{
			bullet1.setPosition(spaceship.getPosition());
			bullet1.move(0, -0.4);
		}
		if (!bullet1.isInbounds('u'))
		{
			bullet1.setPosition(sf::Vector2f(600,600));
		}
		if (bullet1.getPosition() != sf::Vector2f(600, 600))
		{
			bullet1.move(0, -0.4);
		}
		for (int i = 0; i < alienlist.size(); i++)
		{
			if (alienlist[i].hit(bullet1))
			{
				bullet1.setPosition(sf::Vector2f(600, 600));
			}
		}
		
		for (int i = 0; i < alienlist.size(); i++)
		{
			if (alienlist[i].getHP() == 0)
				aliensdead++;
		}
		if (aliensdead == 48)
		{
			gameState = 1;
		}
		if (gameState == 1)
		{
			if (andy.hit(bullet1))
			{
				bullet1.setPosition(sf::Vector2f(600, 600));
				andy.updateHealthBar();
			};
		}
		if (gameState == 1 && andy.getHP() > 0)
		{
			window.draw(andy);
			window.draw(andy.getHealthBar());
		}
		for (int i = 0; i <= alienlist.size() - 1; i++)
		{
			if (alienlist[i].getHP() != 0)
				window.draw(alienlist[i]);
		}
		window.draw(bullet1);
		window.draw(spaceship);
		window.display();
		window.clear();
	}
}
