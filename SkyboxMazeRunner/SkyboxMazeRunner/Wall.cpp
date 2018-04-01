#include "pch.h"
#include "Wall.h"

Wall::Wall() : Entity(EntityTag::Wall) {}
Wall::Wall(Vector3 pos) : Entity(EntityTag::Wall), m_Pos(pos) {}
Wall::Wall(int x, int z) : Entity(EntityTag::Wall)
{
	m_Pos = Vector3(x *(200*0.06f), 0, z*(200* 0.06f));
}
Wall::~Wall() {}

void Wall::LoadModel(ID3D11Device * device, const wchar_t * filename, IEffectFactory & fxFactory)
{
	m_model = Model::CreateFromCMO(device, filename, fxFactory);
}

void Wall::Render(ID3D11DeviceContext* dc, const DirectX::CommonStates &states, Matrix view, SimpleMath::Matrix proj)
{
	m_model->Draw(dc, states, m_World, view, proj);
}

void Wall::Update(float deltaTime)
{
	m_World = Matrix::CreateTranslation(m_Pos);
}

void Wall::ResetModel()
{
	m_model.reset();
}