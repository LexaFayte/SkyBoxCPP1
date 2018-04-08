#include <iostream>
#include <vector>
#include <ctime>
#include "Shorse.h"
#include "Platyporse.h"

#define ARRAY_MAX 4
#define RAND_MAX 100
#define FLOAT_MOD 1.653257

namespace Utils
{


	inline float getRandomFloat()
	{
		return ((rand() % RAND_MAX) + 1) * FLOAT_MOD;
	}

	inline int getRandomInt()
	{
		return (rand() % RAND_MAX) + 1;
	}

	template<typename T>
	const T* GetLargestItem(const T* items, unsigned int itemsSize)
	{
		const T* largest = items;

		for (int i = 0; i < itemsSize; ++i)
		{
			if (*largest < *(items + i))
			{
				largest = items + i;
			}
		}

		return largest;
	}

	template<typename T>
	const T* GetSmallestItem(const T* items, unsigned int itemsSize)
	{
		const T* smallest = items;

		for (int i = 0; i < itemsSize; ++i)
		{
			if (*(items + i) < *smallest)
			{
				smallest = items + i;
			}
		}

		return smallest;
	}
}

int main()
{
	using namespace Utils;
	srand(time(0));
	Shorse shorses[ARRAY_MAX] = {Shorse(getRandomInt()),Shorse(getRandomInt()) ,Shorse(getRandomInt()) ,Shorse(getRandomInt())};
	Platyporse platyporses[ARRAY_MAX] = {Platyporse(getRandomFloat()), Platyporse(getRandomFloat()), Platyporse(getRandomFloat()), Platyporse(getRandomFloat())};

	
	const Shorse* s = GetLargestItem(shorses, ARRAY_MAX);
	const Platyporse* p = GetLargestItem(platyporses, ARRAY_MAX);
	std::cout << "the Shorse with " << s->GetNumberOfTeeth() << " teeth is the largest item in the array of Shorses" << std::endl;
	std::cout << "the Platyporse with a bill length of " << p->GetLengthOfBill() << " is the largest item in the array of Platyporses" << std::endl;

	s = GetSmallestItem(shorses, ARRAY_MAX);
	p = GetSmallestItem(platyporses, ARRAY_MAX);
	std::cout << "the Shorse with " << s->GetNumberOfTeeth() << " teeth is the smallest item in the array of Shorses" << std::endl;
	std::cout << "the Platyporse with a bill length of " << p->GetLengthOfBill() << " is the smallest item in the array of Platyporses" << std::endl;

	system("pause");
	return 0;
}

