#pragma once
#include <vector>
#include "Wall.h"

#define USING 1
#define FREE 0

template<class T>
class ObjectPool
{
	private:
		std::vector<T> m_Objects;


	public:
		ObjectPool<T>()
		{
			m_Objects.reserve(100);
		}

		ObjectPool<T>(size_t size)
		{
			m_Objects.reserve(size);
		}

		~ObjectPool<T>() {}

};


// specialization
template<>
class ObjectPool<Wall*>
{
private:
	size_t m_PoolSize = 128;
	std::vector<Wall*> m_Objects;
	std::vector<__int8> m_ObjectsInUse;

	void Expand();

public:
	ObjectPool()
	{
		m_Objects.reserve(m_PoolSize);
		m_ObjectsInUse.reserve(m_PoolSize);
		for (int i = 0; i < m_PoolSize; ++i)
		{
			m_Objects.emplace_back(new Wall());
			m_ObjectsInUse.push_back(0);
		}
	}

	ObjectPool(size_t size)
	{
		m_Objects.reserve(size);
	}

	~ObjectPool() 
	{
		for (int i = 0; i < m_PoolSize; ++i)
		{
			delete m_Objects[i];
		}
	}

	ObjectPool(const ObjectPool& other) = delete;
	ObjectPool(ObjectPool&& other) = delete;
	ObjectPool& operator=(const ObjectPool& other) = delete;
	ObjectPool& operator=(ObjectPool&& other) = delete;
	

	Wall* GetNext();
	void Return(Wall* w);

};