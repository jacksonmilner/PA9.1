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
#include "mainMenu.h"

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
	void pollEventUpdate();
	void render();
	bool isRunning();

private:
	int mscore;
	sf::RenderWindow* mWindow;
	sf::Event mEvent;
	spaceShip* mPlayer;
	bool gameRunning;
	int score;


	std::vector<Alien> alienlist;
	std::vector<Bullet> Bulletlist;
};


