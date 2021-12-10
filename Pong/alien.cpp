#include "Alien.h"
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

bool Alien::hit(Bullet shot)
{
	if (this->getGlobalBounds().intersects(shot.getGlobalBounds()) && hp != 0)
	{
		hp--;
		return true;
	}
	return false;
}
