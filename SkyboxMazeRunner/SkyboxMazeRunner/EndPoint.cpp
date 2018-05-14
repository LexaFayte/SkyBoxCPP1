#include "pch.h"
#include "EndPoint.h"

EndPoint::EndPoint() :Entity(EntityTag::End) {};
EndPoint::EndPoint(Vector3 pos) :Entity(EntityTag::End), m_Position(pos) {};
EndPoint::EndPoint(int x, int z) :Entity(EntityTag::End) 
{
	m_Position = ConvertPosition(x, z);
};

EndPoint::~EndPoint() {};

void EndPoint::Render(ID3D11DeviceContext* dc, const DirectX::CommonStates &states, Matrix view, SimpleMath::Matrix proj)
{
	m_Model.UpdateEffects([&](IEffect* effect)
	{
		auto lights = dynamic_cast<IEffectLights*>(effect);
		if (lights)
		{
			lights->SetLightingEnabled(true);
			lights->SetPerPixelLighting(true);
			lights->SetLightEnabled(0, true);
			lights->SetLightEnabled(1, false);
			lights->SetLightEnabled(2, false);
			lights->SetAmbientLightColor(Colors::WhiteSmoke);
			lights->SetLightDiffuseColor(0, Colors::WhiteSmoke);
			lights->SetLightDiffuseColor(1, Colors::WhiteSmoke);
		}
	});
	m_Model.Draw(dc, states, m_World, view, proj);
}

void EndPoint::Update(float deltaTime)
{
	// order of mult = T * R * S	to rotate in the world
	// order of mult = R * T to rotate around local center

	if (m_FloatDirection == 1)
	{
		m_Position.y += 0.01f;
	}
	else
	{
		m_Position.y -= 0.01f;
	}

	if (m_Position.y >= 2.5f)
	{
		m_FloatDirection = 0;
	}
	else if (m_Position.y <= 1.5f)
	{
		m_FloatDirection = 1;
	}


	m_World = Matrix::CreateRotationY(1.5f*deltaTime) * Matrix::CreateTranslation(m_Position);
}

void EndPoint::SetModel(Model& m)
{
	m_Model = m;
	m_AABB.Extents = m_Model.meshes[0]->boundingBox.Extents;
	m_AABB.Center = m_Position;
}

Vector3 EndPoint::ConvertPosition(int x, int z)
{
	return Vector3(x * Constants::k_ModelPositionModifier, m_PositonY, z * Constants::k_ModelPositionModifier);
}