#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class MainMenu
{
public:

	MainMenu(float width, float height);
	~MainMenu();
	void draw(sf::RenderWindow& window);
	void MoveUp();
	void MoveDown();

private:
	int mInputSelection;
	sf::Font mFont;
	sf::Text mMenu[3];
};

MainMenu::MainMenu(float width, float height)
{
	//check for 
	if (!mFont.loadFromFile("ARCADECLASSIC.TTF"))
	{
		std::cout << "error loading font" << std::endl;
	}

	mMenu[0].setFont(mFont);
	mMenu[0].setFillColor(sf::Color::White);
	mMenu[0].setString("Play");
	mMenu[0].setCharacterSize(50);
	mMenu[0].setPosition(250, -150);

	mMenu[1].setFont(mFont);
	mMenu[1].setFillColor(sf::Color::White);
	mMenu[1].setString("How to Play");
	mMenu[1].setCharacterSize(50);
	mMenu[1].setPosition(250, -150);

	mMenu[2].setFont(mFont);
	mMenu[2].setFillColor(sf::Color::White);
	mMenu[2].setString("Exit");
	mMenu[2].setCharacterSize(50);
	mMenu[2].setPosition(250, -150);

	mInputSelection = -1;
}

MainMenu::~MainMenu()
{

}

void MainMenu::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < 2; i++)
	{
		window.draw(mMenu[i]);
	}
}

void MainMenu::MoveUp()
{
	if (mInputSelection >= 0)
	{
		mMenu[mInputSelection].setFillColor(sf::Color::White);
		
		mInputSelection--;

		if (mInputSelection == -1)
		{
			mInputSelection = 2;
		}
		mMenu[mInputSelection].setFillColor(sf::Color::Blue);
	}

}

void MainMenu::MoveDown()
{
	if (mInputSelection <= 2)
	{
		mMenu[mInputSelection].setFillColor(sf::Color::White);

		mInputSelection++;
		if (mInputSelection == 2)
		{
			mInputSelection = 0;
		}
			mMenu[mInputSelection].setFillColor(sf::Color::Blue);
	}
}
