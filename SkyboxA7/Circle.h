#ifndef CIRCLE_H
#define CIRCLE_H

#include <string>

#include "TwoDimensional.h"

using namespace std;

class Circle : public TwoDimensional
{
public:
	Circle(string name, float radius);
	~Circle();

	void SetRadius(float radius);
	float GetRadius() { return mRadius; }

	float GetArea() override { return mPie * mRadius * mRadius; }
	float GetPerimeter() override { return 2.0f * mPie * mRadius; }

	void print();

private:
	float mRadius;
	const float mPie;
	
};

#endif // #ifndef CIRCLE_H