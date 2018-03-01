#include <iostream>

#include "Rectangle.h"

Rectangle::Rectangle(std::string name, float width, float height)
	: TwoDimensional(name), Shape(name)
{
	SetWidth(width);
	SetHeight(height);
	Calculate();
}

Rectangle::~Rectangle()
{
	//Empty
}

void Rectangle::SetWidth(float width)
{
	mWidth = BelowZeroCheck(width);
}

void Rectangle::SetHeight(float height)
{
	mHeight = BelowZeroCheck(height);
}

void Rectangle::Calculate()
{
	mArea = GetArea();
	mPerimiter = GetPerimeter();
}

void Rectangle::Print()
{
	std::cout << "Perimeter: " << mPerimiter << std::endl;
	std::cout << "Area: " << mArea << std::endl;
}