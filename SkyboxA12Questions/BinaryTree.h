#pragma once
#include <iostream>
#include <iomanip>
#include <initializer_list>
#define COUNT 10

struct BinaryNode
{
	BinaryNode(int val) :value(val){}

	~BinaryNode()
	{
		delete left;
		delete right;
	}

	int value = 0;
	BinaryNode* left = nullptr;
	BinaryNode* right = nullptr;
};

inline bool operator>(const BinaryNode& lhs, const BinaryNode& rhs)
{
	return lhs.value > rhs.value;
}

inline bool operator<(const BinaryNode& lhs, const BinaryNode& rhs)
{
	return lhs.value < rhs.value;
}

inline bool operator==(const BinaryNode& lhs, const BinaryNode& rhs)
{
	return lhs.value == rhs.value;
}

inline bool operator!=(const BinaryNode& lhs, const BinaryNode& rhs)
{
	return lhs.value != rhs.value;
}

class BinaryTree
{

public:
	BinaryTree() {};
	BinaryTree(int val);
	BinaryTree(std::initializer_list<int> list);

	~BinaryTree()
	{
		delete root;
	}

	BinaryNode* const getRoot() const noexcept { return root; }

	void AddNode(int val, BinaryNode*& root);
	void RemoveNode(int val, BinaryNode* rootPtr);
	int FindMin(BinaryNode* nodePtr);
	int FindMaxDepth(BinaryNode* rootPtr, int currentDepth = 0, int maxDepth = 0);

	void Print(BinaryNode *root, int space = 0)
	{
		// Base case
		if (root == nullptr)
			return;

		// Increase distance between levels
		space += COUNT;

		// Process right child first
		Print(root->right, space);

		// Print current node after space
		// count
		printf("\n");
		for (int i = COUNT; i < space; i++)
			printf(" ");
		printf("%d\n", root->value);

		// Process left child
		Print(root->left, space);
	}

private:
	BinaryNode * root = nullptr;
	void RemoveRoot();
	void RemoveNonRootNode(BinaryNode* parentNode, BinaryNode* matchedNode, bool leftChild);
};
