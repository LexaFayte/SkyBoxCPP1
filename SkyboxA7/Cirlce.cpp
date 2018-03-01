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
	mArea = GetArea();
	mPerimiter = GetPerimeter();
}

void Circle::Print()
{
	std::cout << "Perimeter: " << mPerimiter << std::endl;
	std::cout << "Area: " << mArea << std::endl;
}