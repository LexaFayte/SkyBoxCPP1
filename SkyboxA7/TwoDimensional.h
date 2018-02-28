#ifndef TWO_DIMENSIONAL_H
#define TWODIMENSIONAL_H

#include "Shape.h"

class TwoDimensional : public Shape
{
public:
	TwoDimensional(std::string name);
	~TwoDimensional();

	virtual float GetArea();
	virtual float GetPerimeter();
};

#endif // #ifndef TWO_DIMENSIONAL_H