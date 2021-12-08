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


int Alien::getHP()
{
	return hp;
}

bool Alien::hit(Bullet shot)
{
	if (this->getGlobalBounds().intersects(shot.getGlobalBounds()) && hp != 0)
	{
		hp--;
		return true;
	}
	return false;
}

