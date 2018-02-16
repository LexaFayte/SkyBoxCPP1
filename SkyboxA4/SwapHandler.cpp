#include "SwapHandler.h"
#include <iostream>

SwapHandler::SwapHandler()
{}

SwapHandler::~SwapHandler()
{}

void SwapHandler::run()
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
}

void SwapHandler::swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void SwapHandler::swap(bool &a, bool &b)
{
	std::swap(a, b);
}

void SwapHandler::swap(std::string &a, std::string &b)
{
	std::string temp = std::move(a);
	a = std::move(b);
	b = std::move(temp);
}