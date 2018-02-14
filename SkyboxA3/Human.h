#pragma once
#include "Belt.h"
#include "Shoes.h"
#include <string>

class Human
{
private:
	Belt mBelt;
	Shoes mShoes;
	std::string mName = "";
public:
	Human();
	Human(std::string name, int beltSize, std::string colour);
	~Human();

	Belt getBelt();
	void setBelt(Belt &belt);

	Shoes getShoes();
	void setShoes(Shoes &shoes);

	std::string getName();
	void setName(std::string &name);
};