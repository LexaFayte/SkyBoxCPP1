#include <iostream>
#include <map>

namespace MathUtil
{
	float add(float a, float b)
	{
		return a + b;
	}

	float subtract(float a, float b)
	{
		return a - b;
	}

	float multiply(float a, float b)
	{
		return a * b;
	}
	float divide(float a, float b)
	{
		if (b == 0)
		{
			throw "Error: Division by zero";			
		}

		return a / b;
		
	}
}

int main()
{
	using namespace MathUtil;
	
	system("pause");
	return 0;
}