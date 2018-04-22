#include "pch.h"
#include "Wall.h"

Wall::~Wall() {}
Wall::Wall() : Entity(EntityTag::Wall) {}
Wall::Wall(Vector3 pos) : Entity(EntityTag::Wall), m_Pos(pos) {}

Wall::Wall(int x, int z) : Entity(EntityTag::Wall)
{
	m_Pos = ConvertPosition(x, z);
}

Vector3 Wall::ConvertPosition(int x, int z)
{
	return Vector3(x *(200 * 0.06f), 0, z*(200 * 0.06f));
}

void Wall::LoadModel(ID3D11Device * device, const wchar_t * filename, IEffectFactory & fxFactory)
{
	//m_model = Model::CreateFromCMO(device, filename, fxFactory);
	//for (size_t i = 0; i < m_model.meshes.size(); ++i)
	//{
	//	BoundingBox aabb;
	//	aabb.Extents = m_model.meshes[i]->boundingBox.Extents;
	//	aabb.Center = m_Pos;
	//	m_model.meshes[i]->boundingBox = aabb;
	//}
}

void Wall::SetModel(Model m)
{
	m_model = m;
	m_AABB.Extents = m_model.meshes[0]->boundingBox.Extents;
	m_AABB.Center = m_Pos;	
}

void Wall::Render(ID3D11DeviceContext* dc, const DirectX::CommonStates &states, Matrix view, SimpleMath::Matrix proj)
{
	m_model.UpdateEffects([&](IEffect* effect)
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

	m_model.Draw(dc, states, m_World, view, proj);
}

void Wall::Update(float deltaTime)
{
	m_World = Matrix::CreateTranslation(m_Pos);
}

void Wall::ResetModel()
{
	//m_model.reset();
}