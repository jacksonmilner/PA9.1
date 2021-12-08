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

class RunApp2
{
public:
	RunApp2(int score)
	{
		score = 0;
		render();
		initWindow();
		initVars();
	}
	RunApp2();
	~RunApp2();

	void setScore(int newscore);
	int getScore()
	{
		return mscore;
	}



	//BC TESTS
	void testrun_app();


	void update();
	void render();
	bool isRunning();
	void pollEventUpdate();
	void printStartScreen();
	void initWindow();
	void initVars();


private:
	//BC TEST v
	int mscore;
	sf::RenderWindow* mWindow;
	sf::VideoMode mVideoMode;
	sf::Event mEvent;
	spaceShip mtestPlayer;
	bool gameRunning;

	//BC TEST ^

	std::vector<Alien> alienlist;
	std::vector<Bullet> Bulletlist;
};

RunApp2::RunApp2()
{
	initVars();
	//initWindow();
}

RunApp2::~RunApp2()
{
	delete mWindow;
	
}

void RunApp2::testrun_app()
{
	initWindow();

	sf::Texture t;
	t.loadFromFile("Space-Free-PNG-Image.png");
	sf::Sprite background(t);
	while (isRunning())
	{
		update();
		render();
	}




}

void RunApp2::initWindow()
{
	mWindow = new sf::RenderWindow(sf::VideoMode(500, 500), "Your Doom!");
}

void RunApp2::initVars()
{
	gameRunning = true;
}



void RunApp2::update()
{
	pollEventUpdate();

	mtestPlayer.update();
}

void RunApp2::render()
{
	mWindow->clear();

	mWindow->draw(mtestPlayer);

	mWindow->display();
}

bool RunApp2::isRunning()
{
	return mWindow->isOpen();
}

void RunApp2::pollEventUpdate()
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

void RunApp2::printStartScreen()
{
	if (gameRunning == true)
	{

	}
}