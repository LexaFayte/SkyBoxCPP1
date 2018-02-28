#ifndef THREE_DIMENSIONAL_H
#define THREE_DIMENSIONAL_H

#include <string>
#include "Shape.h"

class ThreeDimensional : public Shape
{
public:
	ThreeDimensional(std::string name);
	~ThreeDimensional();

	virtual float GetVolume();
	virtual float GetSurfaceArea();
};

#endif // #ifndef THREE_DIMENSIONAL_H