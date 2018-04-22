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
	virtual void ResetModel() override;
	virtual void SetPosition(int x, int z) override 
	{
		mPos = ConvertPosition(x,z);
		mAABB.Center = mPos;
	};

	virtual const Model& GetModel() override { return mModel; };
	virtual const BoundingBox& GetAABB() override { return m_AABB; };
	void LoadModel(ID3D11Device* device, const wchar_t* filename, DirectX::IEffectFactory &fxFactory);
	void SetModel(Model& m);

private:
	int floatDir = 1;
	float yPos = 2.0f;
	DirectX::Model mModel;
	Vector3 mPos = Vector3::Zero;
	Matrix mWorld = Matrix::Identity;
	BoundingBox m_AABB;

	Vector3 ConvertPosition(int x, int z);
};