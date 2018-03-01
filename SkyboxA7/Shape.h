#pragma once
#include <string>

class Shape
{
public:
	Shape(std::string name);
	virtual ~Shape() {};

	virtual const std::string& GetName() const noexcept { return mName; }

	virtual void Print();
	float BelowZeroCheck(const float& number) noexcept;

private:
	std::string mName;
};