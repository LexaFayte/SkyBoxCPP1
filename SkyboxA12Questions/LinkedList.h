#pragma once
#include <initializer_list>
#include <iostream>

struct Node
{
	Node(int val) : value(val) {};
	~Node() 
	{
		value = 0;
		if (next != nullptr)
		{
			delete next;
		}
	};
	int value = 0;
	Node* next = nullptr;
};

class LinkedList
{
public:
	LinkedList();
	LinkedList(int val);
	LinkedList(std::initializer_list<int> list);
	~LinkedList();

	LinkedList(const LinkedList& other);
	LinkedList(LinkedList&& other);

	LinkedList& operator=(const LinkedList& other);
	LinkedList& operator=(LinkedList&& other);

	Node* getRoot() noexcept { return root; };
	const int const GetSize() const noexcept { return size; }
	void AddNode(Node*& rootPtr, int value);
	void Reverse(Node* rootPtr, int ListSize);
	void Print(const Node* root) const;


private:
	Node * root = nullptr;
	int size = 0;
};
