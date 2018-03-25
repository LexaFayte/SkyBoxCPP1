#pragma once
#include "pch.h"
using namespace DirectX;

class Camera
{
public:
	//Camera(SimpleMath::Vector3 pos, SimpleMath::Vector3 rot, float aspectRatio, int VPW, int VPH);
	//~Camera();

	//void Update(std::unique_ptr<DirectX::Keyboard>& keyboard, std::unique_ptr<DirectX::Mouse>& mouse, float deltaTime);

	// Get/Set
	SimpleMath::Vector3 getLookAt() const noexcept
	{
		return mLookAt;
	}

	SimpleMath::Vector3 getPosition() const noexcept
	{
		return mPosition;
	}

	SimpleMath::Matrix getProj() const noexcept
	{
		return mProj;
	}

private:
	const float kSpeed = 0.05f;
	const float kNearZ = 0.1f;
	const float kFarZ = 1000.0f;

	SimpleMath::Vector3 mPosition;
	SimpleMath::Vector3 mRotation;
	SimpleMath::Vector3 mLookAt;
	SimpleMath::Vector3 mMouseRotationBuffer;
	SimpleMath::Vector3 mRS;

	SimpleMath::Matrix mView;
	SimpleMath::Matrix mProj;
	
	int mViewPortWidth;
	int mViewPortHeight;
	float mFOV = 70.0f;
	float mAspectRatio;

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