#include "Andy.h"

void Andy::updateHealthBar()
{
	int x = 0;
	x = healthBar.getSize().x - 2;
	healthBar.setSize(sf::Vector2f(x, 30));
}

sf::RectangleShape Andy::getHealthBar()
{
	return healthBar;
}

void Andy::spray()
{
	for (int i = 0; i < 5; i++)
	{
		ammo[i].setPosition(this->getPosition().x + 25, this->getPosition().y + 25);
	}
}
bool Andy::reloaded()
{
	int home = 0;
	for (int i = 0; i < 5; i++)
	{
		if (ammo[i].getPosition() == sf::Vector2f(600, 600))
		{
			home++;
		}
	}
	if (home == 5)
	{
		return true;
	}
	return false;
}
std::vector<Bullet>& Andy::getAmmo()
{
	return ammo;
}
void Andy::reload()
{
	for (int i = 0; i < 5; i++)
	{
		ammo[i].setPosition(sf::Vector2f(-600, -600));
	}
}