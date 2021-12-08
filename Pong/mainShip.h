#pragma once
#include <SFML/Graphics.hpp>

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
	void update();
	void updateInput();

	int getHP()
	{
		return hp;
	}
	void setHP(int newData)
	{
		hp = newData;
	}

	
	virtual void shoot()
	{
		sf::Vector2f center = sf::Vector2f(this->getPosition().x + 11, this->getPosition().y);
		Bullet* bullet = new Bullet(5, sf::Color::Yellow, center);

		while (bullet != nullptr)
		{
			bullet->move(0, -0.4);
			if (!bullet->isInbounds('u'))
			{
				delete bullet;
				bullet = nullptr;
			}
		}
	}

private:
	// double mRadius;
	int hp;
};

spaceShip::spaceShip()
{
	this->setRadius(15);
	this->setFillColor(sf::Color::Black);
	this->setPosition(sf::Vector2f(250.0f, 410.0f));
	hp = 1;
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

bool spaceShip::hit(Bullet shot)
{
	if (this->getGlobalBounds().intersects(shot.getGlobalBounds()) && hp != 0)
	{
		hp--;
		return true;
	}
	return false;
}

void spaceShip::update()
{
	updateInput();
}

void spaceShip::updateInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && isInbounds('r'))
	{
		this->move(0.11, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && isInbounds('l'))
	{
		this->move(-0.11, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		this->shoot();
	}

}