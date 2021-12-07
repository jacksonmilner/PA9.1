// This example will use SFML libraries to implement
// the game of Pong

// History: 4/16 - Started from the SFML tutorial code that draws
//                a circle in the window.

#include <SFML/Graphics.hpp>
#include "runApp.h"

int main()
{
	RunApp spaceshipgame(0);
	spaceshipgame.run_app();
////sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");
	//bool previousShootKeyState;
	//spaceShip spaceship(15, sf::Color::Yellow, sf::Vector2f(window.getSize().x / 2, window.getSize().y - 90));
	//Bullet bullet1(5, sf::Color::Yellow, spaceship.getPosition() + sf::Vector2f(15 / 2, -18), 1);

	//int getsize = window.getSize().x / 14;
	//int get13 = 13;
	//int directionbugx = -1;
	//int directionbeex = -1;
	//int directionalienx = -1;
	//int directionenemyx = -1;

	//Alien bug1(10, sf::Color::Blue, sf::Vector2f((0) + getsize, window.getSize().y - 400), 1);
	//Alien bug2(10, sf::Color::Blue, sf::Vector2f(((window.getSize().x) / get13) + getsize, window.getSize().y - 400), 1);
	//Alien bug3(10, sf::Color::Blue, sf::Vector2f(((window.getSize().x) / get13) + getsize * 2, window.getSize().y - 400), 1);
	//Alien bug4(10, sf::Color::Blue, sf::Vector2f(((window.getSize().x) / get13) + getsize * 3, window.getSize().y - 400), 1);
	//Alien bug5(10, sf::Color::Blue, sf::Vector2f(((window.getSize().x) / get13) + getsize * 4, window.getSize().y - 400), 1);
	//Alien bug6(10, sf::Color::Blue, sf::Vector2f(((window.getSize().x) / get13) + getsize * 5, window.getSize().y - 400), 1);
	//Alien bug7(10, sf::Color::Blue, sf::Vector2f(((window.getSize().x) / get13) + getsize * 6, window.getSize().y - 400), 1);
	//Alien bug8(10, sf::Color::Blue, sf::Vector2f(((window.getSize().x) / get13) + getsize * 7, window.getSize().y - 400), 1);
	//Alien bug9(10, sf::Color::Blue, sf::Vector2f(((window.getSize().x) / get13) + getsize * 8, window.getSize().y - 400), 1);
	//Alien bug10(10, sf::Color::Blue, sf::Vector2f(((window.getSize().x) / get13) + getsize * 9, window.getSize().y - 400), 1);
	//Alien bug11(10, sf::Color::Blue, sf::Vector2f(((window.getSize().x) / get13) + getsize * 10, window.getSize().y - 400), 1);
	//Alien bug12(10, sf::Color::Blue, sf::Vector2f(((window.getSize().x) / get13) + getsize * 11, window.getSize().y - 400), 1);

	//Alien bee1(10, sf::Color::Magenta, sf::Vector2f((0) + getsize, window.getSize().y - 430), 2);
	//Alien bee2(10, sf::Color::Magenta, sf::Vector2f(((window.getSize().x) / get13) + getsize, window.getSize().y - 430), 2);
	//Alien bee3(10, sf::Color::Magenta, sf::Vector2f(((window.getSize().x) / get13) + getsize * 2, window.getSize().y - 430), 2);
	//Alien bee4(10, sf::Color::Magenta, sf::Vector2f(((window.getSize().x) / get13) + getsize * 3, window.getSize().y - 430), 2);
	//Alien bee5(10, sf::Color::Magenta, sf::Vector2f(((window.getSize().x) / get13) + getsize * 4, window.getSize().y - 430), 2);
	//Alien bee6(10, sf::Color::Magenta, sf::Vector2f(((window.getSize().x) / get13) + getsize * 5, window.getSize().y - 430), 2);
	//Alien bee7(10, sf::Color::Magenta, sf::Vector2f(((window.getSize().x) / get13) + getsize * 6, window.getSize().y - 430), 2);
	//Alien bee8(10, sf::Color::Magenta, sf::Vector2f(((window.getSize().x) / get13) + getsize * 7, window.getSize().y - 430), 2);
	//Alien bee9(10, sf::Color::Magenta, sf::Vector2f(((window.getSize().x) / get13) + getsize * 8, window.getSize().y - 430), 2);
	//Alien bee10(10, sf::Color::Magenta, sf::Vector2f(((window.getSize().x) / get13) + getsize * 9, window.getSize().y - 430), 2);
	//Alien bee11(10, sf::Color::Magenta, sf::Vector2f(((window.getSize().x) / get13) + getsize * 10, window.getSize().y - 430), 2);
	//Alien bee12(10, sf::Color::Magenta, sf::Vector2f(((window.getSize().x) / get13) + getsize * 11, window.getSize().y - 430), 2);

	//Alien alien1(10, sf::Color::Red, sf::Vector2f((0) + getsize, window.getSize().y - 460), 3);
	//Alien alien2(10, sf::Color::Red, sf::Vector2f(((window.getSize().x) / get13) + getsize, window.getSize().y - 460), 3);
	//Alien alien3(10, sf::Color::Red, sf::Vector2f(((window.getSize().x) / get13) + getsize * 2, window.getSize().y - 460), 3);
	//Alien alien4(10, sf::Color::Red, sf::Vector2f(((window.getSize().x) / get13) + getsize * 3, window.getSize().y - 460), 3);
	//Alien alien5(10, sf::Color::Red, sf::Vector2f(((window.getSize().x) / get13) + getsize * 4, window.getSize().y - 460), 3);
	//Alien alien6(10, sf::Color::Red, sf::Vector2f(((window.getSize().x) / get13) + getsize * 5, window.getSize().y - 460), 3);
	//Alien alien7(10, sf::Color::Red, sf::Vector2f(((window.getSize().x) / get13) + getsize * 6, window.getSize().y - 460), 3);
	//Alien alien8(10, sf::Color::Red, sf::Vector2f(((window.getSize().x) / get13) + getsize * 7, window.getSize().y - 460), 3);
	//Alien alien9(10, sf::Color::Red, sf::Vector2f(((window.getSize().x) / get13) + getsize * 8, window.getSize().y - 460), 3);
	//Alien alien10(10, sf::Color::Red, sf::Vector2f(((window.getSize().x) / get13) + getsize * 9, window.getSize().y - 460), 3);
	//Alien alien11(10, sf::Color::Red, sf::Vector2f(((window.getSize().x) / get13) + getsize * 10, window.getSize().y - 460), 3);
	//Alien alien12(10, sf::Color::Red, sf::Vector2f(((window.getSize().x) / get13) + getsize * 11, window.getSize().y - 460), 3);

	//Alien enemy1(10, sf::Color::Green, sf::Vector2f((0) + getsize, window.getSize().y - 490), 4);
	//Alien enemy2(10, sf::Color::Green, sf::Vector2f(((window.getSize().x) / get13) + getsize, window.getSize().y - 490), 4);
	//Alien enemy3(10, sf::Color::Green, sf::Vector2f(((window.getSize().x) / get13) + getsize * 2, window.getSize().y - 490), 4);
	//Alien enemy4(10, sf::Color::Green, sf::Vector2f(((window.getSize().x) / get13) + getsize * 3, window.getSize().y - 490), 4);
	//Alien enemy5(10, sf::Color::Green, sf::Vector2f(((window.getSize().x) / get13) + getsize * 4, window.getSize().y - 490), 4);
	//Alien enemy6(10, sf::Color::Green, sf::Vector2f(((window.getSize().x) / get13) + getsize * 5, window.getSize().y - 490), 4);
	//Alien enemy7(10, sf::Color::Green, sf::Vector2f(((window.getSize().x) / get13) + getsize * 6, window.getSize().y - 490), 4);
	//Alien enemy8(10, sf::Color::Green, sf::Vector2f(((window.getSize().x) / get13) + getsize * 7, window.getSize().y - 490), 4);
	//Alien enemy9(10, sf::Color::Green, sf::Vector2f(((window.getSize().x) / get13) + getsize * 8, window.getSize().y - 490), 4);
	//Alien enemy10(10, sf::Color::Green, sf::Vector2f(((window.getSize().x) / get13) + getsize * 9, window.getSize().y - 490), 4);
	//Alien enemy11(10, sf::Color::Green, sf::Vector2f(((window.getSize().x) / get13) + getsize * 10, window.getSize().y - 490), 4);
	//Alien enemy12(10, sf::Color::Green, sf::Vector2f(((window.getSize().x) / get13) + getsize * 11, window.getSize().y - 490), 4); // do not delete

	//double x = (Pi/2); //bug moving
	//
	//while (window.isOpen())
	//{
	//	double z = cos((x / 1000) * Pi); //bug moving
	//	double y = sin((x / 1000) * Pi); //bug moving
	//	//window.clear();
	//	sf::Event event;
	//	while (window.pollEvent(event))
	//	{
	//		if (event.type == sf::Event::Closed)
	//			window.close();
	//	}

	//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && spaceship.isInbounds('r'))
	//	{
	//		spaceship.move(0.11, 0);
	//	}
	//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && spaceship.isInbounds('l'))
	//	{
	//		spaceship.move(-0.11, 0);
	//	}

	//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && bullet1.isInbounds('u') && bullet1.getHP() != 0)
	//	{
	//		bullet1.setPosition(spaceship.getPosition());
	//		bullet1.move(0, -0.4);
	//	}
	//	if (!bullet1.isInbounds('u'))
	//	{
	//		bullet1.setPosition(sf::Vector2f(600,600));
	//	}
	//	if (bullet1.getPosition() != sf::Vector2f(600, 600))
	//	{
	//		bullet1.move(0, -0.4);
	//	}
	//	if (bug1.getGlobalBounds().intersects(bullet1.getGlobalBounds()))
	//	{
	//		if (bug1.getHP() == 1)
	//		{
	//			bug1.hit();
	//		}
	//	}
	//	if (bug1.getPosition().x != 300)
	//	{
	//		int tempx = bug1.getPosition().x;
	//		int tempy = bug1.getPosition().y;
	//		sf::Vector2f(bug1.getPosition().x, bug1.getPosition().y);

	//		bug1.move(0.5*z, 0.5*y); //bug moving

	//	}
	//	if (bug1.getPosition().x == 300)
	//	{

	//	}
	//	
	//	window.draw(spaceship);
	//	if (bug1.getHP() != 0)
	//		window.draw(bug1);
	//	if (bug2.getHP() != 0)
	//		window.draw(bug2);
	//	if (bug3.getHP() != 0)
	//		window.draw(bug3);
	//	if (bug4.getHP() != 0)
	//		window.draw(bug4);
	//	if (bug5.getHP() != 0)
	//		window.draw(bug5);
	//	if (bug6.getHP() != 0)
	//		window.draw(bug6);
	//	if (bug7.getHP() != 0)
	//		window.draw(bug7);
	//	if (bug8.getHP() != 0)
	//		window.draw(bug8);
	//	if (bug9.getHP() != 0)
	//		window.draw(bug9);
	//	if (bug10.getHP() != 0)
	//		window.draw(bug10);
	//	if (bug11.getHP() != 0)
	//		window.draw(bug11);
	//	if (bug12.getHP() != 0)
	//		window.draw(bug12);
	//	window.draw(bullet1);
	//	window.display();
	//	window.clear();
	//	x++; //bug moving
	//}

//=======
//	int lhand_moving_right = 1;
//	float movex = 0;
//	float movey = 0;
//	Bullet lhand(25, sf::Color::Yellow, sf::Vector2f(600, 600));
//	Bullet rhand(25, sf::Color::Yellow, sf::Vector2f(600, 600));
//
//	sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");
//	bool previousShootKeyState;
//	spaceShip spaceship(15, sf::Color::Yellow, sf::Vector2f(window.getSize().x / 2, window.getSize().y - 90));
//	Alien bug1(15, sf::Color::Blue, sf::Vector2f(window.getSize().x / 2, window.getSize().y - 500), 1);
//	
//	//spaceShip bug2(15, sf::Color::Blue, sf::Vector2f(window.getSize().x / 2, window.getSize().y - 500));
//	//spaceShip bug3(15, sf::Color::Blue, sf::Vector2f(window.getSize().x / 2, window.getSize().y - 500));
//	//spaceShip bug4(15, sf::Color::Blue, sf::Vector2f(window.getSize().x / 2, window.getSize().y - 500));
//	//spaceShip bug5(15, sf::Color::Blue, sf::Vector2f(window.getSize().x / 2, window.getSize().y - 500));
//	//spaceShip bug6(15, sf::Color::Blue, sf::Vector2f(window.getSize().x / 2, window.getSize().y - 500));
//	Bullet bullet1(5, sf::Color::Yellow, sf::Vector2f(600,600));
//	Bullet bullet2(5, sf::Color::Yellow, sf::Vector2f(-600,-600));
//	Bullet bullet3(5, sf::Color::Yellow, sf::Vector2f(-600, -600));
//	Bullet bullet4(5, sf::Color::Yellow, sf::Vector2f(-600, -600));
//	
//	int getsize = window.getSize().x / 14;
//	int get13 = 13;
//	int directionbugx = -1;
//	int directionbeex = -1;
//	int directionalienx = -1;
//	int directionenemyx = -1;
//
//	//Alien bug1(10, sf::Color::Blue, sf::Vector2f((0) + getsize, window.getSize().y - 400), 1);
//	Alien bug2(10, sf::Color::Blue, sf::Vector2f(((window.getSize().x) / get13) + getsize, window.getSize().y - 400), 1);
//	Alien bug3(10, sf::Color::Blue, sf::Vector2f(((window.getSize().x) / get13) + getsize * 2, window.getSize().y - 400), 1);
//	Alien bug4(10, sf::Color::Blue, sf::Vector2f(((window.getSize().x) / get13) + getsize * 3, window.getSize().y - 400), 1);
//	Alien bug5(10, sf::Color::Blue, sf::Vector2f(((window.getSize().x) / get13) + getsize * 4, window.getSize().y - 400), 1);
//	Alien bug6(10, sf::Color::Blue, sf::Vector2f(((window.getSize().x) / get13) + getsize * 5, window.getSize().y - 400), 1);
//	Alien bug7(10, sf::Color::Blue, sf::Vector2f(((window.getSize().x) / get13) + getsize * 6, window.getSize().y - 400), 1);
//	Alien bug8(10, sf::Color::Blue, sf::Vector2f(((window.getSize().x) / get13) + getsize * 7, window.getSize().y - 400), 1);
//	Alien bug9(10, sf::Color::Blue, sf::Vector2f(((window.getSize().x) / get13) + getsize * 8, window.getSize().y - 400), 1);
//	Alien bug10(10, sf::Color::Blue, sf::Vector2f(((window.getSize().x) / get13) + getsize * 9, window.getSize().y - 400), 1);
//	Alien bug11(10, sf::Color::Blue, sf::Vector2f(((window.getSize().x) / get13) + getsize * 10, window.getSize().y - 400), 1);
//	Alien bug12(10, sf::Color::Blue, sf::Vector2f(((window.getSize().x) / get13) + getsize * 11, window.getSize().y - 400), 1);
//
//	Alien bee1(10, sf::Color::Magenta, sf::Vector2f((0) + getsize, window.getSize().y - 430), 2);
//	Alien bee2(10, sf::Color::Magenta, sf::Vector2f(((window.getSize().x) / get13) + getsize, window.getSize().y - 430), 2);
//	Alien bee3(10, sf::Color::Magenta, sf::Vector2f(((window.getSize().x) / get13) + getsize * 2, window.getSize().y - 430), 2);
//	Alien bee4(10, sf::Color::Magenta, sf::Vector2f(((window.getSize().x) / get13) + getsize * 3, window.getSize().y - 430), 2);
//	Alien bee5(10, sf::Color::Magenta, sf::Vector2f(((window.getSize().x) / get13) + getsize * 4, window.getSize().y - 430), 2);
//	Alien bee6(10, sf::Color::Magenta, sf::Vector2f(((window.getSize().x) / get13) + getsize * 5, window.getSize().y - 430), 2);
//	Alien bee7(10, sf::Color::Magenta, sf::Vector2f(((window.getSize().x) / get13) + getsize * 6, window.getSize().y - 430), 2);
//	Alien bee8(10, sf::Color::Magenta, sf::Vector2f(((window.getSize().x) / get13) + getsize * 7, window.getSize().y - 430), 2);
//	Alien bee9(10, sf::Color::Magenta, sf::Vector2f(((window.getSize().x) / get13) + getsize * 8, window.getSize().y - 430), 2);
//	Alien bee10(10, sf::Color::Magenta, sf::Vector2f(((window.getSize().x) / get13) + getsize * 9, window.getSize().y - 430), 2);
//	Alien bee11(10, sf::Color::Magenta, sf::Vector2f(((window.getSize().x) / get13) + getsize * 10, window.getSize().y - 430), 2);
//	Alien bee12(10, sf::Color::Magenta, sf::Vector2f(((window.getSize().x) / get13) + getsize * 11, window.getSize().y - 430), 2);
//
//	Alien alien1(10, sf::Color::Red, sf::Vector2f((0) + getsize, window.getSize().y - 460), 3);
//	Alien alien2(10, sf::Color::Red, sf::Vector2f(((window.getSize().x) / get13) + getsize, window.getSize().y - 460), 3);
//	Alien alien3(10, sf::Color::Red, sf::Vector2f(((window.getSize().x) / get13) + getsize * 2, window.getSize().y - 460), 3);
//	Alien alien4(10, sf::Color::Red, sf::Vector2f(((window.getSize().x) / get13) + getsize * 3, window.getSize().y - 460), 3);
//	Alien alien5(10, sf::Color::Red, sf::Vector2f(((window.getSize().x) / get13) + getsize * 4, window.getSize().y - 460), 3);
//	Alien alien6(10, sf::Color::Red, sf::Vector2f(((window.getSize().x) / get13) + getsize * 5, window.getSize().y - 460), 3);
//	Alien alien7(10, sf::Color::Red, sf::Vector2f(((window.getSize().x) / get13) + getsize * 6, window.getSize().y - 460), 3);
//	Alien alien8(10, sf::Color::Red, sf::Vector2f(((window.getSize().x) / get13) + getsize * 7, window.getSize().y - 460), 3);
//	Alien alien9(10, sf::Color::Red, sf::Vector2f(((window.getSize().x) / get13) + getsize * 8, window.getSize().y - 460), 3);
//	Alien alien10(10, sf::Color::Red, sf::Vector2f(((window.getSize().x) / get13) + getsize * 9, window.getSize().y - 460), 3);
//	Alien alien11(10, sf::Color::Red, sf::Vector2f(((window.getSize().x) / get13) + getsize * 10, window.getSize().y - 460), 3);
//	Alien alien12(10, sf::Color::Red, sf::Vector2f(((window.getSize().x) / get13) + getsize * 11, window.getSize().y - 460), 3);
//
//	Alien enemy1(10, sf::Color::Green, sf::Vector2f((0) + getsize, window.getSize().y - 490), 4);
//	Alien enemy2(10, sf::Color::Green, sf::Vector2f(((window.getSize().x) / get13) + getsize, window.getSize().y - 490), 4);
//	Alien enemy3(10, sf::Color::Green, sf::Vector2f(((window.getSize().x) / get13) + getsize * 2, window.getSize().y - 490), 4);
//	Alien enemy4(10, sf::Color::Green, sf::Vector2f(((window.getSize().x) / get13) + getsize * 3, window.getSize().y - 490), 4);
//	Alien enemy5(10, sf::Color::Green, sf::Vector2f(((window.getSize().x) / get13) + getsize * 4, window.getSize().y - 490), 4);
//	Alien enemy6(10, sf::Color::Green, sf::Vector2f(((window.getSize().x) / get13) + getsize * 5, window.getSize().y - 490), 4);
//	Alien enemy7(10, sf::Color::Green, sf::Vector2f(((window.getSize().x) / get13) + getsize * 6, window.getSize().y - 490), 4);
//	Alien enemy8(10, sf::Color::Green, sf::Vector2f(((window.getSize().x) / get13) + getsize * 7, window.getSize().y - 490), 4);
//	Alien enemy9(10, sf::Color::Green, sf::Vector2f(((window.getSize().x) / get13) + getsize * 8, window.getSize().y - 490), 4);
//	Alien enemy10(10, sf::Color::Green, sf::Vector2f(((window.getSize().x) / get13) + getsize * 9, window.getSize().y - 490), 4);
//	Alien enemy11(10, sf::Color::Green, sf::Vector2f(((window.getSize().x) / get13) + getsize * 10, window.getSize().y - 490), 4);
//	Alien enemy12(10, sf::Color::Green, sf::Vector2f(((window.getSize().x) / get13) + getsize * 11, window.getSize().y - 490), 4); // do not delete
//
//	double x = (Pi/2); //bug moving
//	
//	while (window.isOpen())
//	{
//		double z = 10* cos((x / 1000) * Pi); //bug moving
//		double y = 10* sin((x / 1000) * Pi); //bug moving
//		//window.clear();
//		sf::Event event;
//		while (window.pollEvent(event))
//		{
//			if (event.type == sf::Event::Closed)
//				window.close();
//		}
//
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && spaceship.isInbounds('r'))
//		{
//			spaceship.move(0.11, 0);
//		}
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && spaceship.isInbounds('l'))
//		{
//			spaceship.move(-0.11, 0);
//		}
//
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && bullet1.getPosition() == sf::Vector2f(600,600))
//		{
//			bullet1.setPosition(spaceship.getPosition());
//			bullet1.move(0, -0.4);
//		}
//		if (!bullet1.isInbounds('u'))
//		{
//			bullet1.setPosition(sf::Vector2f(600,600));
//		}
//		if (bullet1.getPosition() != sf::Vector2f(600, 600))
//		{
//			bullet1.move(0, -0.4);
//		}
//		if (bug1.getGlobalBounds().intersects(bullet1.getGlobalBounds()))
//		{
//			if (bug1.getHP() == 1)
//			{
//				bug1.hit();
//			}
//		}
//		
//		if (bug1.getPosition().x != 300)
//		{
//			int tempx = bug1.getPosition().x;
//			int tempy = bug1.getPosition().y;
//			sf::Vector2f(bug1.getPosition().x, bug1.getPosition().y);
//
//			bug1.move(0.05*z, 0.05*y); //bug moving
//
//		}
//		if (bug1.getPosition().x == 300)
//		{
//
//		}
//		
//		
//		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//		//float tempbugx = bug1.getPosition().x;
//		//float tempbugy = bug1.getPosition().y;
//		//float tempssx = spaceship.getPosition().x+12.5;
//		//float tempssy = spaceship.getPosition().y+12.5;
//
//		//float xval = tempssx - tempbugx;
//		//float yval = tempssy - tempbugy;
//
//		//float normal = sqrt(pow(xval,2) + pow(yval,2));
//
//		//float movex = xval / normal;
//		//float movey = yval / normal;
//		
//		
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && bullet2.getPosition() == sf::Vector2f(-600, -600))
//		{
//			float tempbugx = bug1.getPosition().x;
//			float tempbugy = bug1.getPosition().y;
//			float tempssx = spaceship.getPosition().x+12.5;
//			float tempssy = spaceship.getPosition().y+12.5;
//
//			float xval = tempssx - tempbugx;
//			float yval = tempssy - tempbugy;
//
//			float normal = sqrt(pow(xval, 2) + pow(yval, 2));
//
//			movex = xval / normal;
//			movey = yval / normal;
//			bullet2.setPosition(bug1.getPosition());
//			bullet2.move(0.05*movex, 0.05*movey);
//		}
//		if (!bullet2.isInbounds('d'))
//		{
//			bullet2.setPosition(sf::Vector2f(-600, -600));
//		}
//
//		if (bullet2.getPosition() != sf::Vector2f(-600, -600))
//		{
//			bullet2.move(0.05*movex, 0.05*movey);
//		}
//		if (bullet2.getGlobalBounds().intersects(spaceship.getGlobalBounds()))
//		{
//			//player health reduced by 1
//		}
//
//
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && bullet3.getPosition() == sf::Vector2f(-600, -600))
//		{
//			bullet3.setPosition(bug1.getPosition());
//			bullet3.move(0, 0.05);
//		}
//		if (!bullet3.isInbounds('d'))
//		{
//			bullet3.setPosition(sf::Vector2f(-600, -600));
//		}
//
//		if (bullet3.getPosition() != sf::Vector2f(-600, -600))
//		{
//			bullet3.move(0, 0.05);
//		}
//		if (bullet3.getGlobalBounds().intersects(spaceship.getGlobalBounds()))
//		{
//			//player health reduced by 1
//		}
//
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::E) && bullet4.getPosition() == sf::Vector2f(-600, -600))
//		{
//			bullet4.setPosition(bug1.getPosition());
//			bullet4.move(0, 0.05);
//		}
//		if (!bullet4.isInbounds('d'))
//		{
//			bullet4.setPosition(sf::Vector2f(-600, -600));
//		}
//
//		if (bullet4.getPosition() != sf::Vector2f(-600, -600))
//		{
//			bullet4.move(0, 0.05);
//		}
//		if (bullet4.getGlobalBounds().intersects(spaceship.getGlobalBounds()))
//		{
//			//player health reduced by 1
//		}
//		 //ANDYS LEFT HAND
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::R) && lhand.getPosition() == sf::Vector2f(-600, -600))
//		{
//			lhand.setPosition(sf::Vector2f(-10,spaceship.getPosition().y));
//			lhand.move(0.06, 0);
//		}
//		if (!lhand.isInbounds('r') || lhand.getPosition().x < -100)
//		{
//			lhand.setPosition(sf::Vector2f(-600, -600));
//			lhand_moving_right = 1;
//		}
//		if (lhand.getPosition() != sf::Vector2f(-600, -600))
//		{
//			if(lhand_moving_right == 1)
//				lhand.move(0.06, 0);
//			else
//				lhand.move(-0.06,0);
//		}
//		if (lhand.getPosition().x > 280)
//		{
//			lhand_moving_right = 0;
//		}
//		
//
//
//		window.draw(lhand);
//		window.draw(bullet4);
//		window.draw(bullet3);
//		window.draw(bullet2);
//		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//		window.draw(spaceship);
//		if (bug1.getHP() != 0)
//			window.draw(bug1);
//		window.draw(bullet1);
//		window.display();
//		window.clear();
//		x++; //bug moving
//	}
//>>>>>>> ac6596904cbefee900f37413a32686e67a237274
	return 0;
}
