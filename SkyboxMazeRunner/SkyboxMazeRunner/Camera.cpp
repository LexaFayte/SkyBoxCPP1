#include "pch.h"
#include "Camera.h"
#include <algorithm>

Camera::Camera() {};

Camera::~Camera() {};

SimpleMath::Vector3 Camera::CalculateLookAt()
{
	float y = sinf(mPitch);
	float r = cosf(mPitch);
	float z = r * cosf(mYaw);
	float x = r * sinf(mYaw);	

	mLookAt = mPosition + SimpleMath::Vector3(x, y, z);
}

void Camera::Update(const Mouse::State& mouseState, const Keyboard::State& keyboardState)
{
	if (keyboardState.Escape)
	{
		PostQuitMessage(0);
	}

	if (mouseState.positionMode == Mouse::MODE_RELATIVE)
	{
		SimpleMath::Vector3 delta = SimpleMath::Vector3(float(mouseState.x), float(mouseState.y), 0.0f) * kSpeed;
		
		mPitch -= delta.y;
		mYaw -= delta.x;

		//can replace with call to clamp?
		float limit = XM_PI / 2.0f - 0.01f;
		mPitch = std::max(-limit, mPitch);
		mPitch = std::min(+limit, mPitch);

		//can replace with call to wrap?
		if (mYaw > XM_PI)
		{
			mYaw -= XM_PI * 2.0f;
		}
		else if (mYaw < -XM_PI)
		{
			mYaw += XM_PI * 2.0f;
		}
	}

	SimpleMath::Vector3 move = SimpleMath::Vector3::Zero;

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

	SimpleMath::Quaternion q = SimpleMath::Quaternion::CreateFromYawPitchRoll(mYaw, 0.0f, 0.0f);//pitch (param 2) set to zero to avoid ascending and descending
	move = SimpleMath::Vector3::Transform(move, q);

	move *= kSpeed;
	mPosition += move;

	CalculateLookAt();
}