#pragma once

class Alien : public sf::CircleShape
{
public:
	Alien(const double& newRadius, const sf::Color& newColor,
		const sf::Vector2f& newPosition, const int& newHP) : sf::CircleShape(newRadius)
	{
		this->setFillColor(newColor);
		this->setPosition(newPosition);
		hp = newHP;
	}
	bool isInbounds(char side);

	int getHP();
	bool hit(Bullet* shot);
	bool hit(Bullet shot);
	void shoot1(spaceShip* player);
	void shoot2(spaceShip* player);
	void shoot3(spaceShip* player);
private:
	int hp;
};
bool Alien::isInbounds(char side)
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


int Alien::getHP()
{
	return hp;
}

bool Alien::hit(Bullet* shot)
{
	if (this->getGlobalBounds().intersects(shot->getGlobalBounds()) && hp != 0)
	{
		hp--;
		return true;
	}
	return false;
}

bool Alien::hit(Bullet shot)
{
	if (this->getGlobalBounds().intersects(shot.getGlobalBounds()) && hp != 0)
	{
		hp--;
		return true;
	}
	return false;
}

void Alien::shoot1(spaceShip* player)
{
	Bullet* bullet = new Bullet(5, sf::Color::Yellow, this->getPosition());

	if (hp != 0)
	{
		float tempbugx = this->getPosition().x;
		float tempbugy = this->getPosition().y;
		float tempssx = player->getPosition().x + 12.5;
		float tempssy = player->getPosition().y + 12.5;

		float xval = tempssx - tempbugx;
		float yval = tempssy - tempbugy;

		float normal = sqrt((xval * xval) + (yval * yval));

		float movex = xval / normal;
		float movey = yval / normal;

		while (bullet != nullptr)
		{
			bullet->move(0.05 * movex, 0.05 * movey);
			if (bullet->isInbounds('d'))
			{
				delete bullet;
				bullet = nullptr;
			}
		}
	}
}

void Alien::shoot2(spaceShip* player)
{
	Bullet* bullet = new Bullet(5, sf::Color::Yellow, this->getPosition());

	if (hp != 0)
	{
		float tempbugx = bullet->getPosition().x;
		float tempbugy = this->getPosition().y;
		float tempssx = player->getPosition().x + 12.5;
		float tempssy = player->getPosition().y + 12.5;

		float xval = tempssx - tempbugx;
		float yval = tempssy - tempbugy;

		float normal = sqrt((xval * xval) + (yval * yval));

		float movex = xval / normal;
		float movey = yval / normal;
	
		while (bullet != nullptr)
		{
			bullet->move(0.1 * movex, 0.04 * movey);
			if (bullet->isInbounds('d'))
			{
				delete bullet;
				bullet = nullptr;
			}
		}
	}
}

void Alien::shoot3(spaceShip* player)
{
	Bullet* bullet = new Bullet(5, sf::Color::Yellow, this->getPosition());

	if (hp != 0)
	{
		float tempbugx = this->getPosition().x;
		float tempbugy = this->getPosition().y;
		float tempssx = player->getPosition().x + 12.5;
		float tempssy = player->getPosition().y + 12.5;

		float xval = tempssx - tempbugx;
		float yval = tempssy - tempbugy;

		float normal = sqrt((xval * xval) + (yval * yval));

		float movex = xval / normal;
		float movey = yval / normal;
		bullet->setPosition(this->getPosition());
		bullet->move(0.05 * movex, 0.05 * movey);

		while (bullet != nullptr)
		{
			bullet->move(0, 0.05);
			if (bullet->isInbounds('d'))
			{
				delete bullet;
				bullet = nullptr;
			}
		}
	}
}
