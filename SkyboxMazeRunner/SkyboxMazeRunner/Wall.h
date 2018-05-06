#pragma once
#include "pch.h"
#include "Entity.h"
using namespace DirectX;
using namespace SimpleMath;

class Wall : public Entity
{
private:
	float m_Width = 1.5f;
	float m_Height = 3.0f;
	BoundingBox m_AABB;
	Vector3 m_Position = Vector3::Zero;
	Matrix m_World = Matrix::Identity;
	Model m_Model;

	Vector3 ConvertPosition(int x, int z);

public:
	Wall();
	Wall(Vector3 pos);
	Wall(int x, int z);
	~Wall();

	virtual void Render(ID3D11DeviceContext* dc, const CommonStates &states, Matrix view, Matrix proj) override;
	virtual void Update(float deltaTime) override;
	virtual void SetPosition(int x, int z) override { m_Position = ConvertPosition(x, z); };
	virtual const Model& GetModel() override { return m_Model; };
	virtual const BoundingBox& GetAABB() override { return m_AABB; };
	void SetModel(Model m);

};