#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>
class Bullet
{
public:
	Bullet();
	Bullet(sf::Texture& texture, float x, float y, float movespd);
	~Bullet();

	void update();
	void render(sf::RenderTarget* target);

private:
	sf::Sprite mCircle; 

	sf::Vector2f mDirection;
	float mMovementSpeed;
};

Bullet::Bullet()
{

}

Bullet::Bullet(sf::Texture& texture, float x, float y, float movespd)
{
	mCircle.setTexture(texture);
	mDirection.x = x;
	mDirection.y = y;
	mMovementSpeed = movespd;
}

Bullet::~Bullet()
{
}

void Bullet::update()
{
	mCircle.move(mMovementSpeed * mDirection);
}

void Bullet::render(sf::RenderTarget* target)
{
	target->draw(mCircle)
}