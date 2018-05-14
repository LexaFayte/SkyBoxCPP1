#pragma once
#include "pch.h"
#include "Entity.h"

class EndPoint : public Entity
{
public:
	EndPoint();
	EndPoint(Vector3 pos);
	EndPoint(int x, int z);
	~EndPoint();

	virtual void Render(ID3D11DeviceContext* dc, const CommonStates &states, Matrix view, Matrix proj) override;
	virtual void Update(float deltaTime) override;
	virtual void SetPosition(int x, int z) override 
	{
		m_Position = ConvertPosition(x,z);
		m_AABB.Center = m_Position;
	};

	virtual const Model& GetModel() override { return m_Model; };
	virtual const BoundingBox& GetAABB() override { return m_AABB; };
	void SetModel(Model& m);

private:
	int m_FloatDirection = 1;
	float m_PositonY = 2.0f;
	DirectX::Model m_Model;
	Matrix m_World = Matrix::Identity;
	Vector3 m_Position = Vector3::Zero;
	BoundingBox m_AABB;

	Vector3 ConvertPosition(int x, int z);
};