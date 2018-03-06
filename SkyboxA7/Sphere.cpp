#include <iostream>

#include "Sphere.h"

Sphere::Sphere(const std::string & name, float radius)
	: ThreeDimensional(name)
	, Shape(name)
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
	mVolume = GetVolume();
	mSurfaceArea = GetSurfaceArea();
}

void Sphere::Print()
{
	std::cout << "Volume: " << mVolume << std::endl;
	std::cout << "Surface Area: " << mSurfaceArea << std::endl;
}