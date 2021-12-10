#pragma once
#include "bullet.h"

class spaceShip : public sf::CircleShape
{
public:
	~spaceShip();
	spaceShip(const double& newRadius, const sf::Color& newColor,
		const sf::Vector2f& newPosition) : sf::CircleShape(newRadius)
	{
		this->setFillColor(newColor);
		this->setPosition(newPosition);
		hp = 1;
	}
	bool isInbounds(char side);
	bool hit(Bullet shot);
	int getHP()
	{
		return hp;
	}

	virtual void shoot()
	{

	}

private:
	// double mRadius;
	int hp;
};

