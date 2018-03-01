#ifndef THREE_DIMENSIONAL_H
#define THREE_DIMENSIONAL_H

#include <string>
#include "Shape.h"

class ThreeDimensional : public virtual Shape
{
public:
	ThreeDimensional(std::string name);
	virtual ~ThreeDimensional() {};

	virtual float GetVolume();
	virtual float GetSurfaceArea();
	virtual void Print() override;
};

#endif 