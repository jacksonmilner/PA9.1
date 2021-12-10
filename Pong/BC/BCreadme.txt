Bradley C. Logs

A program that runs a game very similar to that of space invaders. This folder is here to hold the code I began
when trying to organize it. Most of the code/object is done in one function and I would prefer it to be done nice
and in classes. Since you work too slow right now at your current level to rewrite the current code into a more 
organized program over break/ on free time. 

All .h files in the BC folder are the ones you scrapped for later. Make sure to look over them, they 
can be easily salvaged.

You will get better from now on.Good luck bruh, no excuses next time!

TO DO LIST:
-Sort required classes
	GameEntity class that holds a circle as a member(or possibly a rectangle for messing around w sprites)
		~Let it have a virtual shoot function to be overridden by each entity
	*Boss class that inherits from GameObject
	*Ship class that inherits from GameObject
	*Alien class that inherits from GameObject
		~
	*Bullet class that inherits from GameObject
	*Possible multiple classes for differently behaving aliens?
	*Class that holds the alien formation (probably with a vector member)
	*Class that holds the bullets used in the program (probably with a vector member) OR implement
	dynamic bullets into the shoot functions






















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
