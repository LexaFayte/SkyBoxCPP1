#pragma once
#include <string>

#include"TwoDimensional.h"

class Rectangle : public TwoDimensional
{
public:
	Rectangle(std::string name, float width, float height);
	~Rectangle();

	void SetWidth(float width);
	void SetHeight(float height);

	const float& GetWidth() const noexcept { return mWidth; }
	const float& GetHeight() const noexcept { return mHeight; }

	float GetArea() override { return mWidth * mHeight; }
	float GetPerimeter() override { return 2.0f * (mWidth + mHeight); }

	void Calculate();

	void Print() override;

private:
	float mWidth;
	float mHeight;
	float mArea = 0;
	float mPerimiter = 0;
};