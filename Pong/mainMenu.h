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

