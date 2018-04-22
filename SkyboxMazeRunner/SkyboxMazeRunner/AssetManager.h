#pragma once
#include "pch.h"
#include "Entity.h"
#include <map>

class AssetManager
{
private:
	std::map<Entity::EntityTag, std::unique_ptr<DirectX::Model>> mModels;
public:
	AssetManager() {};

	void RegisterModel(ID3D11Device * device, const wchar_t * filename, IEffectFactory & fxFactory, Entity::EntityTag tag);
	DirectX::Model GetModel(Entity::EntityTag tag);

};