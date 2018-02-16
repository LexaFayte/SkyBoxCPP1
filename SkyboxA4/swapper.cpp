#include "swapper.h"

void swapper::swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void swapper::swap(bool &a, bool &b)
{
	std::swap(a, b);
}

void swapper::swap(std::string &a, std::string &b)
{
	std::string temp = std::move(a);
	a = std::move(b);
	b = std::move(temp);
}
