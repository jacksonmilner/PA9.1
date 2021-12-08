#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include <vector>
#include "bullet.h"
#include "mainShip.h"
#include "Alien.h"
#include "Andy.h"
#include <time.h>

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
	srand(time(0));
	int yum = 0;
	int z = 0;
	int p = 0;
	int c = 0;
	int shootthebulletfromaliens = 0;
	sf::RenderWindow window(sf::VideoMode(500, 500), "Your Doom!");
	spaceShip spaceship(15, sf::Color::Black, sf::Vector2f(window.getSize().x / 2, window.getSize().y - 90));
	Bullet bullet1(5, sf::Color::Yellow, sf::Vector2f(600, 600), 1);
	sf::Texture t;
	t.loadFromFile("Space-Free-PNG-Image.png");
	sf::Sprite background(t);
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
		int aliensdead = 0;
		sf::Event event;
		window.draw(background);
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		if (spaceship.getHP() == 0)
		{
			std::cout << std::endl << "You have perished" << std::endl;
			window.close();
		}
		if (andy.getHP() == 0)
		{
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
			sf::Vector2f center = sf::Vector2f(spaceship.getPosition().x + 11, spaceship.getPosition().y);
			bullet1.setPosition(center);
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
			c = rand(); //SET C = C+1; AND THEN IT TAKES LIKE 20 SECONDS FOR C TO BE OVER 32000
			if (c > 32000)
				shootthebulletfromaliens = 1;
			else
				shootthebulletfromaliens = 0;
			
			if (shootthebulletfromaliens == 1 && Bulletlist[yum].getPosition() == sf::Vector2f(-600, -600)) // <-REPLACE WITH-> (when time is greater than something but less than something else && Bulletlist[x].getPosition() == sf::Vector2f(-600, -600))
			{
				yum = rand() % 48;
				float tempbugx = alienlist[yum].getPosition().x;
				float tempbugy = alienlist[yum].getPosition().y;
				float tempssx = spaceship.getPosition().x + 12.5;
				float tempssy = spaceship.getPosition().y + 12.5;

				float xval = tempssx - tempbugx;
				float yval = tempssy - tempbugy;

				float normal = sqrt(pow(xval, 2) + pow(yval, 2));

				movex = xval / normal;
				movey = yval / normal;
				Bulletlist[yum].setPosition(alienlist[yum].getPosition()); 
				Bulletlist[yum].move(0.05 * movex, 0.05 * movey);
			}
			if (!Bulletlist[yum].isInbounds('d'))
			{
				Bulletlist[yum].setPosition(sf::Vector2f(-600, -600));
			}
			if (Bulletlist[yum].getPosition() != sf::Vector2f(-600, -600))
			{
				Bulletlist[yum].move(0.05 * movex, 0.05 * movey);
			}
			for (int i = 0; i < Bulletlist.size() - 1; i++)
				spaceship.hit(Bulletlist[i]);

			float moveyh = 0;
			float movexh = 0;
			if (shootthebulletfromaliens == 1 && Bulletlist[z].getPosition() == sf::Vector2f(-600, -600)) // <-REPLACE WITH-> (when time is greater than something but less than something else && Bulletlist[z].getPosition() == sf::Vector2f(-600, -600))
			{
				z = rand() % 48;
				Bulletlist[z].setPosition(alienlist[z].getPosition());
				Bulletlist[z].move(0.02 * movexh, 0.05 * moveyh);
			}
			float tempbugx = Bulletlist[z].getPosition().x;
			float tempbugy = alienlist[z].getPosition().y;
			float tempssx = spaceship.getPosition().x + 12.5;
			float tempssy = spaceship.getPosition().y + 12.5;

			float xval = tempssx - tempbugx;
			float yval = tempssy - tempbugy;

			float normal = sqrt(pow(xval, 2) + pow(yval, 2));

			movexh = xval / normal;
			moveyh = yval / normal;
			if (!Bulletlist[z].isInbounds('d'))
			{
				Bulletlist[z].setPosition(sf::Vector2f(-600, -600));
			}

			if (Bulletlist[z].getPosition() != sf::Vector2f(-600, -600))
			{
				Bulletlist[z].move(0.05 * movexh, 0.04 * moveyh);
			}
			for (int i = 0; i < Bulletlist.size() - 1; i++)
				spaceship.hit(Bulletlist[i]);

			
			if (shootthebulletfromaliens == 1 && Bulletlist[p].getPosition() == sf::Vector2f(-600, -600))
			{
				p = rand() % 48;
				Bulletlist[p].setPosition(alienlist[p].getPosition());
				Bulletlist[p].move(0, 0.05);
			}
			if (!Bulletlist[p].isInbounds('d'))
			{
				Bulletlist[p].setPosition(sf::Vector2f(-600, -600));
			}

			if (Bulletlist[p].getPosition() != sf::Vector2f(-600, -600))
			{
				Bulletlist[p].move(0, 0.05);
			}
			for (int i = 0; i < Bulletlist.size() - 1; i++)
				spaceship.hit(Bulletlist[i]);
		}
		//		BULLET THAT TRACKS WORKS WITH Q, CHANGE TO TIMED EVENT, IF ALL THE TEMP BUG AND XVAL AND NORMAL AND MOVEX/Y ARE MOVED TO THE OUTSIDE ITLL TRACK THE PLAYER
				


		//		PRESS E, SWITCH TO A TIMED EVENT LATER
				


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