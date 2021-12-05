#pragma once

#include <SFML/Graphics.hpp>

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
};

bool Bullet::isInbounds(char side)
{
	if (side == 'u' && this->getPosition().y > 0)
	{
		return true;
	}

	return false;
}