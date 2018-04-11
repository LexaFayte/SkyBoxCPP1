#pragma once
#include <string>
class Animal
{
public:
	Animal() {};
	virtual ~Animal() {};

	virtual const float GetSize() const noexcept { return mSize; };
	virtual const std::string GetName() const noexcept { return mName; };
private:
	float mSize = 0;
	std::string mName = "";
};