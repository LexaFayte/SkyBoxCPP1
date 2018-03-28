#include "LinkedList.h"

LinkedList::LinkedList() {};

LinkedList::LinkedList(int val) : root(new Node(val)), size(1){};

LinkedList::LinkedList(std::initializer_list<int> list) : size(list.size())
{
	int counter = 0;
	Node* current = nullptr;
	
	for (int v : list)
	{
		if (counter == 0)
		{
			root = new Node(v);
			current = root;
			counter++;
		}
		else
		{
			current->next = new Node(v);
			current = current->next;
		}
	}
};

LinkedList::~LinkedList()
{
	if (root != nullptr)
	{
		delete root;
	}
}

void LinkedList::Reverse(Node* rootPtr, int ListSize)
{
	int curDepth = ListSize;
	Node* current = rootPtr;
	if (current->next == nullptr)
	{
		root = rootPtr;
		return;
	}

	Reverse(current->next, curDepth - 1);
	if (curDepth < size)
	{
		current->next->next = rootPtr;
	}
	else
	{
		current->next->next = rootPtr;
		current->next = nullptr;
	}
}

void LinkedList::AddNode(Node*& rootPtr, int val)
{
	if (rootPtr->next == nullptr)
	{
		rootPtr->next = new Node(val);
		++size;
		return;
	}

	AddNode(rootPtr->next, val);
}

void LinkedList::Print(const Node* root) const
{
	if (root == nullptr)
	{
		return;
	}

	std::cout << root->value << ", ";
	Print(root->next);
}