#include <iostream>

#include "Shape.h"

Shape::Shape(std::string name) : mName(name)
{

}

void Shape::Print()
{
	// Empty
}

float Shape::BelowZeroCheck(const float& number) noexcept
{
	if (number < 0.0f)
	{
		std::cout << "ERROR - " << number << " Invaild. " << std::endl;
		return 0.0f;
	}
	return number;
}
