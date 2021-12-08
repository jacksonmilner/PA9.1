#pragma once
#include <SFML/Graphics.hpp>
#include "Alien.h"
#include <vector>

class Formation
{
public:
	Formation();
	~Formation();

	void movement();

private:
	std::vector<Alien> alienList
};

Formation::Formation()
{
	for (int j = 0; j < 12; j++)
	{
		alienList.push_back(Alien(10, sf::Color::Blue, sf::Vector2f(((500.0f / 14.0f) * j) + (500.0f / 14.0f), 100.0f), 1));
	}
	for (int e = 0; e < 12; e++)
	{
		alienList.push_back(Alien(10, sf::Color::Magenta, sf::Vector2f(((500 / 14) * e) + (500 / 14), 70.0f), 2));
	}
	for (int b = 0; b < 12; b++)
	{
		alienList.push_back(Alien(10, sf::Color::Red, sf::Vector2f(((500 / 14) * b) + (500 / 14), 40.0f), 3));
	}
	for (int f = 0; f < 12; f++)
	{
		alienList.push_back(Alien(10, sf::Color::Green, sf::Vector2f(((500 / 14) * f) + (500 / 14), 10.0f), 4));
	}
}