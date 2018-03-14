#pragma once
#include "CustomClass.h"

class AnotherClass
{
public:
	AnotherClass() { customClassPtr = new CustomClass; }
	~AnotherClass() { delete customClassPtr; }

private:
	CustomClass * customClassPtr;
};
