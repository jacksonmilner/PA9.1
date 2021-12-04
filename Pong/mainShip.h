#pragma once
#include "ship.h"

class spaceShip : public sf::CircleShape
{
public:
	spaceShip(const double& newRadius, const sf::Color& newColor,
		const sf::Vector2f& newPosition) :
		sf::CircleShape(newRadius)
	{
		this->setFillColor(newColor);
		this->setPosition(newPosition);
	}
	bool isInbounds(char side);
private:
	// double mRadius;
};

bool spaceShip::isInbounds(char side)
{
	if (side == 'l' && this->getPosition().x > 0)
	{
		return true;
	}
	if (side == 'r' && this->getPosition().x + 50 < 500)
	{
		return true;
	}

	return false;
}