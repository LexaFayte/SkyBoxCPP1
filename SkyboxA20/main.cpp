#include <iostream>
#include "Button.h"
void Add(int num)
{
	std::cout << "ADD FUNC" << std::endl;
}

int main()
{

	int a = 127;
	std::function<void()> testFunction = [a]() {std::cout << a << std::endl; };
	std::function<void()> testFunction2 = []() {std::cout << "TEST 2" << std::endl; };
	std::function<void()> testFunction3 = []() {std::cout << "TEST 3" << std::endl; };
	std::function<void()> testFunction4 = std::bind(Add, 6);
	std::function<void()> testFunction5 = std::bind(Add, 10);
	
	Button b;
	
	b.PressCallBack += testFunction4;
	b.PressCallBack += testFunction;
	b.PressCallBack += testFunction2;
	b.PressCallBack += testFunction3;
	b.PressCallBack += testFunction5;

	b.Press();

	b.PressCallBack -= testFunction5;

	system("pause");
	return 0;
}