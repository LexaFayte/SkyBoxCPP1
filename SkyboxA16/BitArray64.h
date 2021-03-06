#pragma once
#include <iostream>

class BitArray64
{
public:
	BitArray64() {};

	int Get();
	void Return(int index);
	void Set(int index, bool value);
	bool Value(int index);
	void Print();

private:
	const unsigned int ArraySize = 64;

	//bits that will be set in the Set method and returned in the Value method
	long long mBits = 0;

	//will be used as a marker to show which bits are already in use for the object
	//used in Get and Return
	long long mBitsInUse = 0;
};