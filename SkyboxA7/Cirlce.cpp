#include <iostream>

#include "Circle.h"

Circle::Circle(std::string name, float radius) : 
	TwoDimensional(name)
	, Shape(name)
	, mPie(3.14f)
{
	SetRadius(radius);
}

Circle::~Circle()
{
	// Empty
}

void Circle::SetRadius(float radius)
{
	mRadius = BelowZeroCheck(radius);
}

void Circle::Print()
{
	std::cout << "Perimeter: " << GetPerimeter() << std::endl;
	std::cout << "Area: " << GetArea() << std::endl;
}