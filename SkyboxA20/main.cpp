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
	CallBackFunction func1 = b.CreateCallBackFunction(testFunction4);
	CallBackFunction func2 = b.CreateCallBackFunction(testFunction);
	CallBackFunction func3 = b.CreateCallBackFunction(testFunction2);
	CallBackFunction func4 = b.CreateCallBackFunction(testFunction3);
	CallBackFunction func5 = b.CreateCallBackFunction(testFunction5);
	
	b.PressCallBack += func1;
	b.PressCallBack += func2;
	b.PressCallBack += func3;
	b.PressCallBack += func4;
	b.PressCallBack += func5;

	b.Press();

	b.PressCallBack -= func5;

	system("pause");
	return 0;
}