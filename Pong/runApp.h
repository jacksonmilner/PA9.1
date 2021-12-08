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
	RunApp();
	~RunApp();

	void setScore(int newscore)
	{
		mscore = newscore;
	}
	int getScore()
	{
		return mscore;
	}

	void run_app();

	void initWindow();
	void initVars();
	void update();
	void render();
	bool isRunning();
	void inputCheck();
	void printStartScreen();
private:
	int mscore;
	sf::RenderWindow* mWindow;
	sf::VideoMode mVideoMode;
	sf::Event mEvent;
	spaceShip mPlayer;
	bool gameRunning;
	int score;



	std::vector<Alien> alienlist;
	std::vector<Bullet> Bulletlist;
};

void RunApp::run_app()
{
	sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");
	spaceShip spaceship(15, sf::Color::Yellow, sf::Vector2f(window.getSize().x / 2, window.getSize().y - 90));
	Bullet bullet1(5, sf::Color::Yellow, sf::Vector2f(600, 600), 1);
	//Bullet bullet2(5, sf::Color::Yellow, sf::Vector2f(-600, -600), 1);
	//Bullet bullet4(5, sf::Color::Yellow, sf::Vector2f(-600, -600), 1);
	int lhand_moving_right = 1;
	//Bullet lhand(25, sf::Color::Yellow, sf::Vector2f(600, 600));
	//Bullet rhand(25, sf::Color::Yellow, sf::Vector2f(600, 600));


	Andy andy(25, sf::Color::Cyan, sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2), 25);

	bool previousShootKeyState;
	int getsize = (window.getSize().x - 240) / 12;
	int x1 = -1;
	int x2 = -1;
	int x3 = -1;
	int x4 = -1;
	int aliensdead = 0;
	bool bosstime = false;
	int gameState = 0;
	int x = window.getSize().x / 14;
	for (int j = 0; j < 12; j++)
	{
		alienlist.push_back(Alien(10, sf::Color::Blue, sf::Vector2f((x * j) + x, window.getSize().y - 400), 1));
		Bulletlist.push_back(Bullet(5, sf::Color::Yellow, sf::Vector2f(-600, -600))); //change color
	}
	for (int e = 0; e < 12; e++)
	{
		alienlist.push_back(Alien(10, sf::Color::Magenta, sf::Vector2f((x * e) + x, window.getSize().y - 430), 2));
		Bulletlist.push_back(Bullet(5, sf::Color::Yellow, sf::Vector2f(-600, -600))); //change color
	}
	for (int b = 0; b < 12; b++)
	{
		alienlist.push_back(Alien(10, sf::Color::Red, sf::Vector2f((x * b) + x, window.getSize().y - 460), 3));
		Bulletlist.push_back(Bullet(5, sf::Color::Yellow, sf::Vector2f(-600, -600))); //change color
	}
	for (int f = 0; f < 12; f++)
	{
		alienlist.push_back(Alien(10, sf::Color::Green, sf::Vector2f((x * f) + x, window.getSize().y - 490), 4));
		Bulletlist.push_back(Bullet(5, sf::Color::Yellow, sf::Vector2f(-600, -600))); //change color
	}
	float movex = 0, movey = 0;

	while (window.isOpen())
	{
		if (aliensdead != 48)
		{
			aliensdead = 0;
		}
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
			window.draw(Bulletlist[i]);
		}

		if (aliensdead < 48)
		{
			int x = 3; //rand() % 48
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && Bulletlist[x].getPosition() == sf::Vector2f(-600, -600))
			{
				float tempbugx = alienlist[x].getPosition().x;
				float tempbugy = alienlist[x].getPosition().y;
				float tempssx = spaceship.getPosition().x + 12.5;
				float tempssy = spaceship.getPosition().y + 12.5;

				float xval = tempssx - tempbugx;
				float yval = tempssy - tempbugy;

				float normal = sqrt(pow(xval, 2) + pow(yval, 2));

				movex = xval / normal;
				movey = yval / normal;
				Bulletlist[x].setPosition(alienlist[x].getPosition());
				Bulletlist[x].move(0.05 * movex, 0.05 * movey);
			}
			if (!Bulletlist[x].isInbounds('d'))
			{
				Bulletlist[x].setPosition(sf::Vector2f(-600, -600));
			}

			if (Bulletlist[x].getPosition() != sf::Vector2f(-600, -600))
			{
				Bulletlist[x].move(0.05 * movex, 0.05 * movey);
			}
			if (Bulletlist[x].getGlobalBounds().intersects(spaceship.getGlobalBounds()))
			{
				//player health reduced by 1
			}
		}
		//		BULLET THAT TRACKS WORKS WITH Q, CHANGE TO TIMED EVENT, IF ALL THE TEMP BUG AND XVAL AND NORMAL AND MOVEX/Y ARE MOVED TO THE OUTSIDE ITLL TRACK THE PLAYER
				


		//		PRESS E, SWITCH TO A TIMED EVENT LATER
		//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::E) && bullet4.getPosition() == sf::Vector2f(-600, -600))
		//		{
		//			bullet4.setPosition(andy.getPosition());
		//			bullet4.move(0, 0.05);
		//		}
		//		if (!bullet4.isInbounds('d'))
		//		{
		//			bullet4.setPosition(sf::Vector2f(-600, -600));
		//		}
		//
		//		if (bullet4.getPosition() != sf::Vector2f(-600, -600))
		//		{
		//			bullet4.move(0, 0.05);
		//		}
		//		if (bullet4.getGlobalBounds().intersects(spaceship.getGlobalBounds()))
		//		{
		//			//player health reduced by 1
		//		}


		//		 //ANDYS LEFT HAND WORKS WHEN R IS PRESSED, SWITCH TO A TIMED EVENT LATER
		//if (sf::Keyboard::isKeyPressed(sf::Keyboard::R) && lhand.getPosition() == sf::Vector2f(-600, -600))
		//{
		//	lhand.setPosition(sf::Vector2f(-10,spaceship.getPosition().y));
		//	lhand.move(0.06, 0);
		//}
		//if (!lhand.isInbounds('r') || lhand.getPosition().x < -100)
		//{
		//	lhand.setPosition(sf::Vector2f(-600, -600));
		//	lhand_moving_right = 1;
		//}
		//if (lhand.getPosition() != sf::Vector2f(-600, -600))
		//{
		//	if(lhand_moving_right == 1)
		//		lhand.move(0.06, 0);
		//	else
		//		lhand.move(-0.06,0);
		//}
		//if (lhand.getPosition().x > 280)
		//{
		//	lhand_moving_right = 0;
		//}

		//window.draw(lhand);
		//window.draw(bullet4);
		//window.draw(bullet2);
		window.draw(bullet1);
		window.draw(spaceship);
		window.display();
		window.clear();
	}
}



RunApp::RunApp()
{
	initWindow();
	initVars();
}

RunApp::~RunApp()
{
	delete mWindow;
	mWindow = nullptr;
}

void RunApp::initWindow()
{
	mVideoMode = sf::VideoMode(500, 500);
	mWindow = new sf::RenderWindow(mVideoMode, "Invaders");
}

void RunApp::initVars()
{
	return;
}

void RunApp::update()
{
	inputCheck();
}

void RunApp::render()
{
	mWindow->clear();


	mWindow->display();
}

bool RunApp::isRunning()
{
	gameRunning = mWindow->isOpen();
	return gameRunning;
}

void RunApp::inputCheck()
{
	while (mWindow->pollEvent(mEvent))
	{
		switch (mEvent.type)
		{
		case sf::Event::Closed:
			{
			mWindow->close();
			break;
			}
		default:
			break;
		}
	}
}

void RunApp::printStartScreen()
{
	if (gameRunning == true)
	{

	}
}