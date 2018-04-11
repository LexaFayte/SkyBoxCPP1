#pragma once
#include "Animal.h"

class Fox : public Animal
{
public:
	Fox(float size, std::string name);
	~Fox() {};

	virtual const float GetSize() const noexcept override { return mSize; };
	virtual const std::string GetName() const noexcept override { return mName; };
private:
	float mSize = 0;
	std::string mName = "";
};