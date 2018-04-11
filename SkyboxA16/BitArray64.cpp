#include "BitArray64.h"
#include <bitset>
//returns an "index"
int BitArray64::Get()
{
	long long value = 1;
	int index = 0;
	int result = 0;
	bool freeBit = false;
	do
	{
		result = (~mBitsInUse&value);
		if (result > 0)
		{
			mBitsInUse |= (1 << index);
			freeBit = true;
			std::cout << "GIVING OUT INDEX: " << index << std::endl;
			std::cout << std::bitset<64>(mBitsInUse) << std::endl;
		}
		else
		{
			value <<= 1;
			++index;
		}
	} while (!freeBit);

	return index;
}

void BitArray64::Return(int index)//does this function have to clear the bit in mBits to false?
{
	mBitsInUse ^= (1 << index);
	Set(index, false);
	std::cout << "TAKING BACK INDEX: " << index << std::endl;
	std::cout << std::bitset<64>(mBitsInUse) << std::endl;
}

void BitArray64::Set(int index, bool value)
{
	if (value)
	{
		mBits |= (1 << index);//turn on
		std::cout << "TURN VALUE AT INDEX: " << index << " ON" << std::endl;
		std::cout << std::bitset<64>(mBits) << std::endl;
	}
	else
	{
		mBits ^= (1 << index);//turn off
		std::cout << "TURN VALUE AT INDEX: " << index << " OFF" << std::endl;
		std::cout << std::bitset<64>(mBits) << std::endl;
	}
}

bool BitArray64::Value(int index)
{
	long long value = mBits & (1 << index);
	if (value > 0)
	{
		return true;
	}
	return false;
}

void BitArray64::Print()
{
	std::cout << std::bitset<64>(mBits) << std::endl;
}