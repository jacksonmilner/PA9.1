#pragma once
#include "mainShip.h"

class Alien : public sf::CircleShape
{
public:
	Alien(const double& newRadius, const sf::Color& newColor,
		const sf::Vector2f& newPosition, const int& newtype) : sf::CircleShape(newRadius)
	{
		this->setFillColor(newColor);
		this->setPosition(newPosition);
		type = newtype;
		setHP();
	}
	void setHP();
	int getHP();
	void hit();
private:
	int type;
	int hp;
};

void Alien::setHP()
{
	switch (type)
	{
	case 1:
		hp = 1;
		break;
	case 2:
		hp = 2;
		break;
	default:
		break;
	}
}
int Alien::getHP()
{
	return hp;
}

void Alien::hit()
{
	hp--;
}

