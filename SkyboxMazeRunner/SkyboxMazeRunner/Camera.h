#pragma once
#include "pch.h"

class Camera
{
private:
	void CalculateLookAt();
	void CalculateView();

public:
	Camera(Vector3 pos, Vector3 rot, float aspectRatio, int VPW, int VPH);
	~Camera();

	// Get/Set
	Vector3 getLookAt()
	{
		return m_LookAt;
	}

	Matrix getView() 
	{
		return m_View;
	}

	Vector3 getPosition() const noexcept
	{
		return m_Position;
	}

	void SetPosition(Vector3& position)
	{
		m_Position = position;
		m_BoundingSphere.sphere.Center = m_Position;
		m_PreviewMove = m_Position;
	}

	Matrix getProj() const noexcept
	{
		return m_Proj;
	}

	Vector3 const getPreviewMove() const
	{
		return m_PreviewMove;
	}


	CollisionSphere& getCollisionSphere()
	{
		return m_BoundingSphere;
	}

	void Update(const Mouse::State& mouseState, const Keyboard::State& keyboardState, const GamePad::State& gamepadState);
	void Move();
	void handleCollision(SimpleMath::Vector3 nttPos);

private:
	const float k_MoveSpeed = 0.30f;
	const float k_MouseRotationSpeed = 0.007f;
	const float k_GamePadRotationSpeed = 0.05f;
	const float k_NearZ = 0.1f;
	const float k_FarZ = 1000.0f;
	const float k_Radius = 0.5f;

	Vector3 m_Position = Vector3::Zero;
	Vector3 m_Rotation = Vector3::Zero;
	Vector3 m_LookAt = Vector3::Zero;
	float m_Yaw = 0.0f;
	float m_Pitch = 0.0f;

	Vector3 m_PreviewMove = Vector3::Zero;
	Vector3 m_PreviousPos = Vector3::Zero;

	Matrix m_View = Matrix::Identity;
	Matrix m_Proj = Matrix::Identity;
	
	int m_ViewPortWidth;
	int m_ViewPortHeight;
	float m_FOV = 70.0f;
	float m_AspectRatio;

	CollisionSphere m_BoundingSphere;

	inline float clamp(float x, float a, float b)
	{
		return x < a ? a : (x > b ? b : x);
	}

	//C++ version of C# MathHelper.WarpAngle
	float wrapAngle(float angle)
	{
		angle = (double)std::remainder((double)angle, 6.2831854820251465f);
		if (angle <= -3.14159274f)
		{
			angle += 6.28318548f;
		}
		else
		{
			if (angle > 3.14159274f)
			{
				angle -= 6.28318548f;
			}
		}
		return angle;
	}
};