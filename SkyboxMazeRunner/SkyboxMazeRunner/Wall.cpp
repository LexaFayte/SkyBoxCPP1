#include "pch.h"
#include "Wall.h"

Wall::~Wall() {}
Wall::Wall() : Entity(EntityTag::Wall) {}
Wall::Wall(Vector3 pos) : Entity(EntityTag::Wall), m_Position(pos) {}

Wall::Wall(int x, int z) : Entity(EntityTag::Wall)
{
	m_Position = ConvertPosition(x, z);
}

Vector3 Wall::ConvertPosition(int x, int z)
{
	return Vector3(x *(200 * 0.06f), 0, z*(200 * 0.06f));
}

void Wall::SetModel(Model m)
{
	m_Model = m;
	m_AABB.Extents = m_Model.meshes[0]->boundingBox.Extents;
	m_AABB.Center = m_Position;	
}

void Wall::Render(ID3D11DeviceContext* dc, const DirectX::CommonStates &states, Matrix view, SimpleMath::Matrix proj)
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

void Wall::Update(float deltaTime)
{
	m_World = Matrix::CreateTranslation(m_Position);
}