#include "LoopsAndStuff.h"



void LoopsAndStuff::ReversePsychology()
{
	int input = 0;
	do
	{
		std::cout << "Enter a number other than 5: ";
		std::cin >> input;
	} while (input != THE_NUMBER);

	std::cout << REPRIMAND << std::endl;
}

void LoopsAndStuff::ReversePsychologyV2()
{
	int input = 0;
	int counter = 0;

	do
	{
		std::cout << "Enter a number other than 5: ";
		std::cin >> input;
		++counter;
	} while (input != THE_NUMBER && counter < 10);

	if (counter >= 10)
	{
		std::cout << WIN_V1 << std::endl;
	}
	else
	{
		std::cout << REPRIMAND << std::endl;
	}
}

void LoopsAndStuff::ReversePsychologyV3()
{
	int input = 0;
	int counter;
	for (counter = 0; counter < 10; ++counter)
	{
		std::cout << "Enter a number other than " << counter << ":";
		std::cin >> input;
		if (input == counter)
		{
			break;
		}
	}

	if (counter >= 10)
	{
		std::cout << WIN_V2 << std::endl;
	}
	else
	{
		std::cout << REPRIMAND_V2 << std::endl;
	}
}
