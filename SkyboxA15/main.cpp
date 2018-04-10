#include <iostream>
#include "Slotter.h"

int main(int argc, char* argv[])
{
	bool assigned = false;
	Slotter s;
	std::string name = "";
	int legs = 0;
	float length = 0.0f;

	while (!assigned)
	{
		std::cout << "please name your slotter: ";
		std::cin >> name;
		
		try
		{
			s.SetName(name);
			assigned = true;
		}
		catch (SlotterNameException& e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	assigned = false;
	while (!assigned)
	{
		std::cout << "please specify the number of legs your slotter has: ";
		std::cin >> legs;

		try
		{
			s.SetNumLegs(legs);
			assigned = true;
		}
		catch (SlotterEvenLegNumberException& e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	assigned = false;
	while (!assigned)
	{
		std::cout << "please specify the length of your slotter: ";
		std::cin >> length;

		try
		{
			s.SetLength(length);
			assigned = true;
		}
		catch (SlotterLengthException& e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	system("pause");

	return 0;
}