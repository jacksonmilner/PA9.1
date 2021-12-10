#pragma once
#include "mainShip.h"

class Alien : public sf::CircleShape
{
public:
	Alien(const double& newRadius, const sf::Color& newColor,
		const sf::Vector2f& newPosition, const int& newHP) : sf::CircleShape(newRadius)
	{
		this->setFillColor(newColor);
		this->setPosition(newPosition);
		hp = newHP;
	}
	bool isInbounds(char side);

	int getHP();
	bool hit(Bullet shot);


private:
	int hp;
};

