#ifndef TWO_DIMENSIONAL_H
#define TWO_DIMENSIONAL_H

#include "Shape.h"

class TwoDimensional : public virtual Shape
{
public:
	TwoDimensional(std::string name);
	virtual ~TwoDimensional() {};

	virtual float GetArea();
	virtual float GetPerimeter();
	virtual void Print() override;
};

#endif // #ifndef TWO_DIMENSIONAL_H