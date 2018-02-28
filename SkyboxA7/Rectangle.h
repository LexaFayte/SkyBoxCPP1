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

	float GetWidth() { return mWidth; }
	float GetHeight() { return mHeight; }

	virtual float GetArea() override { return mWidth * mHeight; }
	virtual float GetPerimeter() override { return 2.0f * (mWidth + mHeight); }

	void Print() override;

private:
	float mWidth;
	float mHeight;
};