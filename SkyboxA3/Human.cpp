#include "Human.h"

Human::Human()
{

};

Human::~Human() {};

Human::Human(std::string name, int beltSize, std::string colour) : mName(name),
mBelt(beltSize), mShoes(colour)
{

};

Belt Human::getBelt()
{
	return mBelt;
}

Shoes Human::getShoes()
{
	return mShoes;
}

std::string Human::getName()
{
	return mName;
}

void Human::setBelt(Belt &belt)
{
	mBelt = belt;
}

void Human::setShoes(Shoes &shoes)
{
	mShoes = shoes;
}

void Human::setName(std::string &name)
{
	mName = name;
}