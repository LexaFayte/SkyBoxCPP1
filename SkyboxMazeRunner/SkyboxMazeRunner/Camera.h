#pragma once
#include "pch.h"
using namespace DirectX;

class Camera
{
private:
	void CalculateLookAt();
	void CalculateView();

public:
	Camera(SimpleMath::Vector3 pos, SimpleMath::Vector3 rot, float aspectRatio, int VPW, int VPH);
	~Camera();

	//void Update(std::unique_ptr<DirectX::Keyboard>& keyboard, std::unique_ptr<DirectX::Mouse>& mouse, float deltaTime);

	// Get/Set
	SimpleMath::Vector3 getLookAt()
	{
		//CalculateLookAt();
		return mLookAt;
	}

	SimpleMath::Matrix getView() 
	{
		//CalculateView();
		return mView;
	}

	SimpleMath::Vector3 getPosition() const noexcept
	{
		return mPosition;
	}

	SimpleMath::Matrix getProj() const noexcept
	{
		return mProj;
	}

	void setPosition(const SimpleMath::Vector3 pos)
	{
		mPosition = pos;
	}


	void Update(const Mouse::State& mouseState, const Keyboard::State& keyboardState);

private:
	const float kMoveSpeed = 0.07f;
	const float kRotationSpeed = 0.004f;
	const float kNearZ = 0.1f;
	const float kFarZ = 1000.0f;

	SimpleMath::Vector3 mPosition;
	SimpleMath::Vector3 mRotation;
	SimpleMath::Vector3 mLookAt;
	float mYaw = 0.0f;
	float mPitch = 0.0f;

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