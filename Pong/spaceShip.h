#pragma once
#include <SFML/Graphics.hpp>

class spaceShip2
{
public:
	spaceShip2();
	spaceShip2(sf::Vector2f coords);
	~spaceShip2();
	sf::Vector2f getPos();
	bool isInbounds(char side);

	void update();
	void updateInput();
	void render(sf::RenderTarget* target);

private:
	sf::CircleShape mShape;
	float mMovespd;
	void initShape();
	void initVariables();
	void setPos(sf::Vector2f bruh);
};

spaceShip2::spaceShip2()
{

}

spaceShip2::spaceShip2(sf::Vector2f coords)
{
	mShape.setPosition(coords);

	
}

spaceShip2::~spaceShip2()
{

}

sf::Vector2f spaceShip2::getPos()
{
	return mShape.getPosition();
}

void spaceShip2::initShape()
{
	mShape.setFillColor(sf::Color::Yellow);
	mShape.setRadius(15);
	mShape.setPosition(sf::Vector2f(250, 410));
}

void spaceShip2::initVariables()
{

}

void spaceShip2::setPos(sf::Vector2f bruh)
{
	mShape.setPosition(bruh);
}

void spaceShip2::update()
{

	updateInput();



}

void spaceShip2::updateInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && isInbounds('r'))
	{
		mShape.move(0.11, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && isInbounds('l'))
	{
		mShape.move(-0.11, 0);
	}
}

void spaceShip2::render(sf::RenderTarget* target)
{
	target->draw(mShape);
}

bool spaceShip2::isInbounds(char side)
{
	if (side == 'l' && mShape.getPosition().x > 0)
	{
		return true;
	}
	if (side == 'r' && mShape.getPosition().x + 30 < 500)
	{
		return true;
	}

	return false;
}