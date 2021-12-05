#pragma once
#include "mainShip.h"
#include <iostream>

class RunApp
{
public:
	RunApp();
	~RunApp();
	void playGame();
private:
	sf::Text* mPlayerOne;
	sf::Font mFont;
	sf::Text* mHiScore;
};

RunApp::RunApp()
{
	//LOAD FROM FILE NOT WORKING/DONT HAVE EMULOGIC?
	/*if (!mFont.loadFromFile("emulogic.ttf"))
	{
		std::cout << "error setting font" << std::endl;
	}*/

	mPlayerOne->setFont(mFont);
	mPlayerOne->setString("1UP");
	mPlayerOne->setCharacterSize(33);
	mPlayerOne->setColor(sf::Color::Red);

	mHiScore->setFont(mFont);
	mHiScore->setString("HI-SCORE");
	mHiScore->setCharacterSize(33);
	mHiScore->setColor(sf::Color::Red);

}

RunApp::~RunApp()
{
	delete mPlayerOne;
	mPlayerOne = nullptr;
	delete mHiScore;
	mHiScore = nullptr;
}

void RunApp::playGame()
{
	sf::RenderWindow window(sf::VideoMode(500, 500), "Galaga!(scuffed)");
	bool previousShootKeyState;
	spaceShip spaceship(15, sf::Color::Yellow, sf::Vector2f(window.getSize().x / 2, window.getSize().y - 90));
	spaceShip bug1(15, sf::Color::Blue, sf::Vector2f(window.getSize().x / 2, window.getSize().y - 90));

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
		window.display();
	}
}