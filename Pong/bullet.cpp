#include "bullet.h"
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
	if (side == 'r' && this->getPosition().x < 500)
	{
		return true;
	}
	if (side == 'l' && this->getPosition().x > 0)
	{
		return true;
	}

	return false;
}

int Bullet::getHP()
{
	return hp;
}