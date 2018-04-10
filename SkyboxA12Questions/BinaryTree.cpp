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

void BinaryTree::RemoveNode(int val, BinaryNode* rootPtr)
{
	if (root != nullptr)
	{
		if (root->value == val)
		{
			//remove the root match
		}
		else
		{
			if (val < rootPtr->value && rootPtr->left != nullptr)
			{
				if (rootPtr->left->value == val)
				{
					//remove this node
					RemoveNonRootNode(rootPtr, rootPtr->left, true);
				}
				else
				{
					RemoveNode(val, rootPtr->left);
				}
			}
			else if (rootPtr->value < val && rootPtr->right != nullptr)
			{
				if (rootPtr->right->value == val)
				{
					//remove this node
					RemoveNonRootNode(rootPtr, rootPtr->right, false);
				}
				else
				{
					RemoveNode(val, rootPtr->right);
				}
			}
			else
			{
				std::cout << "Node with value " << val << " does not exist in the tree\n";
				return;
			}
		}
	}
}

void BinaryTree::RemoveNonRootNode(BinaryNode* parentNode, BinaryNode* matchedNode, bool leftChild)
{
	if (root != nullptr)
	{
		BinaryNode* nPtr = nullptr;
		int matchedValue = matchedNode->value;
		int minInRight = -1;

		// no children
		if (matchedNode->left == nullptr && matchedNode->right == nullptr)
		{
			nPtr = matchedNode;
			if (leftChild)
			{
				parentNode->left = nullptr;
			}
			else
			{
				parentNode->right = nullptr;
			}

			delete nPtr;
			return;
		}

		// only left child
		if (matchedNode->left != nullptr && matchedNode->right == nullptr)
		{
			if (leftChild)
			{
				parentNode->left = matchedNode->right;
			}
			else
			{
				parentNode->right = matchedNode->right;
			}
			matchedNode->right = nullptr;
			delete matchedNode;
			return;
		}

		// only right child
		if (matchedNode->left == nullptr && matchedNode->right != nullptr)
		{
			if (leftChild)
			{
				parentNode->left = matchedNode->left;
			}
			else
			{
				parentNode->right = matchedNode->left;
			}
			matchedNode->left = nullptr;
			delete matchedNode;
			return;
		}

		// has two children
		minInRight = FindMin(matchedNode->right);
		RemoveNode(minInRight, matchedNode);
		matchedNode->value = minInRight;
		return;
	}
}

void BinaryTree::RemoveRoot()
{
	if (root != nullptr)
	{
		BinaryNode* nPtr = root;
		int rootVal = root->value;
		int minValInRight;

		//no children
		if (root->left == nullptr && root->right == nullptr)
		{
			root = nullptr;
			delete nPtr;
			return;
		}

		// only right child
		if (root->left == nullptr && root->right != nullptr)
		{
			root = root->right;
			nPtr->right = nullptr;
			delete nPtr;
			return;
		}

		// only left child
		if (root->left != nullptr && root->right == nullptr)
		{
			root = root->left;
			nPtr->left = nullptr;
			delete nPtr;
			return;
		}

		// has two children
		minValInRight = FindMin(root->right);
		RemoveNode(minValInRight, root);
		root->value = minValInRight;
	}
	
}

int BinaryTree::FindMin(BinaryNode* rootPtr)
{
	if (rootPtr == nullptr)
	{
		return -1;
	}

	if (rootPtr->left != nullptr)
	{
		return FindMin(rootPtr->left);
	}
	else
	{
		return rootPtr->value;
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

