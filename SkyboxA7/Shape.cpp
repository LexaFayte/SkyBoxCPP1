#include <iostream>

#include "Shape.h"

Shape::Shape(std::string name)
{
	mName = name;
}

void Shape::Print()
{
	// Empty
}

float Shape::BelowZeroCheck(float number)
{
	if (number < 0.0f)
	{
		cout << "ERROR - " << number << " Invaild. " << endl;
		return 0.0f;
	}
	return number;
}
