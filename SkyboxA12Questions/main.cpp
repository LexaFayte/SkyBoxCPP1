#include <iostream>
#include "LinkedList.h"

int main()
{
	LinkedList l{ 0,1,2,3,4,5 };
	l.Print(l.getRoot());
	std::cout << std::endl;
	l.Reverse(l.getRoot(), l.GetSize());
	l.Print(l.getRoot());
	std::cout << std::endl;
	system("pause");
	return 0;
}