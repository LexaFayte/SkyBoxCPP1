#include <iostream>

#include "Cube.h"

Cube::Cube(std::string name, float sideLength)
	: ThreeDimensional(name)
	, Shape(name)
{
	SetSideLength(sideLength);
}

Cube::~Cube()
{
	// Empty
}

void Cube::SetSideLength(float sideLength)
{
	mSideLength = BelowZeroCheck(sideLength);
	mVolume = GetVolume();
	mSurfaceArea = GetSurfaceArea();
}

void Cube::Print()
{
	std::cout << "Volume: " << mVolume << std::endl;
	std::cout << "Surface Area: " << mSurfaceArea << std::endl;
}