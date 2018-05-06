#include "pch.h"
#include "AssetManager.h"
#include <utility>

void AssetManager::RegisterModel(ID3D11Device * device, const wchar_t * filename, IEffectFactory & fxFactory, Entity::EntityTag tag)
{
	m_Models.insert(std::make_pair(tag, Model::CreateFromCMO(device, filename, fxFactory)));
}

DirectX::Model AssetManager::GetModel(Entity::EntityTag tag)
{
	return *m_Models[tag];
}

void AssetManager::Reset()
{
	for (auto it = m_Models.begin(); it != m_Models.end(); ++it)
	{
		it->second.reset();
	}
}