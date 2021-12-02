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

private:
	// double mRadius;
};