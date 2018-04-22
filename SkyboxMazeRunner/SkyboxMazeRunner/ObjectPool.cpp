#include "pch.h"
#include "ObjectPool.h"

Wall* ObjectPool<Wall*>::GetNext()
{
	auto result = std::find(mObjectsInUse.begin(), mObjectsInUse.end(), FREE);
	size_t index = std::distance(mObjectsInUse.begin(), result);

	if(result == mObjectsInUse.end())
	{
		index = mPoolSize;
		Expand();	
	}
	
	mObjectsInUse[index] = USING;
	return mObjects[index];
}

void ObjectPool<Wall*>::Return(Wall* w)
{
	auto result = std::find(mObjects.begin(), mObjects.end(), w);

	if (result != mObjects.end())
	{
		int index = std::distance(mObjects.begin(), result);
		mObjectsInUse[index] = FREE;
	}
}

void ObjectPool<Wall*>::Expand()
{
	size_t currentSize = mPoolSize;
	mPoolSize += 100;	
	mObjects.reserve(100);
	mObjectsInUse.reserve(100);

	for (size_t i = currentSize; i < mPoolSize; ++i)
	{
		mObjects.emplace_back(new Wall());
		mObjectsInUse.push_back(FREE);
	}
}