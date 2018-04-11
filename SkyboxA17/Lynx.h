#pragma once
#include "Animal.h"

class Lynx : public Animal
{
public:
	Lynx(float size, std::string name);
	~Lynx() {};

	virtual const float GetSize() const noexcept override { return mSize; };
	virtual const std::string GetName() const noexcept override { return mName; };
private:
	float mSize = 0;
	std::string mName = "";
};