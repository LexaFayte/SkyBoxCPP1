#ifndef CIRCLE_H
#define CIRCLE_H

#include <string>

#include "TwoDimensional.h"

class Circle : public TwoDimensional
{
public:
	Circle(std::string name, float radius);
	~Circle();

	void SetRadius(const float radius);
	const float& GetRadius() const noexcept { return mRadius; }

	float GetArea() override { return mPie * (mRadius * mRadius); }
	float GetPerimeter() override { return 2.0f * mPie * mRadius; }

	void Print() override;

private:
	float mRadius;
	const float mPie;
};

#endif // #ifndef CIRCLE_H