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
		const sf::Vector2f& newPosition, int newhp = 1) :
		sf::CircleShape(newRadius)
	{
		this->setFillColor(newColor);
		this->setPosition(newPosition);
		hp = newhp;
	}
	bool isInbounds(char side);
	int getHP();
	void hit();

private:
	// double mRadius;
	char bullet_type;
	int hp;
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

int Bullet::getHP()
{
	return hp;
}

void Bullet::hit()
{
	if (hp != 0)
	{
		hp--;
	}
	else
	{
		hp++;
	}

}