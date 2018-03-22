#include <iostream>
#include "Cash.h"

int main()
{
	Cash monies(1, 50);
	monies *= 2;
	std::cout << monies;
	
	Cash moarMonies = monies * 5;
	std::cout << moarMonies;
	
	Cash riches = 5 * monies;
	std::cout << riches;

	system("pause");
	return 0;
}