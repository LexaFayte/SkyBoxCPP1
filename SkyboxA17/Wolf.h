#pragma once
#include "Animal.h"

class Wolf : public Animal
{
public:
	Wolf(float size, std::string name);
	~Wolf() {};

	virtual const float GetSize() const noexcept override { return mSize; };
	virtual const std::string GetName() const noexcept override { return mName; };
private:
	float mSize = 0;
	std::string mName = "";
};