#include <iostream>
#include <math.h>

void MultiPrint(int printAmount, char printCharacter);
float Distance(float x1, float y1, float x2, float y2);
void TotalFunction();

int main()
{
	std::cout << "MultiPrint with 4, 'z':" << std::endl;
	MultiPrint(4, 'z');
	std::cout << std::endl;
	std::cout << "Distance with (5,5) and (2,1):" << std::endl;
	float dist = Distance(5, 5, 2, 1);
	std::cout << "Distance is " << dist << std::endl;
	std::cout << std::endl;
	std::cout << "Totaling Function:" << std::endl;
	TotalFunction();

	system("pause");
	return 0;
}

void MultiPrint(int printAmount, char printCharacter)
{
	for (int i = 0; i < printAmount; ++i)
	{
		std::cout << printCharacter;
	}
}

float Distance(float x1, float y1, float x2, float y2)
{
	return std::sqrtf((std::powf((x2 - x1), 2)) + (std::powf((y2 - y1), 2)));
}

void TotalFunction()
{
	int x = 0;
	int y = 0;
	int p = 0;
	int s = 0;
	int total = 0;

	std::cout << "please enter a number: ";
	std::cin >> x;

	std::cout << "please enter another number: ";
	std::cin >> y;

	p = x * y;
	s = x + y;
	total = (2 * s) + p * (s - x)*(p + y);

	std::cout << "Total is: " << total << std::endl;
}

/*
	1. Difference between Scoped Enumeration and Global Enumeration; Global Enumerations do not require the use of a namespace and scope resolution operator for access
	to the enumerations, which can cause ambiguity if another Global Enumeration with the same name is created. A Scoped Enumeration requires the use of a namespace/class
	and scope resolution operator to access the enumerations.

	Scoped Enum example:
	Class ExampleEnums
	{
		public:
			enum examples
			{
				this,
				is,
				an,
				example
			}
	}

	or

	enum class ScopedEnum
	{
		this,
		is,
		class,
		enumeration
	}

	to use anywhere, must use the class name:
	ExampleEnums::examples::this;
	or
	ScopedEnum::class

	Global Enum example:

	enum GlobalExampleEnum
	{
		this,
		is,
		global
	}
	
	to use anywhere, can type the following because the scope isn't necessary (enforced):
	this;


	2. the Brake keyword will break out of the current loop or switch statement (it will stop execution of the loop or switch and exit it at that very spot);
	   the Continue keyword will jump back up to the top of the loop and continue iteration (it will skip over the rest of the code in the loop for that iteration).
	   Note that for both of these, they only break out of or skip over the current iteration in the loop they are called in;
	   so if a break is called in the inner most loop, the break will only be applied in the inner most loop, it will not break out of the entire nested loop statement.
*/