#pragma once
#define PLAYER_BULLET true
#define ENEMY_BULLET false
#define TYPE1 1
#define TYPE2 2
#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>
class Bullet : public sf::CircleShape
{
public:
	Bullet(const double& newRadius, const sf::Color& newColor,
		const sf::Vector2f& newPosition) :
		sf::CircleShape(newRadius)
	{
		this->setFillColor(newColor);
		this->setPosition(newPosition);
	}
	bool isInbounds(char side);

private:
	// double mRadius;
	char bullet_type;
};

bool Bullet::isInbounds(char side)
{
	if (side == 'u' && this->getPosition().y > 0)
	{
		return true;
	}
	if (side == 'd' && this->getPosition().y < 500)
	{
		return true;
	}
	if (side == 'r' && this->getPosition().x < 550)
	{
		return true;
	}

	return false;
}