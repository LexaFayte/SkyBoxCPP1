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
	virtual const Model& GetModel() override { return *mModel; };
	void LoadModel(ID3D11Device* device, const wchar_t* filename, DirectX::IEffectFactory &fxFactory);

private:
	std::unique_ptr<DirectX::Model> mModel;
	Matrix mWorld = Matrix::Identity;
	Vector3 mPos = Vector3::Zero;
	int floatDir = 1;
};