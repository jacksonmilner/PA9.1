#pragma once
#include "bullet.h"

class spaceShip : public sf::CircleShape
{
public:
	spaceShip();
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

bool spaceShip::hit(Bullet shot)
{
	if (this->getGlobalBounds().intersects(shot.getGlobalBounds()) && hp != 0)
	{
		hp--;
		return true;
	}
	return false;
}

spaceShip::spaceShip()
{

}

spaceShip::~spaceShip()
{

}

bool spaceShip::isInbounds(char side)
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