#pragma once
#include "pch.h"
#include "Entity.h"
using namespace DirectX;
using namespace SimpleMath;

class Wall : public Entity
{
public:
	Wall();
	Wall(Vector3 pos);
	Wall(int x, int z);
	~Wall();

	virtual void Render(ID3D11DeviceContext* dc, const CommonStates &states, Matrix view, Matrix proj) override;
	virtual void Update(float deltaTime) override;
	virtual void ResetModel() override;
	virtual void SetPosition(int x, int z) override { m_Pos = ConvertPosition(x, z); };
	virtual const Model& GetModel() override { return m_model; };
	virtual const BoundingBox& GetAABB() override { return m_AABB; };
	void LoadModel(ID3D11Device* device, const wchar_t* filename, DirectX::IEffectFactory &fxFactory);
	void SetModel(Model m);

private:
	DirectX::Model m_model;
	Matrix m_World = Matrix::Identity;
	Vector3 m_Pos = Vector3::Zero;
	float m_Width = 1.5;
	float m_Height = 3;
	BoundingBox m_AABB;
	Vector3 ConvertPosition(int x, int z);
};