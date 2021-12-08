#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include <vector>
#include "bullet.h"
#include "mainShip.h"
#include "Alien.h"
#include "Andy.h"
#include "spaceShip.h"
#include <time.h>

using std::vector;

#define Pi 3.14159265

class RunApp
{
public:
	RunApp(int score)
	{
		score = 0;
		//render();
	/*	initWindow();
		initVars();*/
	}
	RunApp();
	~RunApp();

	void setScore(int newscore);
	int getScore()
	{
		return mscore;
	}
	void run_app();



	////BC TESTS
	//void testrun_app();

	//void initWindow();
	//void initVars();
	//void initTextures();

	//void update();
	//void render();
	//bool isRunning();
	void pollEventUpdate();
	void updateBullets();
	//void inputUpdate();
	//void printStartScreen();


private:
	//BC TEST v
	int mscore;
	sf::RenderWindow* mWindow;
	//sf::VideoMode mVideoMode;
	sf::Event mEvent;
	spaceShip mPlayer;
	//spaceShip2 mtestPlayer;
	//bool gameRunning;

	sf::Texture* andy;
	sf::Sprite boss;

	//BC TEST ^

	std::vector<Alien> alienlist;
	std::vector<Bullet> Bulletlist;
};

RunApp::RunApp()
{
	mPlayer = spaceShip(15, sf::Color::Black, sf::Vector2f(mWindow->getSize().x / 2, mWindow->getSize().y - 90));
	mscore = 0;
	andy = new sf::Texture();
	andy->loadFromFile("andy_boss.png");

}

RunApp::~RunApp()
{

}

