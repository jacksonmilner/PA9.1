#include "mainShip.h"
bool spaceShip::hit(Bullet shot)
{
	if (this->getGlobalBounds().intersects(shot.getGlobalBounds()) && hp != 0)
	{
		hp--;
		return true;
	}
	return false;
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