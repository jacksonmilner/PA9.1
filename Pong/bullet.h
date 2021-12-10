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
		const sf::Vector2f& newPosition, int newhp = 1) : sf::CircleShape(newRadius)
	{
		this->setFillColor(newColor);
		this->setPosition(newPosition);
		hp = newhp;
	}
	bool isInbounds(char side);
	int getHP();

private:
	int hp;
};

