#pragma once
#include <vector>
#include "ServiceCounter.h"
#include "Animal.h"

class DMV
{
public:
	DMV();
	~DMV() {};
	void EnterQueue(Animal& animal);
	void PrintServiceCounterInfo();
private:
	std::vector<ServiceCounter> mCounters;
};