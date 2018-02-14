#include "Shoes.h"


Shoes::Shoes() {};
Shoes::Shoes(std::string colour)
{

};

Shoes::~Shoes() {};

std::string Shoes::getColour()
{
	return mColour;
}

void Shoes::setColour(const std::string& colour)
{
	mColour = colour;
}