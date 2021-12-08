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
	void initWindow();
	void initVars();
	void update();
	void render();
	bool isRunning();
	void inputCheck();
	void printStartScreen();

	void setScore(int newscore);
	int getScore()
	{
		return mscore;
	}

	void run_app();
private:
	int mscore;
	sf::RenderWindow* mWindow;
	sf::VideoMode mVideoMode;
	sf::Event mEvent;
	spaceShip mPlayer;
	bool gameRunning;

	std::vector<Alien> alienlist;
};

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
			mWindow->close();
			break;
		case sf::Event::KeyPressed:
			if (mEvent.key.code == )
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

void RunApp::setScore(int newscore)
{
	mscore = newscore;
}

void RunApp::run_app()
{
	
}


