#include <iostream>
#include <map>
#include <functional>
#include <stdexcept>
#include <string>

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
			throw std::overflow_error("Divide by zero exception");
		}

		return a / b;
	}
}

int main()
{
	using namespace MathUtil;
	
	using arithmeticFunction = std::function<float(float, float)>;
	std::map<char, arithmeticFunction> functions = {
		std::pair<char,arithmeticFunction>('+',add),
		std::pair<char,arithmeticFunction>('-',subtract),
		std::pair<char,arithmeticFunction>('*',multiply),
		std::pair<char,arithmeticFunction>('/',divide)
	};

	float lhs = 0;
	float rhs = 0;
	char operation = ' ';
	
	std::cout << "please enter the first number of the arithmetic expresion to calculate: ";
	std::cin >> lhs;
	std::cout << "please enter the second number of the arithmetic expression to calculate: ";
	std::cin >> rhs;
	std::cout << "please enter the arithmetic operation you want to execute (+, -, *, /)";
	std::cin >> operation;

	float result = 0;
	switch (operation)
	{
	case '+':
	case '-':
	case '*':
	case '/':
		try
		{
			result = functions[operation](lhs, rhs);
		}
		catch (std::overflow_error e)
		{
			std::cout << e.what() << std::endl;
			std::cout << "exiting the program" << std::endl;
			system("pause");
			return 0;
		}
		break;
	}
	
	std::cout << std::endl;
	std::cout << lhs << " " << operation << " " << rhs << " = " << result << std::endl;

	system("pause");
	return 0;
}