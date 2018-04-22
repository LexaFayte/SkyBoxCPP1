#include "pch.h"
#include "AssetManager.h"
#include <utility>

void AssetManager::RegisterModel(ID3D11Device * device, const wchar_t * filename, IEffectFactory & fxFactory, Entity::EntityTag tag)
{
	mModels.insert(std::make_pair(tag, Model::CreateFromCMO(device, filename, fxFactory)));
}

DirectX::Model AssetManager::GetModel(Entity::EntityTag tag)
{
	return *mModels[tag];
}