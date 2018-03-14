#include <array>
#include <iostream>
#include "CustomClass.h"

void PrintArray(char* charArray)
{
	while (*charArray != '\0')
	{	
		std::cout << *charArray;
		++charArray;
	}
	std::cout << std::endl;
}

void ReverseArray(char* charArray, const int size)
{
	char* rArray = charArray + (size - 2);

	while (charArray < rArray)
	{
		char temp = *charArray;
		*charArray = *rArray;
		*rArray = temp;
		++charArray;
		--rArray;
	}
}

int main()
{
	const int SIZE = 6;
	char * characterArray = new char[SIZE];

	for (int i = 0; i < SIZE-1; ++i)
	{
		characterArray[i] = 65+i;
	}
	characterArray[SIZE - 1] = '\0';
	
	
	int* intArray = new int[10000];
	for (int i = 0; i < 10000; ++i)
	{
		intArray[i] = i;
	}

	CustomClass* customClassPtr = new CustomClass;

	PrintArray(characterArray);
	ReverseArray(characterArray, SIZE);
	PrintArray(characterArray);

	system("pause");

	delete customClassPtr;
	delete[] characterArray;
	delete[] intArray;
	return 0;
}