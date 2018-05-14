#pragma once
#include "Entity.h"

class Floor : public Entity
{
private:
	Vector3 m_Position = Vector3::Zero;
	Matrix m_World = Matrix::Identity;
	Model m_Model;

	
public:
	Floor();
	Floor(Vector3 pos);
	~Floor();

	virtual void Render(ID3D11DeviceContext* dc, const CommonStates &states, Matrix view, Matrix proj) override;
	virtual void Update(float deltaTime) override;
	void SetPosition(Vector3 pos);
	void SetModel(Model m);
};