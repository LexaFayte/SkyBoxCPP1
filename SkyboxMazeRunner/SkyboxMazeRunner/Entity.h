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
		End,
		Floor,
		EnumCount
	};

public:
	Entity(EntityTag t);
	virtual ~Entity() {};

	virtual void Render(ID3D11DeviceContext* dc, const DirectX::CommonStates &states, SimpleMath::Matrix view, SimpleMath::Matrix proj) {};
	virtual void Update(float deltaTime) {};
	virtual void ResetModel() {};
	virtual void SetPosition(int x, int z) {};
	virtual const Model& GetModel() { return m; };
	virtual const BoundingBox& GetAABB() { return mAABB; };

	virtual const EntityTag& GetTag() noexcept { return tag; };
protected:
	EntityTag tag;
	Model m;
	BoundingBox mAABB;
};