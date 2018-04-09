#include "pch.h"
#include "EndPoint.h"

EndPoint::EndPoint() :Entity(EntityTag::End) {};
EndPoint::EndPoint(Vector3 pos) :Entity(EntityTag::End), mPos(pos) {};
EndPoint::EndPoint(int x, int z) :Entity(EntityTag::End) 
{
	mPos = Vector3(x * (200 * 0.06f), 0.0f, z * (200 * 0.06f));
};

EndPoint::~EndPoint() {};

void EndPoint::LoadModel(ID3D11Device * device, const wchar_t * filename, IEffectFactory & fxFactory)
{
	mModel = Model::CreateFromCMO(device, filename, fxFactory);
	for (int i = 0; i < mModel->meshes.size(); ++i)
	{
		mModel->meshes[i]->boundingBox.Center = mPos;
	}
}

void EndPoint::Render(ID3D11DeviceContext* dc, const DirectX::CommonStates &states, Matrix view, SimpleMath::Matrix proj)
{
	
	mModel->Draw(dc, states, mWorld, view, proj);
}

void EndPoint::Update(float deltaTime)
{
	// order of mult = T * R * S	

	if (floatDir == 1)
	{
		mPos.y += 0.01f;
	}
	else
	{
		mPos.y -= 0.01f;
	}

	if (mPos.y >= 2.5f)
	{
		floatDir = 0;
	}
	else if (mPos.y <= 1.5f)
	{
		floatDir = 1;
	}


	mWorld = Matrix::CreateRotationY(cosf(deltaTime) * 2.f) * Matrix::CreateTranslation(mPos);
}

void EndPoint::ResetModel()
{
	mModel.reset();
}