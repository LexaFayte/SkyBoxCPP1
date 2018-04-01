#include <iostream>
#include "LinkedList.h"
#include "BinaryTree.h"

int main()
{
	LinkedList l{ 0,1,2,3,4,5 };
	l.Print(l.getRoot());
	std::cout << std::endl;
	l.Reverse(l.getRoot(), l.GetSize());
	l.Print(l.getRoot());
	std::cout << std::endl;
	std::cout << "\n\n";

	BinaryTree bt{ 5,2,7,9,4,3 };
	bt.Print(bt.getRoot());
	std::cout << "\n\n";
	int maxDepth = 0;
	maxDepth = bt.FindMaxDepth(bt.getRoot());
	std::cout << "Max Depth: " << maxDepth << std::endl;
	system("pause");
	return 0;
}