#include <string>
#include <iostream>

void swap(int &a, int &b);
void swap(bool &a, bool &b);
void swap(std::string &a,  std::string &b);

int main()
{
	{
		int a = 2;
		int b = 4;

		std::cout << "a: " << a << "; b: " << b << std::endl;
		std::cout << "swap" << std::endl;
		swap(a, b);
		std::cout << "a: " << a << "; b: " << b << std::endl;
		std::cout << std::endl;
	}

	{
		bool ba = true;
		bool bb = false;

		std::cout << "bool a: " << ba << "; bool b: " << bb << std::endl;
		std::cout << "swap using std::swap" << std::endl;
		swap(ba, bb);
		std::cout << "bool a: " << ba << "; bool b: " << bb << std::endl;
		std::cout << std::endl;
	}

	{
		std::string sa = "Hello";
		std::string sb = "World";

		std::cout << "string a: " << sa << "; string b: " << sb << std::endl;
		std::cout << "swap using std::move" << std::endl;
		swap(sa, sb);
		std::cout << "string a: " << sa << "; string b: " << sb << std::endl;
		std::cout << std::endl;
	}

	system("pause");
	return 0;
}

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void swap(bool &a, bool &b)
{
	std::swap(a, b);
}

void swap(std::string &a, std::string &b)
{
	std::string temp = std::move(a);
	a = std::move(b);
	b = std::move(temp);
}

/*
	1. int number = 10;
	this variable is stored on the main functions stack frame; the integer takes up 4 bytes of contiguous memory to store the number it holds.

	2. passing a variable in by reference means you do not make a local copy of the variable; anything that happens to this variable in the function is a permanent change to the actual
	variable itself (where ever it may be stored in memory); this is analogous to dereferencing a pointer - you are changing the actual value at the memory address.

	passing a variable by value means that a local copy of the variable is made; any changes made are made to the copy, and the copy is destroyed once the function returns as the variable
	will be out of scope - the original value will have no changes made to it.


*/