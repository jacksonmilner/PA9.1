// This example will use SFML libraries to implement
// the game of Pong

// History: 4/16 - Started from the SFML tutorial code that draws
//                a circle in the window.

#include <SFML/Graphics.hpp>
#include <iostream>
#include "runApp.h"
#include "mainShip.h"
#include "Alien.h"
#include "bullet.h"
#include "runApp.h"
#include <math.h>
#include "testAndy.h"
#define Pi 3.14159265

int main()
{
	TestAndy test;
	test.testSpray();
	int response = 1;
	RunApp spaceshipgame(0);
	while (response != 3)
	{
		std::cout << "Welcome to your doom" << std::endl;
		std::cout << "Press 1 to start" << std::endl;
		std::cout << "Press 2 to read instructions" << std::endl;
		std::cout << "Press 3 to exit" << std::endl;
		std::cin >> response;
		if (response == 1)
		{
			spaceshipgame.run_app();
			system("cls");
			std::cout << "You have completed our game. Thank You for playing." << std::endl 
				 << "Contributers: Jackson Milner, Bradley Cruz, Owen Ryan, Rodrigo Martinez" << std::endl << std::endl;
			system("pause");
			system("cls");
		}
		if (response == 2)
		{
			std::cout << "Your goal is to defeat all enemies plus the final boss" << std::endl <<
				"The a key will move you left, while the d key will move you right" << std::endl <<
				"The spacebar is the shoot button. the enemies will shoot towards you" << std::endl <<
				"One hit from an enemy will be Game Over" << std::endl;
			system("pause");
			system("cls");
		}
		if (response == 3)
			return 0;
	}
	system("pause");
	system("cls");
	return 0;
}
