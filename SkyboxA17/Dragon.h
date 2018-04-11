#pragma once
#include "Animal.h"

class Dragon : public Animal
{
public:
	Dragon(float size, std::string name);
	~Dragon() {};

	virtual const float GetSize() const noexcept override { return mSize; };
	virtual const std::string GetName() const noexcept override { return mName; };
private:
	float mSize = 0;
	std::string mName = "";
};