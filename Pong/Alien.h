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
	bool isInbounds(char side);

	void setHP();
	int getHP();
	bool hit(Bullet& shot);
	

private:
	int type;
	int hp;
};
bool Alien::isInbounds(char side)
{
	if (side == 'l' && this->getPosition().x > 0)
	{
		return true;
	}
	if (side == 'r' && this->getPosition().x + 30 < 500)
	{
		return true;
	}

	return false;
}

void Alien::setHP()
{
	switch (type)
	{
	case 1:
		hp = 1;
		break;
	case 2:
		hp = 2;
	case 3:
		hp = 3;
		break;
	case 4:
		hp = 4;
		break;
	case 25:
		hp = 50;
		break;
	default:
		break;
	}
}
int Alien::getHP()
{
	return hp;
}

bool Alien::hit(Bullet& shot)
{
	if (this->getGlobalBounds().intersects(shot.getGlobalBounds()) && hp != 0)
	{
		hp--;
		return true;
	}
	return false;
}

