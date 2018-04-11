#pragma once
#include <queue>
#include "Animal.h"

class ServiceCounter
{
public:
	ServiceCounter(float AnimalServiceSize);
	~ServiceCounter() {};

	void AddAnimalToQueue(Animal* animal);
	void PrintInfo();
private:
	float mAnimalServiceSize = 0;
	std::queue<Animal*> mAnimalServiceLine;
};