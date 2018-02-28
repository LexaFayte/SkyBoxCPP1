#include <iostream>

#include "Cube.h"

Cube::Cube(std::string name, float width, float height, float depth)
	: ThreeDimensional(name)
	, mDepth(0.0f)
{
	SetWidth(width);
	SetHeight(height);
	SetDepth(depth);
}

Cube::~Cube()
{
	// Empty
}

void Cube::SetWidth(float width)
{
	mWidth = BelowZeroCheck(width);
}

void Cube::SetHeight(float height)
{
	mHeight = BelowZeroCheck(height);
}

void Cube::SetDepth(float depth)
{
	mDepth = BelowZeroCheck(depth);
}

void Cube::Print()
{
	std::cout << "Volume: " << GetVolume() << std::endl;
	std::cout << "Surface Area: " << GetSurfaceArea() << std::endl;
}