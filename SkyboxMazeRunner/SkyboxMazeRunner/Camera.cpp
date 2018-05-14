#include "pch.h"
#include "Camera.h"
#include <algorithm>

Camera::Camera(Vector3 pos, Vector3 rot, float aspectRatio, int VPW, int VPH) :
	m_Position(pos), m_AspectRatio(aspectRatio), m_ViewPortWidth(VPW), m_ViewPortHeight(VPH)
{
	m_View = Matrix::CreateLookAt(Vector3(2.0f, 2.0f, 2.0f),
		Vector3::Zero, Vector3::UnitY);

	m_Proj = Matrix::CreatePerspectiveFieldOfView(XMConvertToRadians(m_FOV), float(m_ViewPortWidth) / float(m_ViewPortHeight), k_NearZ, k_FarZ);
	m_BoundingSphere.sphere.Center = pos;
	m_BoundingSphere.sphere.Radius = k_Radius;
	m_BoundingSphere.collision = DISJOINT;
}

Camera::~Camera() {};

void Camera::CalculateLookAt()
{
	float y = sinf(m_Pitch);
	float r = cosf(m_Pitch);
	float z = r * cosf(m_Yaw);
	float x = r * sinf(m_Yaw);	

	m_LookAt = m_Position + Vector3(x, y, z);
}

void Camera::CalculateView()
{
	m_View = Matrix::CreateLookAt(m_Position, m_LookAt, Vector3::Up);
}

void Camera::Update(const Mouse::State& mouseState, const Keyboard::State& keyboardState, const GamePad::State& gamepadState)
{
	Vector3 delta;
	Vector3 move = Vector3::Zero;

	if (gamepadState.IsConnected())
	{
		delta = Vector3(float(gamepadState.thumbSticks.rightX), float(gamepadState.thumbSticks.rightY * -1), 0.0f) * k_GamePadRotationSpeed;


		m_Pitch -= delta.y;
		m_Yaw -= delta.x;

		float limit = XM_PI / 2.0f - 0.01f;
		m_Pitch = clamp(m_Pitch, -limit, limit);

		if (m_Yaw > XM_PI)
		{
			m_Yaw -= XM_PI * 2.0f;
		}
		else if (m_Yaw < -XM_PI)
		{
			m_Yaw += XM_PI * 2.0f;
		}

		move.x = gamepadState.thumbSticks.leftX * -1;
		move.z = gamepadState.thumbSticks.leftY;		

	}
	else
	{
		delta = Vector3(float(mouseState.x), float(mouseState.y), 0.0f) * k_MouseRotationSpeed;

		m_Pitch -= delta.y;
		m_Yaw -= delta.x;

		float limit = XM_PI / 2.0f - 0.01f;
		m_Pitch = clamp(m_Pitch, -limit, limit);

		if (m_Yaw > XM_PI)
		{
			m_Yaw -= XM_PI * 2.0f;
		}
		else if (m_Yaw < -XM_PI)
		{
			m_Yaw += XM_PI * 2.0f;
		}

		

		if (keyboardState.Up || keyboardState.W)
		{
			move.z += 1.0f;
		}

		if (keyboardState.Down || keyboardState.S)
		{
			move.z -= 1.0f;
		}

		if (keyboardState.Left || keyboardState.A)
		{
			move.x += 1.0f;
		}

		if (keyboardState.Right || keyboardState.D)
		{
			move.x -= 1.0f;
		}
	}

	Quaternion q = Quaternion::CreateFromYawPitchRoll(m_Yaw, 0.0f, 0.0f);//pitch (param 2) set to zero to avoid ascending and descending
	move = Vector3::Transform(move, q);

	move *= k_MoveSpeed;

	m_PreviewMove = m_Position + move;
	CalculateLookAt();
	CalculateView();
}

void Camera::Move()
{
	if (m_PreviewMove != Vector3::Zero)
	{
		m_PreviousPos = m_Position;
		m_Position = m_PreviewMove;
		m_BoundingSphere.sphere.Center = m_Position;
	}
	CalculateLookAt();
	CalculateView();
}

void Camera::handleCollision(Vector3 nttPos)
{
	m_Position = m_PreviousPos;
	m_BoundingSphere.sphere.Center = m_Position;

	CalculateLookAt();
	CalculateView();
}