// This example will use SFML libraries to implement
// the game of Pong

// History: 4/16 - Started from the SFML tutorial code that draws
//                a circle in the window.

#include <SFML/Graphics.hpp>
#include "runApp.h"
#include "mainShip.h"
#include "Alien.h"
#include "bullet.h"
#include "runApp.h"
#include <math.h>
#define Pi 3.14159265

int main()
{
	//RunApp spaceshipgame(0);
	//spaceshipgame.run_app();

sf::RenderWindow window{ sf::VideoMode(800,600), "The game!" };
sf::Texture t;
//i.loadFromFile(/"Image.png");
t.loadFromFile("ANDYYY.jpg");
//t.loadFromImage(i);
sf::Sprite s(t);
while (window.isOpen())
{
	sf::Event windowEvent;
	while (window.pollEvent(windowEvent))
	{
		if (windowEvent.type == sf::Event::Closed)
			window.close();
	}
	window.clear(sf::Color::White);

	window.draw(s);
	window.display();
}
return 0;
}
