#pragma once
#include <string>
#include <iostream>

class swapper
{
public:
	static void run()
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

private:
	swapper() {}
	static void swap(int &a, int &b);
	static void swap(bool &a, bool &b);
	static void swap(std::string &a, std::string &b);
};