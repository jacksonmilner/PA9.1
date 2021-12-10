/************************************************************************
*
*
*
*
*
*
*
*
*
*
*************************************************************************/
#include <SFML/Graphics.hpp>
#include <iostream>
#include "runApp.h"
#include "testCases.h"
#define Pi 3.14159265

int main()
{
	//TestCases test;
	//test.testSpray();
	int response = 0;
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
