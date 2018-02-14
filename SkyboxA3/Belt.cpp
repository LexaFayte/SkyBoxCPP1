#include "Belt.h"

Belt::Belt() {};
Belt::Belt(int size) : mSize(size)
{

};

Belt::~Belt() {};

int Belt::getSize()
{
	return mSize;
}

void Belt::setSize(int size)
{
	mSize = size;
}