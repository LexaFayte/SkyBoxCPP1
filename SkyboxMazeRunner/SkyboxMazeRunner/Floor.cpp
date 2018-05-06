#include "pch.h"
#include "Floor.h"

Floor::Floor() : Entity(EntityTag::Floor) {};
Floor::Floor(Vector3 pos) : Entity(EntityTag::Floor), m_Position(pos) {};
Floor::~Floor() {};

void Floor::SetModel(Model m)
{
	m_Model = m;
}

void Floor::Render(ID3D11DeviceContext* dc, const CommonStates &states, Matrix view, Matrix proj)
{
	m_Model.UpdateEffects([](IEffect* effect)
	{
		auto lights = dynamic_cast<IEffectLights*>(effect);
		if (lights)
		{
			lights->SetLightingEnabled(true);
			lights->SetPerPixelLighting(true);
			lights->SetLightEnabled(0, true);
			lights->SetLightEnabled(1, false);
			lights->SetLightEnabled(2, false);
		}
	});

	m_Model.Draw(dc, states, m_World, view, proj);
}

void Floor::Update(float deltaTime)
{
	m_World = Matrix::CreateScale(10) * Matrix::CreateTranslation(m_Position);
}

void Floor::SetPosition(Vector3 pos)
{
	m_Position = pos;
}