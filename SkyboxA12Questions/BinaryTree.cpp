#include "BinaryTree.h"

BinaryTree::BinaryTree(int val)
{
	root = new BinaryNode(val);
}

BinaryTree::BinaryTree(std::initializer_list<int> list)
{
	int count = 0;
	for (int val : list)
	{
		if (count == 0)
		{
			root = new BinaryNode(val);
			++count;
		}
		else
		{
			AddNode(val, root);
		}
	}
}

void BinaryTree::AddNode(int val, BinaryNode*& rootPtr)
{
	

	if (rootPtr == nullptr)
	{
		rootPtr = new BinaryNode(val);
		return;
	}

	if (val <= rootPtr->value)
	{
		AddNode(val, rootPtr->left);
	}
	else
	{
		AddNode(val, rootPtr->right);
	}
}

int BinaryTree::FindMaxDepth(BinaryNode* rootPtr, int currentDepth, int maxDepth)
{
	if (rootPtr == nullptr)
	{
		return maxDepth;
	}

	if (currentDepth > maxDepth)
	{
		maxDepth = currentDepth;
	}

	++currentDepth;
	maxDepth = FindMaxDepth(rootPtr->left, currentDepth, maxDepth);
	maxDepth = FindMaxDepth(rootPtr->right, currentDepth, maxDepth);
	return maxDepth;
}