#pragma once
#include "Laces.h"
#include <string>

class Shoes
{
private:
	std::string mColour = "";
	Laces mLaces();
public:
	Shoes();
	Shoes(std::string colour);
	~Shoes();

	std::string getColour();
	void setColour(const std::string &colour);
};

