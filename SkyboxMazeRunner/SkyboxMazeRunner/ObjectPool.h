#pragma once
#include <vector>
#include "Wall.h"

#define USING 1
#define FREE 0

template<class T>
class ObjectPool
{
	private:
		std::vector<T> mObjects;


	public:
		ObjectPool<T>()
		{
			mObjects.reserve(100);
		}

		ObjectPool<T>(size_t size)
		{
			mObjects.reserve(size);
		}

		~ObjectPool<T>() {}

};


// specialization
template<>
class ObjectPool<Wall*>
{
private:
	size_t mPoolSize = 128;
	std::vector<Wall*> mObjects;
	std::vector<__int8> mObjectsInUse;

	void Expand();

public:
	ObjectPool()
	{
		mObjects.reserve(mPoolSize);
		mObjectsInUse.reserve(mPoolSize);
		for (int i = 0; i < mPoolSize; ++i)
		{
			mObjects.emplace_back(new Wall());
			mObjectsInUse.push_back(0);
		}
	}

	ObjectPool(size_t size)
	{
		mObjects.reserve(size);
	}

	~ObjectPool() 
	{
		for (int i = 0; i < mPoolSize; ++i)
		{
			delete mObjects[i];
		}
	}

	ObjectPool(const ObjectPool& other) = delete;
	ObjectPool(ObjectPool&& other) = delete;
	ObjectPool& operator=(const ObjectPool& other) = delete;
	ObjectPool& operator=(ObjectPool&& other) = delete;
	

	Wall* GetNext();
	void Return(Wall* w);

};