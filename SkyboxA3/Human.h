#pragma once
#include "Belt.h"
#include "Shoes.h"
#include <string>

class Human
{
private:
	Belt mBelt;
	Shoes mShoes;
	std::string mName;
public:
	Human();
	~Human();
};