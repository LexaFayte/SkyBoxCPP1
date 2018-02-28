#include <iostream>

#include "Sphere.h"

Sphere::Sphere(const std::string & name, float radius)
	: ThreeDimensional(name)
	, mRadius(0.0f)
	, mPie(3.14f)
{
	SetRadius(radius);
}

Sphere::~Sphere()
{
	// Empty
}

void Sphere::SetRadius(float radius)
{
	mRadius = BelowZeroCheck(radius);
}

void Sphere::Print()
{
	std::cout << "Volume: " << GetVolume() << std::endl;
	std::cout << "Surface Area: " << GetSurfaceArea() << std::endl;
}