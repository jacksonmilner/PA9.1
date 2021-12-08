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

	void initWindow();
	void initVars();
	void initTextures();

	void update();
	void render();
	bool isRunning();
	void pollEventUpdate();
	void inputUpdate();
	void printStartScreen();
	void run_app();


private:
	//BC TEST v
	int mscore;
	sf::RenderWindow* mWindow;
	sf::VideoMode mVideoMode;
	sf::Event mEvent;
	spaceShip mPlayer;
	spaceShip2 mtestPlayer;
	bool gameRunning;


	//BC TEST ^

	std::vector<Alien> alienlist;
	std::vector<Bullet> Bulletlist;
};

RunApp2::RunApp2()
{
	initWindow();
	initTextures();
	initVars();
}

RunApp2::~RunApp2()
{

}

