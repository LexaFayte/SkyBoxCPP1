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

	// Get/Set
	SimpleMath::Vector3 getLookAt()
	{
		return mLookAt;
	}

	SimpleMath::Matrix getView() 
	{
		return mView;
	}

	SimpleMath::Vector3 getPosition() const noexcept
	{
		return mPosition;
	}

	void SetPosition(SimpleMath::Vector3& position)
	{
		mPosition = position;
		mBoundingSphere.sphere.Center = mPosition;
		mPreviewMove = mPosition;
	}

	SimpleMath::Matrix getProj() const noexcept
	{
		return mProj;
	}

	SimpleMath::Vector3 const getPreviewMove() const
	{
		return mPreviewMove;
	}


	CollisionSphere& getCollisionSphere()
	{
		return mBoundingSphere;
	}

	void Update(const Mouse::State& mouseState, const Keyboard::State& keyboardState, const GamePad::State& gamepadState);
	void Move();
	void handleCollision(SimpleMath::Vector3 nttPos);

private:
	const float kMoveSpeed = 0.30f;
	const float kMouseRotationSpeed = 0.007f;
	const float kGamePadRotationSpeed = 0.05f;
	const float kNearZ = 0.1f;
	const float kFarZ = 1000.0f;
	const float kRadius = 0.5f;

	SimpleMath::Vector3 mPosition = SimpleMath::Vector3::Zero;
	SimpleMath::Vector3 mRotation = SimpleMath::Vector3::Zero;
	SimpleMath::Vector3 mLookAt = SimpleMath::Vector3::Zero;
	float mYaw = 0.0f;
	float mPitch = 0.0f;

	SimpleMath::Vector3 mPreviewMove = SimpleMath::Vector3::Zero;
	SimpleMath::Vector3 mPreviousPos = SimpleMath::Vector3::Zero;

	SimpleMath::Matrix mView = SimpleMath::Matrix::Identity;
	SimpleMath::Matrix mProj = SimpleMath::Matrix::Identity;
	
	int mViewPortWidth;
	int mViewPortHeight;
	float mFOV = 70.0f;
	float mAspectRatio;

	CollisionSphere mBoundingSphere;

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