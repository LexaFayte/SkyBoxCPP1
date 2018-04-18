#include "List.h"
#include <iostream>

namespace Storage
{
	template<class T>
	List<T>::List()
		: mCount(0)
		, pHead(nullptr)
	{
		// Empty
	}

	// ----------------------------------------------------------------------------------------------------

	template<class T>
	List<T>::~List()
	{
		delete pHead;
	}

	// ----------------------------------------------------------------------------------------------------

	template<class T>
	List<T>::List(const List<T>& other)
	{
		std::cout << "COPY CONSTRUCTOR" << std::endl;
		CreateNode(pHead, other.pHead->Item);

		Node<T>* conductor = other.pHead->pNext;
		while (conductor != nullptr)
		{
			CopyNode(*conductor);
			conductor = conductor->pNext;
		}
	}

	// ----------------------------------------------------------------------------------------------------

	template<class T>
	List<T>& List<T>::operator=(const List<T>& other)
	{
		std::cout << "COPY ASSINGNEMT" << std::endl;
		if (this == &other)
		{
			return *this;
		}

		CreateNode(pHead, other.pHead->Item);

		Node<T>* conductor = other.pHead->pNext;
		while (conductor != nullptr)
		{
			CopyNode(*conductor);
			conductor = conductor->pNext;
		}

		return *this;
	}

	// ----------------------------------------------------------------------------------------------------

	template<class T>
	List<T>::List(List<T>&& other) noexcept :
		pHead{std::exchange(other.pHead, nullptr)}
	{
		std::cout << "MOVE CONSTRUCTOR" << std::endl;
	}

	// ----------------------------------------------------------------------------------------------------

	template<class T>
	List<T>& List<T>::operator=(List<T>&& other) noexcept
	{
		std::cout << "MOVE ASSIGNMENT" << std::endl;
		if (this == &other)
		{
			return *this;
		}

		pHead = std::exchange(other.pHead, nullptr);
		return *this;
	}

	// ----------------------------------------------------------------------------------------------------

	template<class T>
	void List<T>::Add(const T& item)
	{
		Node<T>* pEnd = pHead;
		Node<T>* pCurrent = pHead;

		while (pCurrent != nullptr)
		{
			pEnd = pCurrent;
			pCurrent = pCurrent->pNext;
		}

		CreateNode(pEnd, item);
	}

	// ----------------------------------------------------------------------------------------------------

	template<class T>
	void List<T>::Remove(const T& item)
	{
		Node<T>* pCurrent = pHead;
		Node<T>* pPrevious = nullptr;

		while (pCurrent != nullptr)
		{
			if (pCurrent->Item == item)
			{
				RemoveNode(pCurrent, pPrevious);
				break;
			}

			pPrevious = pCurrent;
			pCurrent = pCurrent->pNext;
		}
	}

	// ----------------------------------------------------------------------------------------------------

	template<class T>
	void List<T>::RemoveAt(int index)
	{
		Node<T>* pCurrent = pHead;
		Node<T>* pPrevious = nullptr;

		int currentIndex = 0;
		while (pCurrent != nullptr)
		{
			if (currentIndex == index)
			{
				RemoveNode(pCurrent, pPrevious);
				break;
			}

			pPrevious = pCurrent;
			pCurrent = pCurrent->pNext;
		}
	}

	// ----------------------------------------------------------------------------------------------------

	template<class T>
	void List<T>::Clear()
	{
		delete pHead;
	}

	// ----------------------------------------------------------------------------------------------------

	template<class T>
	T& List<T>::operator[](int index)
	{
		Node<T>* pCurrent = pHead;
		for (int i = 0; i < index; ++i)
		{
			pCurrent = pCurrent->pNext;
		}

		return pCurrent->Item;
	}

	// ----------------------------------------------------------------------------------------------------

	template<class T>
	void List<T>::CreateNode(Node<T>* pEnd, const T& item)
	{
		Node<T>* pNewNode = new Node<T>(item, nullptr);

		if (pEnd != nullptr)
		{
			pEnd->pNext = pNewNode;
		}
		else
		{
			pHead = pNewNode;
		}
		++mCount;
	}

	// ----------------------------------------------------------------------------------------------------

	template<class T>
	void List<T>::RemoveNode(Node<T>* pNode, Node<T>* pPrevious)
	{
		if (pPrevious == nullptr)
		{
			pHead = pNode->pNext;
		}
		else
		{
			pPrevious->pNext = pNode->pNext;
		}

		delete pNode;
		pNode = nullptr;

		--mCount;
	}

	// ----------------------------------------------------------------------------------------------------

	template<class T>
	void List<T>::Print()
	{
		Node<T>* conductor = pHead;
		while (conductor != nullptr)
		{
			std::cout << conductor->Item << std::endl;
			conductor = conductor->pNext;
		}
	}

	// ----------------------------------------------------------------------------------------------------

	template<class T>
	void List<T>::CopyNode(const Node<T>& n)
	{
		Node<T>* pNewNode = new Node<T>(n);
		pNewNode->pNext = nullptr;
		Node<T>* pEnd = pHead;
		Node<T>* pCurrent = pHead;

		while (pCurrent != nullptr)
		{
			pEnd = pCurrent;
			pCurrent = pCurrent->pNext;
		}

		pEnd->pNext = pNewNode;
		++mCount;
	}
}