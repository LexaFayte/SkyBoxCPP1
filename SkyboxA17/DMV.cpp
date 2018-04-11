#include "DMV.h"
#include <iostream>

DMV::DMV()
{
	mCounters.reserve(10);
	for (int i = 0; i < 10; ++i)
	{
		mCounters.emplace_back(ServiceCounter(i + 1));
	}
}

void DMV::EnterQueue(Animal& animal)
{
	int counterIndex = std::floorf(animal.GetSize() - 1);
	mCounters[counterIndex].AddAnimalToQueue(&animal);
}

void DMV::PrintServiceCounterInfo()
{
	for (ServiceCounter& sc : mCounters)
	{
		sc.PrintInfo();
		std::cout << "\n";
	}
}