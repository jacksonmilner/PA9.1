#pragma once
#include "Alien.h"
class Andy : public Alien
{
public:
	Andy(const double& newRadius, const sf::Color& newColor,
		const sf::Vector2f& newPosition, const int& type = 3) : Alien(newRadius, sf::Color::White, newPosition, type)
	{
		healthBar.setFillColor(sf::Color::Red);
		healthBar.setPosition(sf::Vector2f(0, 10));
		healthBar.setSize(sf::Vector2f(500, 25));

	}
	void updateHealthBar();
	void move();
	sf::RectangleShape getHealthBar();

private:
	sf::RectangleShape healthBar;
};

void Andy::updateHealthBar()
{
	int x = 0;
	x = healthBar.getSize().x;
	healthBar.setSize(sf::Vector2f(x-20, 30));
}

sf::RectangleShape Andy::getHealthBar()
{
	return healthBar;
}
void Andy::move()
{

}