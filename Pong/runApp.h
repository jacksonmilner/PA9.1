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
	int zap = 0;
	int pop = 0;
	int rap = 0;
	int hat = 0;
	int counterup = 0;
	int shootthebulletfromaliens = 0;
	int shootthebulletfromaliens1 = 0;
	int shootthebulletfromaliens2 = 0;
	int shootthebulletfromaliens3 = 0;
	int shootthebulletfromaliens4 = 0;
	int andy_timer = 0;

	sf::RenderWindow window(sf::VideoMode(500, 500), "Your Doom!");
	spaceShip spaceship(15, sf::Color::Black, sf::Vector2f(window.getSize().x / 2, window.getSize().y - 90));
	Bullet bullet1(5, sf::Color::Yellow, sf::Vector2f(600, 600), 1);
	sf::Texture t;
	t.loadFromFile("Space-Free-PNG-Image.png");
	sf::Sprite background(t);
	int lhand_moving_right = 1;
	Bullet lhand(25, sf::Color::Yellow, sf::Vector2f(600, 600));
	Bullet rhand(25, sf::Color::Yellow, sf::Vector2f(600, 600));


	Andy andy(25, sf::Color::Cyan, sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2), 150);

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
	float movex1 = 0, movey1 = 0;
	float moveyh = 0;
	float movexh = 0;

	while (window.isOpen())
	{
		int aliensdead = 0;
		sf::Event event;
		window.draw(background);
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.clear();
				window.close();
			}
		}
		if (spaceship.getHP() == 0)
		{
			std::cout << std::endl << "You have perished" << std::endl;
			window.clear();
			window.close();
		}
		if (andy.getHP() == 0)
		{
			window.clear();
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
		

		//gameState = 1; //ERASE LATER
		if (gameState == 1)
		{
			if (andy.hit(bullet1))
			{
				bullet1.setPosition(sf::Vector2f(600, 600));
				andy.updateHealthBar();
			};
		}
		if (gameState == 1 && andy.getHP() > 0) //&& andy.getHP()>stage2)
		{
			if (andy_timer < 100000)
			{
				if (andy_timer % 10000 == 0)
				{
					andy.setPosition(sf::Vector2f((rand() % (400 - 100 + 1) + 100), (rand() % (200 - 100 + 1) + 100)));
				}
				if (andy_timer % 5000 == 0)
				{
					andy.spray();
				}
			}
			if ((andy_timer > 100000 && andy_timer < 101000)||(andy_timer % 50000 == 0 && andy_timer > 101000))
			{
				andy.setPosition(sf::Vector2f(window.getSize().x , window.getSize().y / 2 - 175)); // / 2 - 25
			}
			if (andy_timer > 101000)
			{
				if (andy.getPosition().y == -25)
				{

					if (andy.getAmmo()[5].getPosition().y < 250)
					{
						if (andy.getAmmo()[7].getPosition().x == -600)
						{
							andy.getAmmo()[5].setPosition(andy.getPosition());
							andy.getAmmo()[6].setPosition(andy.getPosition());
							andy.getAmmo()[7].setPosition(andy.getPosition());
							andy.getAmmo()[8].setPosition(andy.getPosition());
							andy.getAmmo()[9].setPosition(andy.getPosition());
						}
						andy.getAmmo()[5].move(-0.06, 0.07);
						andy.getAmmo()[6].move(-0.03, 0.07);
						andy.getAmmo()[7].move(0, 0.07);
						andy.getAmmo()[8].move(0.03, 0.07);
						andy.getAmmo()[9].move(0.06, 0.07);
					}
					else
					{
						andy.getAmmo()[5].move(0.07 * movexh, 0.05);
						andy.getAmmo()[6].move(0.07 * movexh, 0.05);
						andy.getAmmo()[7].move(0.07 * movexh, 0.05);
						andy.getAmmo()[8].move(0.07 * movexh, 0.05);
						andy.getAmmo()[9].move(0.07 * movexh, 0.05);
					}
				}
				else
				{
					andy.move(sin((andy_timer / 100) * (Pi / 10)),sin((andy_timer / 100) * (Pi / 10))*cos((andy_timer/100)*(Pi/10)));
				}
				if (andy_timer % 25000 == 0 && andy_timer % 50000 != 0 && andy_timer > 130000)
				{
					andy.setPosition(sf::Vector2f(window.getSize().x / 2 - 25, -25));
				}
				//if(andy_timer % )
			}
			if (andy.getAmmo()[0].getPosition() != sf::Vector2f(-600,-600))
			{
				andy.getAmmo()[0].move(-0.06, 0.07);
				andy.getAmmo()[1].move(-0.03, 0.07);
				andy.getAmmo()[2].move(0, 0.07);
				andy.getAmmo()[3].move(0.03, 0.07);
				andy.getAmmo()[4].move(0.06, 0.07);
			}
			for (int i = 0; i < 10; i++)
			{
				if (!andy.getAmmo()[i].isInbounds('d'))
				{
					for (int i = 0; i < 10; i++)
					{
						andy.getAmmo()[i].setPosition(sf::Vector2f(-600, -600));
					}
				}
			}
			for (int i = 0; i < 10; i++)
			{
				window.draw(andy.getAmmo()[i]);
				spaceship.hit(andy.getAmmo()[i]);
			}
			window.draw(andy);
			window.draw(andy.getHealthBar());
			andy_timer++;
		}
		//if (gameState == 1 && andy.getHP() > 0)// && andy.getHP() <= stage2)
		//{
			
		//}







		for (int i = 0; i <= alienlist.size() - 1; i++)
		{
			if (alienlist[i].getHP() != 0)
				window.draw(alienlist[i]);
			window.draw(Bulletlist[i]);
		}

		if (aliensdead < 48)
		{
			
			counterup++;
			if (counterup > 5000)
			{
				shootthebulletfromaliens = 1;
			}
			if (counterup > 10000)
			{
				shootthebulletfromaliens1 = 1;
			}
			if (counterup > 15000)
			{
				shootthebulletfromaliens2 = 1;
				shootthebulletfromaliens3 = 1;
				shootthebulletfromaliens4 = 1;
			}

			
			if (shootthebulletfromaliens == 1 && Bulletlist[yum].getPosition() == sf::Vector2f(-600, -600)) // <-REPLACE WITH-> (when time is greater than something but less than something else && Bulletlist[x].getPosition() == sf::Vector2f(-600, -600))
			{
				yum = rand() % 48;
				if (alienlist[yum].getHP() > 0) 
				{
					float tempbugx = alienlist[yum].getPosition().x;
					float tempbugy = alienlist[yum].getPosition().y;
					float tempssx = spaceship.getPosition().x + 12.5;
					float tempssy = spaceship.getPosition().y + 12.5;

					float xval = tempssx - tempbugx;
					float yval = tempssy - tempbugy;

					float normal = sqrt((xval*xval) + (yval*yval));

					movex = xval / normal;
					movey = yval / normal;
					Bulletlist[yum].setPosition(alienlist[yum].getPosition()); 
					Bulletlist[yum].move(0.05 * movex, 0.05 * movey);
				}
			}
			if (!Bulletlist[yum].isInbounds('d'))
			{
				Bulletlist[yum].setPosition(sf::Vector2f(-600, -600));
			}
			if (Bulletlist[yum].getPosition() != sf::Vector2f(-600, -600))
			{
				Bulletlist[yum].move(0.05 * movex, 0.05 * movey);
			}
			//for (int i = 0; i < Bulletlist.size() - 1; i++)
				//spaceship.hit(Bulletlist[i]);

			
			if (shootthebulletfromaliens1 == 1 && Bulletlist[zap].getPosition() == sf::Vector2f(-600, -600)) // <-REPLACE WITH-> (when time is greater than something but less than something else && Bulletlist[zap].getPosition() == sf::Vector2f(-600, -600))
			{
				zap = rand() % 48;
				if (alienlist[zap].getHP() > 0)
				{
					Bulletlist[zap].setPosition(alienlist[zap].getPosition());
					Bulletlist[zap].move(0.1 * movexh, 0.04 * moveyh);
				}
			}
			float tempbugx = Bulletlist[zap].getPosition().x;
			float tempbugy = alienlist[zap].getPosition().y;
			float tempssx = spaceship.getPosition().x + 12.5;
			float tempssy = spaceship.getPosition().y + 12.5;

			float xval = tempssx - tempbugx;
			float yval = tempssy - tempbugy;

			float normal = sqrt((xval * xval) + (yval * yval));

			movexh = xval / normal;
			moveyh = yval / normal;
			if (!Bulletlist[zap].isInbounds('d'))
			{
				Bulletlist[zap].setPosition(sf::Vector2f(-600, -600));
			}

			if (Bulletlist[zap].getPosition() != sf::Vector2f(-600, -600))
			{
				Bulletlist[zap].move(0.1 * movexh, 0.04 * moveyh);
			}
			//for (int i = 0; i < Bulletlist.size() - 1; i++)
				//spaceship.hit(Bulletlist[i]);

			
			if (shootthebulletfromaliens2 == 1 && Bulletlist[pop].getPosition() == sf::Vector2f(-600, -600))
			{
				pop = rand() % 48;
				if (alienlist[pop].getHP() > 0)
				{
					Bulletlist[pop].setPosition(alienlist[pop].getPosition());
					Bulletlist[pop].move(0, 0.05);
				}
			}
			if (!Bulletlist[pop].isInbounds('d'))
			{
				Bulletlist[pop].setPosition(sf::Vector2f(-600, -600));
			}

			if (Bulletlist[pop].getPosition() != sf::Vector2f(-600, -600))
			{
				Bulletlist[pop].move(0, 0.05);
			}
			//for (int i = 0; i < Bulletlist.size() - 1; i++)
				//spaceship.hit(Bulletlist[i]);


			if (shootthebulletfromaliens3 == 1 && Bulletlist[hat].getPosition() == sf::Vector2f(-600, -600)) // <-REPLACE WITH-> (when time is greater than something but less than something else && Bulletlist[x].getPosition() == sf::Vector2f(-600, -600))
			{
				hat = rand() % 48;
				if (alienlist[hat].getHP() > 0)
				{
					float tempbugx = alienlist[hat].getPosition().x;
					float tempbugy = alienlist[hat].getPosition().y;
					float tempssx = spaceship.getPosition().x + 12.5;
					float tempssy = spaceship.getPosition().y + 12.5;

					float xval = tempssx - tempbugx;
					float yval = tempssy - tempbugy;

					float normal = sqrt(pow(xval, 2) + pow(yval, 2));

					movex1 = xval / normal;
					movey1 = yval / normal;
					Bulletlist[hat].setPosition(alienlist[hat].getPosition());
					Bulletlist[hat].move(0.05 * movex1, 0.05 * movey1);
				}
			}
			if (!Bulletlist[hat].isInbounds('d'))
			{
				Bulletlist[hat].setPosition(sf::Vector2f(-600, -600));
			}
			if (Bulletlist[hat].getPosition() != sf::Vector2f(-600, -600))
			{
				Bulletlist[hat].move(0.05 * movex1, 0.05 * movey1);
			}

			if (shootthebulletfromaliens4 == 1 && Bulletlist[rap].getPosition() == sf::Vector2f(-600, -600))
			{
				rap = rand() % 48;
				if (alienlist[rap].getHP() > 0)
				{
					Bulletlist[rap].setPosition(alienlist[rap].getPosition());
					Bulletlist[rap].move(0, 0.05);
				}
			}
			if (!Bulletlist[rap].isInbounds('d'))
			{
				Bulletlist[rap].setPosition(sf::Vector2f(-600, -600));
			}

			if (Bulletlist[rap].getPosition() != sf::Vector2f(-600, -600))
			{
				Bulletlist[rap].move(0, 0.05);
			}

			for (int i = 0; i < Bulletlist.size() - 1; i++)
				spaceship.hit(Bulletlist[i]);
		}
		else
		{
			for (int i = 0; i < Bulletlist.size() - 1; i++)
			{
				Bulletlist[i].setFillColor(sf::Color::Transparent);
			}
		}
		
		window.draw(lhand);
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