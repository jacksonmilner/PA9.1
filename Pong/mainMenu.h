#pragma once
#include <SFML/Graphics.hpp>

class MainMenu
{
public:

	MainMenu(float width, float height);

	void draw(sf::RenderWindow& window);
	void MoveUp();
	void MoveDown();
};
