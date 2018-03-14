#include "FloatArray.h"

FloatArray::FloatArray()
{
	// Empty
	const int size = mCapacity;
	mpFloats = new float[size] {0.0f};
}

FloatArray::~FloatArray()
{
	// Empty
	delete[] mpFloats;
}

void FloatArray::Add(float value)
{
	// TODO:

	// Add a float value to the end of the current array (mpFloats).
	// Remember: An array is a contiguous block of memory, to add a new element you need to allocate a whole new array.

	// The size of this new array should be:
	//		The size of the old array + 1.
	// Copy the old array and add the new value into the end of the newly allocated array.

	// mpFloats should store this new array.

	// WATCH OUT FOR MEMORY LEAKS!

	if (mNumberOfFloats + 1 < mCapacity)
	{
		*(mpFloats + mNumberOfFloats) = value;
	}
	else
	{
		Expand();
		*(mpFloats + mNumberOfFloats) = value;
	}
	++mNumberOfFloats;
}

void FloatArray::Remove(int index)
{
	// TODO:

	// Remove the index from the array (mpFloats).
	// Remember: An array is a contiguous block of memory, to remove an element you need to allocate a whole new array.

	// The size of this new array should be:
	//		The size of the old array - 1
	// Copy the old array into the newly allocated array, expect the index being removed.

	// mpFloats should store this new array.

	// MAKE SURE THE INDEX PASSED IN IS VALID!
	// WATCH OUT FOR MEMORY LEAKS!

	if (index < mNumberOfFloats && index >= 0)
	{
		float* numToRemove = mpFloats + index;
		int range = mNumberOfFloats - index;
		Shift(numToRemove, range);
		--mNumberOfFloats;
	}

	
}

void FloatArray::Shift(float* begin, int range)
{
	for (int i = 0; i < range; ++i)
	{
		float* temp = begin + 1;
		*begin = *temp;
		*temp = 0;
		++begin;
	}
}

void FloatArray::Expand()
{
	const int newSize = mCapacity * 2;
	float* tempFloatsArray = new float[newSize] {0.0f};

	float* tempCursorNew = tempFloatsArray;
	float* tempCursorOG = mpFloats;
	
	for (int i = 0; i < mCapacity; ++i)
	{
		*tempCursorNew = *tempCursorOG;
		++tempCursorNew;
		++tempCursorOG;
	}
	
	delete[] mpFloats;
	mpFloats = tempFloatsArray;
}

void FloatArray::Resize(const int size)
{
	if (size < 0)
	{
		return;
	}

	float* tempFloatsArray = new float[size] {0.0f};
	mCapacity = size;

	float* tempCursorNew = tempFloatsArray;
	float* tempCursorOG = mpFloats;

	for (int i = 0; i < mCapacity; ++i)
	{
		*tempCursorNew = *tempCursorOG;
		++tempCursorNew;
		++tempCursorOG;
	}

	delete[] mpFloats;
	mpFloats = tempFloatsArray;
}