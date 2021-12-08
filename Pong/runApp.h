#pragma once
#include "mainShip.h"




class RunApp
{
public:
	RunApp();
	~RunApp();

	void initWindow();
	void initVars();
	void update();
	void render();
	bool isRunning();
	void inputCheck();
	void printStartScreen();
private:


	sf::RenderWindow* mWindow;
	sf::VideoMode mVideoMode;
	sf::Event mEvent;
	spaceShip mPlayer;
	bool gameRunning;
	int score;
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