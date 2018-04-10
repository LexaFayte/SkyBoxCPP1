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

LinkedList::LinkedList(const LinkedList& other) : size(other.size)
{
	if (other.root != nullptr)
	{
		Node* conductorOther = other.root;
		root = new Node(other.root->value);
		Node* conductorThis = root;

		while (conductorOther->next != nullptr)
		{
			conductorThis->next = new Node(conductorOther->next->value);
			conductorOther = conductorOther->next;
			conductorThis = conductorThis->next;
		}
	}
}

LinkedList::LinkedList(LinkedList&& other) :
	root{ std::exchange(other.root, nullptr) },
	size{std::exchange(other.size, 0)}
{

}

LinkedList& LinkedList::operator=(const LinkedList& other)
{
	if (this != &other)
	{
		delete root;
		size = other.size;
		if (other.root != nullptr)
		{
			Node* conductorOther = other.root;
			root = new Node(other.root->value);
			Node* conductorThis = root;

			while (conductorOther->next != nullptr)
			{
				conductorThis->next = new Node(conductorOther->next->value);
				conductorOther = conductorOther->next;
				conductorThis = conductorThis->next;
			}
		}
	}

	return *this;
}

LinkedList& LinkedList::operator=(LinkedList&& other)
{
	if (this != &other)
	{
		delete root;
		root = std::exchange(other.root, nullptr);
		size = std::exchange(other.size, 0);
	}

	return *this;
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

void LinkedList::RemoveNode(Node* rootPtr, int value)
{
	if (rootPtr->next == nullptr)
	{
		return;
	}

	if (rootPtr->next->value == value)
	{
		Node* temp = rootPtr->next->next;
		rootPtr->next->next = nullptr;
		delete rootPtr->next;
		rootPtr->next = temp;
		return;
	}
	else
	{
		RemoveNode(rootPtr->next, value);
	}
	
	return;
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