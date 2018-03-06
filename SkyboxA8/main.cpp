#include <string>
#include <iostream>
#include "SimpleClass.h"

float* GetFloatPtr(float& val)
{
	float* ptr = &val;
	return ptr;
}

bool* GetBoolPtr(bool& val)
{
	bool* ptr = &val;
	return ptr;
}

char* GetCharPtr(char& val)
{
	char* ptr = &val;
	return ptr;
}

std::string* GetStringPtr(std::string& val)
{
	std::string* ptr = &val;
	return ptr;
}

void CheckWhale(int* intPtr)
{
	if (intPtr)
	{
		if (*intPtr % 2 == 0)
		{
			std::cout << "THIS WHALE IS EVEN!" << std::endl;
		}
		else
		{
			std::cout << "THIS WHALE IS ODD!" << std::endl;
		}
	}
}

float* CheckDragon(float& dragon)
{
	float* dragonPtr = &dragon;

	if (std::floorf(*dragonPtr) == *dragonPtr)
	{
		std::cout << "THIS DRAGON IS WHOLE!" << std::endl;
	}
	else
	{
		std::cout << "THIS DRAGON IS NOT WHOLE!" << std::endl;
	}

	return dragonPtr;
}

void ChangeSimpleClassVar(SimpleClass* ptr)
{
	ptr->mSimpleInt = 20;
}

int main()
{

	int whale = 4;
	CheckWhale(&whale);
	std::cout << "WHALE: " << whale << std::endl;

	float dragon = 1.5f;
	float* dragonPtr = CheckDragon(dragon);
	std::cout << "DRAGON PTR: " << *dragonPtr << std::endl;

	SimpleClass simple;
	SimpleClass* simplePtr = &simple;
	std::cout << "SimpleClass SimpleInt value: "<< simplePtr->mSimpleInt << std::endl;
	ChangeSimpleClassVar(simplePtr);
	std::cout << "SimpleClass SimpleInt value after change method: " << simplePtr->mSimpleInt << std::endl;

	system("pause");
	return 0;
}