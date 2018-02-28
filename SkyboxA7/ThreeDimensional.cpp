#include "ThreeDimensional.h"

ThreeDimensional::ThreeDimensional(std::string name)
	: Shape(name)
{
	// Empty
}

ThreeDimensional::~ThreeDimensional()
{
	// Empty
}

float ThreeDimensional::GetVolume()
{
	return 0.0f;
}

float ThreeDimensional::GetSurfaceArea()
{
	return 0.0f;
}
