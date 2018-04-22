#include "pch.h"
#include "EndPoint.h"

EndPoint::EndPoint() :Entity(EntityTag::End) {};
EndPoint::EndPoint(Vector3 pos) :Entity(EntityTag::End), mPos(pos) {};
EndPoint::EndPoint(int x, int z) :Entity(EntityTag::End) 
{
	mPos = ConvertPosition(x, z);
};

EndPoint::~EndPoint() {};

void EndPoint::LoadModel(ID3D11Device * device, const wchar_t * filename, IEffectFactory & fxFactory)
{
	//mModel = Model::CreateFromCMO(device, filename, fxFactory);
	//for (size_t i = 0; i < mModel->meshes.size(); ++i)
	//{
	//	mModel->meshes[i]->boundingBox.Center = mPos;
	//}
}

void EndPoint::Render(ID3D11DeviceContext* dc, const DirectX::CommonStates &states, Matrix view, SimpleMath::Matrix proj)
{
	mModel.UpdateEffects([&](IEffect* effect)
	{
		auto lights = dynamic_cast<IEffectLights*>(effect);
		if (lights)
		{
			lights->SetLightingEnabled(true);
			lights->SetPerPixelLighting(true);
			lights->SetLightEnabled(0, true);
			lights->SetLightEnabled(1, false);
			lights->SetLightEnabled(2, false);
			lights->SetAmbientLightColor(Colors::Gold);
			lights->SetLightDiffuseColor(0, Colors::Gold);
			lights->SetLightDiffuseColor(1, Colors::Gold);
			//lights->SetLightDiffuseColor(2, Colors::Gold);
		}
	});
	mModel.Draw(dc, states, mWorld, view, proj);
}

void EndPoint::Update(float deltaTime)
{
	// order of mult = T * R * S	to rotate in the world
	// order of mult = R * T to rotate around local center

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

void EndPoint::SetModel(Model& m)
{
	mModel = m;
	m_AABB.Extents = mModel.meshes[0]->boundingBox.Extents;
	m_AABB.Center = mPos;
}

void EndPoint::ResetModel()
{
	//mModel.reset();
}


Vector3 EndPoint::ConvertPosition(int x, int z)
{
	return Vector3(x * (200 * 0.06f), yPos, z * (200 * 0.06f));
}