//void RunApp::run_app()
//{
//	srand(time(0));
//	int yum = 0;
//	int zap = 0;
//	int pop = 0;
//	int rap = 0;
//	int hat = 0;
//	int counterup = 0;
//	int shootthebulletfromaliens = 0;
//	int shootthebulletfromaliens1 = 0;
//	int shootthebulletfromaliens2 = 0;
//	int shootthebulletfromaliens3 = 0;
//	int shootthebulletfromaliens4 = 0;
//	int andy_timer = 0;
//
//
//	//spaceShip spaceship(15, sf::Color::Black, sf::Vector2f(mWindow->getSize().x / 2, mWindow->getSize().y - 90));
//	//Bullet bullet1(5, sf::Color::Yellow, sf::Vector2f(600, 600));
//	sf::Texture t;
//	t.loadFromFile("Space-Free-PNG-Image.png");
//	sf::Sprite background(t);
//	int lhand_moving_right = 1;
//	Bullet lhand(25, sf::Color::Yellow, sf::Vector2f(600, 600));
//	Bullet rhand(25, sf::Color::Yellow, sf::Vector2f(600, 600));
//
//
//
//	Andy andy(25, sf::Color::Cyan, sf::Vector2f(mWindow->getSize().x / 2, mWindow->getSize().y / 2), 25);
//	int stage2 = andy.getHP();
//	bool previousShootKeyState;
//	int getsize = (mWindow->getSize().x - 240) / 12;
//	int x1 = -1;
//	int x2 = -1;
//	int x3 = -1;
//	int x4 = -1;
//	bool bosstime = false;
//	int gameState = 0;
//	int x = mWindow->getSize().x / 14;
//	//for (int j = 0; j < 12; j++)
//	//{
//	//	alienlist.push_back(Alien(10, sf::Color::Blue, sf::Vector2f((x * j) + x, mWindow->getSize().y - 400), 1));
//	//	Bulletlist.push_back(Bullet(5, sf::Color::Yellow, sf::Vector2f(-600, -600))); //change color
//	//}
//	//for (int e = 0; e < 12; e++)
//	//{
//	//	alienlist.push_back(Alien(10, sf::Color::Magenta, sf::Vector2f((x * e) + x, mWindow->getSize().y - 430), 2));
//	//	Bulletlist.push_back(Bullet(5, sf::Color::Yellow, sf::Vector2f(-600, -600))); //change color
//	//}
//	//for (int b = 0; b < 12; b++)
//	//{
//	//	alienlist.push_back(Alien(10, sf::Color::Red, sf::Vector2f((x * b) + x, mWindow->getSize().y - 460), 3));
//	//	Bulletlist.push_back(Bullet(5, sf::Color::Yellow, sf::Vector2f(-600, -600))); //change color
//	//}
//	//for (int f = 0; f < 12; f++)
//	//{
//	//	alienlist.push_back(Alien(10, sf::Color::Green, sf::Vector2f((x * f) + x, mWindow->getSize().y - 490), 4));
//	//	Bulletlist.push_back(Bullet(5, sf::Color::Yellow, sf::Vector2f(-600, -600))); //change color
//	//}
//	float movex = 0, movey = 0;
//
//	while (mWindow->isOpen())
//	{
//		int aliensdead = 0;
//		pollEventUpdate();
//		if (mPlayer.getHP() == 0)
//		{
//			//LOSE GAME
//			std::cout << std::endl << "You have perished" << std::endl;
//			mWindow->clear();
//			mWindow->close();
//		}
//		if (andy.getHP() == 0)
//		{
//			//WON GAME
//			mWindow->clear();
//			mWindow->close();
//		}
//
//
//		////if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && spaceship.isInbounds('r'))
//		////{
//		////	spaceship.move(0.11, 0);
//		////}
//		////if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && spaceship.isInbounds('l'))
//		////{
//		////	spaceship.move(-0.11, 0);
//		////}
//
//		for (int j = 0; j < 12; j++)
//			alienlist[j].move(x1 * .005, 0);
//		for (int b = 12; b < 24; b++)
//			alienlist[b].move(x2 * -.008, 0);
//		for (int e = 24; e < 36; e++)
//			alienlist[e].move(x3 * .01, 0);
//		for (int v = 36; v < 48; v++)
//			alienlist[v].move(x4 * -0.012, 0);
//
//		if (!alienlist[0].isInbounds('l'))
//			x1 *= -1;
//		if (!alienlist[11].isInbounds('r'))
//			x1 *= -1;
//		if (!alienlist[12].isInbounds('l'))
//			x2 *= -1;
//		if (!alienlist[23].isInbounds('r'))
//			x2 *= -1;
//		if (!alienlist[24].isInbounds('l'))
//			x3 *= -1;
//		if (!alienlist[35].isInbounds('r'))
//			x3 *= -1;
//		if (!alienlist[36].isInbounds('l'))
//			x4 *= -1;
//		if (!alienlist[47].isInbounds('r'))
//			x4 *= -1;
//
//		
//	
//		for (int i = 0; i < alienlist.size(); i++)
//		{
//			if (alienlist[i].hit(bullet1))
//			{
//				bullet1.setPosition(sf::Vector2f(600, 600));
//			}
//		}
//		
//		for (int i = 0; i < alienlist.size(); i++)
//		{
//			if (alienlist[i].getHP() == 0)
//				aliensdead++;
//		}
//		if (aliensdead == 48)
//		{
//			gameState = 1;
//		}
//		
//
//
//		if (gameState == 1)
//		{
//			if (andy.hit(bullet1))
//			{
//				bullet1.setPosition(sf::Vector2f(600, 600));
//				andy.updateHealthBar();
//			};
//		}
//		if (gameState == 1 && andy.getHP() > 0) //&& andy.getHP()>stage2)
//		{
//			if (andy_timer < 100000)
//			{
//				if (andy_timer % 10000 == 0)
//				{
//					andy.setPosition(sf::Vector2f((rand() % (400 - 100 + 1) + 100), (rand() % (200 - 100 + 1) + 100)));
//				}
//			}
//			else
//			{
//				if (andy_timer > 100000 && andy_timer < 101000)
//				{
//					andy.setPosition(sf::Vector2f(mWindow->getSize().x / 2, mWindow->getSize().y / 2));
//				}
//				else
//				{
//
//					float andymovingx = sin(andy_timer/1000*Pi);
//					float andymovingy = sin(andy_timer / 1000 * Pi)*cos(andy_timer / 1000 * Pi);
//					//andy.move(0.1 * andymovingx, 0.1 * andymovingy); DONT KNOW HOW TO FIX ANDY MOVE FUNCTION
//				}
//			}
//			mWindow->draw(andy);
//			mWindow->draw(andy.getHealthBar());
//		}
//		if ((gameState == 1 && andy.getHP() > 0) && andy.getHP() <= stage2)
//		{
//			
//		}
//		for (int i = 0; i <= alienlist.size() - 1; i++)
//		{
//			if (alienlist[i].getHP() != 0)
//				mWindow->draw(alienlist[i]);
//			mWindow->draw(Bulletlist[i]);
//		}
//
//		if (aliensdead < 48)
//		{
//			
//			counterup++;
//			if (counterup > 5000)
//			{
//				shootthebulletfromaliens = 1;
//			}
//			if (counterup > 10000)
//			{
//				shootthebulletfromaliens1 = 1;
//			}
//			if (counterup > 15000)
//			{
//				shootthebulletfromaliens2 = 1;
//				shootthebulletfromaliens3 = 1;
//				shootthebulletfromaliens4 = 1;
//			}
//
//			
//			if (shootthebulletfromaliens == 1 && Bulletlist[yum].getPosition() == sf::Vector2f(-600, -600)) // <-REPLACE WITH-> (when time is greater than something but less than something else && Bulletlist[x].getPosition() == sf::Vector2f(-600, -600))
//			{
//				yum = rand() % 48;
//				if (alienlist[yum].getHP() > 0) 
//				{
//					float tempbugx = alienlist[yum].getPosition().x;
//					float tempbugy = alienlist[yum].getPosition().y;
//					float tempssx = mPlayer.getPosition().x + 12.5;
//					float tempssy = mPlayer.getPosition().y + 12.5;
//
//					float xval = tempssx - tempbugx;
//					float yval = tempssy - tempbugy;
//
//					float normal = sqrt((xval*xval) + (yval*yval));
//
//					movex = xval / normal;
//					movey = yval / normal;
//					Bulletlist[yum].setPosition(alienlist[yum].getPosition()); 
//					Bulletlist[yum].move(0.05 * movex, 0.05 * movey);
//				}
//			}
//			if (!Bulletlist[yum].isInbounds('d'))
//			{
//				Bulletlist[yum].setPosition(sf::Vector2f(-600, -600));
//			}
//			if (Bulletlist[yum].getPosition() != sf::Vector2f(-600, -600))
//			{
//				Bulletlist[yum].move(0.05 * movex, 0.05 * movey);
//			}
//			//for (int i = 0; i < Bulletlist.size() - 1; i++)
//				//spaceship.hit(Bulletlist[i]);
//
//			float moveyh = 0;
//			float movexh = 0;
//			if (shootthebulletfromaliens1 == 1 && Bulletlist[zap].getPosition() == sf::Vector2f(-600, -600)) // <-REPLACE WITH-> (when time is greater than something but less than something else && Bulletlist[zap].getPosition() == sf::Vector2f(-600, -600))
//			{
//				zap = rand() % 48;
//				if (alienlist[zap].getHP() > 0)
//				{
//					Bulletlist[zap].setPosition(alienlist[zap].getPosition());
//					Bulletlist[zap].move(0.1 * movexh, 0.04 * moveyh);
//				}
//			}
//			float tempbugx = Bulletlist[zap].getPosition().x;
//			float tempbugy = alienlist[zap].getPosition().y;
//			float tempssx = mPlayer.getPosition().x + 12.5;
//			float tempssy = mPlayer.getPosition().y + 12.5;
//
//			float xval = tempssx - tempbugx;
//			float yval = tempssy - tempbugy;
//
//			float normal = sqrt((xval * xval) + (yval * yval));
//
//			movexh = xval / normal;
//			moveyh = yval / normal;
//			if (!Bulletlist[zap].isInbounds('d'))
//			{
//				Bulletlist[zap].setPosition(sf::Vector2f(-600, -600));
//			}
//
//			if (Bulletlist[zap].getPosition() != sf::Vector2f(-600, -600))
//			{
//				Bulletlist[zap].move(0.1 * movexh, 0.04 * moveyh);
//			}
//			//for (int i = 0; i < Bulletlist.size() - 1; i++)
//				//spaceship.hit(Bulletlist[i]);
//
//			
//			if (shootthebulletfromaliens2 == 1 && Bulletlist[pop].getPosition() == sf::Vector2f(-600, -600))
//			{
//				pop = rand() % 48;
//				if (alienlist[pop].getHP() > 0)
//				{
//					Bulletlist[pop].setPosition(alienlist[pop].getPosition());
//					Bulletlist[pop].move(0, 0.05);
//				}
//			}
//			if (!Bulletlist[pop].isInbounds('d'))
//			{
//				Bulletlist[pop].setPosition(sf::Vector2f(-600, -600));
//			}
//
//			if (Bulletlist[pop].getPosition() != sf::Vector2f(-600, -600))
//			{
//				Bulletlist[pop].move(0, 0.05);
//			}
//			//for (int i = 0; i < Bulletlist.size() - 1; i++)
//				//spaceship.hit(Bulletlist[i]);
//
//
//			if (shootthebulletfromaliens3 == 1 && Bulletlist[hat].getPosition() == sf::Vector2f(-600, -600)) // <-REPLACE WITH-> (when time is greater than something but less than something else && Bulletlist[x].getPosition() == sf::Vector2f(-600, -600))
//			{
//				hat = rand() % 48;
//				if (alienlist[hat].getHP() > 0)
//				{
//					float tempbugx = alienlist[hat].getPosition().x;
//					float tempbugy = alienlist[hat].getPosition().y;
//					float tempssx = mPlayer.getPosition().x + 12.5;
//					float tempssy = mPlayer.getPosition().y + 12.5;
//
//					float xval = tempssx - tempbugx;
//					float yval = tempssy - tempbugy;
//
//					float normal = sqrt(pow(xval, 2) + pow(yval, 2));
//
//					movex = xval / normal;
//					movey = yval / normal;
//					Bulletlist[hat].setPosition(alienlist[hat].getPosition());
//					Bulletlist[hat].move(0.05 * movex, 0.05 * movey);
//				}
//			}
//			if (!Bulletlist[hat].isInbounds('d'))
//			{
//				Bulletlist[hat].setPosition(sf::Vector2f(-600, -600));
//			}
//			if (Bulletlist[hat].getPosition() != sf::Vector2f(-600, -600))
//			{
//				Bulletlist[hat].move(0.05 * movex, 0.05 * movey);
//			}
//
//			if (shootthebulletfromaliens2 == 1 && Bulletlist[rap].getPosition() == sf::Vector2f(-600, -600))
//			{
//				rap = rand() % 48;
//				if (alienlist[rap].getHP() > 0)
//				{
//					Bulletlist[rap].setPosition(alienlist[rap].getPosition());
//					Bulletlist[rap].move(0, 0.05);
//				}
//			}
//			if (!Bulletlist[rap].isInbounds('d'))
//			{
//				Bulletlist[rap].setPosition(sf::Vector2f(-600, -600));
//			}
//
//			if (Bulletlist[rap].getPosition() != sf::Vector2f(-600, -600))
//			{
//				Bulletlist[rap].move(0, 0.05);
//			}
//
//			for (int i = 0; i < Bulletlist.size() - 1; i++)
//				mPlayer.hit(Bulletlist[i]);
//		}
//		else
//		{
//			for (int i = 0; i < Bulletlist.size() - 1; i++)
//			{
//				Bulletlist[i].setFillColor(sf::Color::Transparent);
//			}
//		}
//		
//	//	mWindow->draw(lhand);
//	//	mWindow->draw(bullet1);
//		mWindow->clear();
//		mWindow->draw(mPlayer);
//		mWindow->display();
//	//	andy_timer++;
//	}
//}

void RunApp::setScore(int newscore)
{
	mscore = newscore;
}

void RunApp::pollEventUpdate()
{
	while (mWindow->pollEvent(mEvent))
	{
		switch (mEvent.type)
		{
		case sf::Event::Closed:
			mWindow->close();
			break;
		default:
			break;
		}
	}
}

void RunApp::updateBullets()
{

}