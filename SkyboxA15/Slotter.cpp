#include "Slotter.h"
#include "Helper.h"

void Slotter::SetName(std::string& name)
{
	if (name.length() > 0 && Helper::CheckVowel(name[0]))
	{
		mName = name;
	}
	else
	{
		throw SlotterNameException();
	}
};

void Slotter::SetNumLegs(int numLegs) 
{
	if (numLegs % 2 == 1)
	{
		mNumLegs = numLegs; 
	}
	else
	{
		throw SlotterEvenLegNumberException();
	}
};

void Slotter::SetLength(float length)
{
	if (length > 0.001f && length < 0.1f)
	{
		mLength = length; 
	}
	else
	{
		throw SlotterLengthException();
	}
};

