#pragma once
#include <SFML/Graphics.hpp>

class spaceShip2
{
public:
	spaceShip2();
	~spaceShip2();

	void initShape();
	void setPos(sf::Vector2f bruh);

private:
	sf::CircleShape mShape;
	void update();
	void render(sf::RenderTarget* target);
};

spaceShip2::spaceShip2()
{

}

spaceShip2::~spaceShip2()
{

}

void spaceShip2::initShape()
{
	mShape.setFillColor(sf::Color::Yellow);
	mShape.setRadius(15);
//	mShape.setPosition(sf::Vector2f(window.getSize().x / 2, window.getSize().y - 90)))
}

void spaceShip2::setPos(sf::Vector2f bruh)
{
	mShape.setPosition(bruh);
}

void spaceShip2::update()
{

}

void spaceShip2::render(sf::RenderTarget* target)
{
	target->draw(mShape);
}