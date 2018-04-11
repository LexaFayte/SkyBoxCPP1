#include "ServiceCounter.h"
#include <iostream>

ServiceCounter::ServiceCounter(float animalServiceSize) : mAnimalServiceSize(animalServiceSize) {};

void ServiceCounter::AddAnimalToQueue(Animal* animal)
{
	mAnimalServiceLine.push(animal);
}

void ServiceCounter::PrintInfo()
{
	std::cout << "This service counter serves animals of size: " << mAnimalServiceSize << std::endl;
	std::cout << "there are " << mAnimalServiceLine.size() << " animals in this line!" << std::endl;
}