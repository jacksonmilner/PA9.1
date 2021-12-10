#pragma once
#include "Alien.h"
class Andy : public Alien
{
public:
	Andy(const double& newRadius, const sf::Color& newColor,
		const sf::Vector2f& newPosition, const int& type = 50) : Alien(newRadius, sf::Color::White, newPosition, type)
	{
		healthBar.setFillColor(sf::Color::Red);
		healthBar.setPosition(sf::Vector2f(100, 10));
		healthBar.setSize(sf::Vector2f(300, 25));
		for (int i = 0; i < 10; i++)
		{
			ammo.push_back(Bullet(5, sf::Color::Yellow, sf::Vector2f(-600, -600)));
		}
	}
	void move(float x, float y)
	{
		this->setPosition(sf::Vector2f(this->getPosition().x + x, this->getPosition().y + y));
	}
	void reload();
	bool reloaded();
	void updateHealthBar();
	void spray();
	std::vector<Bullet>& getAmmo();
	sf::RectangleShape getHealthBar();

private:
	sf::RectangleShape healthBar;
	std::vector<Bullet> ammo;
};

