#include "pch.h"
#include "ObjectPool.h"

Wall* ObjectPool<Wall*>::GetNext()
{
	auto result = std::find(m_ObjectsInUse.begin(), m_ObjectsInUse.end(), FREE);
	size_t index = std::distance(m_ObjectsInUse.begin(), result);

	if(result == m_ObjectsInUse.end())
	{
		index = m_PoolSize;
		Expand();	
	}
	
	m_ObjectsInUse[index] = USING;
	return m_Objects[index];
}

void ObjectPool<Wall*>::Return(Wall* w)
{
	auto result = std::find(m_Objects.begin(), m_Objects.end(), w);

	if (result != m_Objects.end())
	{
		int index = std::distance(m_Objects.begin(), result);
		m_ObjectsInUse[index] = FREE;
	}
}

void ObjectPool<Wall*>::Expand()
{
	size_t currentSize = m_PoolSize;
	m_PoolSize += 100;	
	m_Objects.reserve(100);
	m_ObjectsInUse.reserve(100);

	for (size_t i = currentSize; i < m_PoolSize; ++i)
	{
		m_Objects.emplace_back(new Wall());
		m_ObjectsInUse.push_back(FREE);
	}
}