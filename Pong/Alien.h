#pragma once
#include "mainShip.h"

class Alien : public spaceShip
{
public:
	Alien(const double& newRadius, const sf::Color& newColor,
		const sf::Vector2f& newPosition, int type) : spaceShip(newRadius, newColor, newPosition)
	{
		this->setFillColor(newColor);
		this->setPosition(newPosition);
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

