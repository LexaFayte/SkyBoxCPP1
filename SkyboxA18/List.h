#pragma once
#include <utility>
namespace Storage
{
	template<class T>
	class List
	{
	public:
		List();
		~List();

		List(const List<T>& other);
		List(List<T>&& other) noexcept;

		List<T>& operator=(const List<T>& other);
		List<T>& operator=(List<T>&& other) noexcept;

		unsigned int Count() const { return mCount; }

		void Add(const T& item);
		void Remove(const T& item);
		void RemoveAt(int index);
		void Clear();
		void Print();

		T& operator[](int index);

	private:
		template<class T>
		class Node
		{
		public:
			Node(const T& item, Node* next)
				: Item(item)
				, pNext(next)
			{
				// Empty
			}

			~Node()
			{
				delete pNext;
			}

			Node(const Node<T>& other) : Item(other.Item),
				pNext(other.pNext)
			{

			}

			Node<T>& operator=(const Node<T>& other)
			{
				if (*this == other)
				{
					return *this;
				}
				Item = other.Item;
				pNext = other.pNext;
				return *this;
			}

			Node(Node<T>&& other) noexcept : Item{ std::exchange(other.Item, 0) },
				pNext{ std::exchange(other.pNext, nullptr) }
			{

			}

			Node<T>& operator=(Node<T>&& other) noexcept
			{
				if (*this == other)
				{
					return *this;
				}

				Item = std::exchange(other.Item, 0);
				pNext = std::exchange(other.pNext, nullptr);
			}

			T Item;
			Node* pNext;
		};

		Node<T>* pHead;
		unsigned int mCount;

		void CreateNode(Node<T>* pEnd, const T& item);
		void RemoveNode(Node<T>* pNode, Node<T>* pPrevious);
		void CopyNode(const Node<T>& n);
	};
}