#pragma once
#include "pch.h"
using namespace DirectX;
using namespace SimpleMath;

class Entity
{
public:
	enum class EntityTag
	{
		Player,
		Enemy,
		Wall,
		EnumCount
	};

public:
	Entity(EntityTag t);
	virtual ~Entity() {};

	virtual void Render(ID3D11DeviceContext* dc, const DirectX::CommonStates &states, SimpleMath::Matrix view, SimpleMath::Matrix proj) {};
	virtual void Update(float deltaTime) {};
	virtual void ResetModel() {};

	virtual const EntityTag& const GetTag() const noexcept { return tag; };
protected:
	EntityTag tag;
};