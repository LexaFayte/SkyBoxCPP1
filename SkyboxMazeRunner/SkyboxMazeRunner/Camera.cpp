#include "pch.h"
#include "Camera.h"
#include <algorithm>

Camera::Camera(SimpleMath::Vector3 pos, SimpleMath::Vector3 rot, float aspectRatio, int VPW, int VPH) :
	mPosition(pos), mAspectRatio(aspectRatio), mViewPortWidth(VPW), mViewPortHeight(VPH)
{
	mView = SimpleMath::Matrix::CreateLookAt(SimpleMath::Vector3(2.0f, 2.0f, 2.0f),
		SimpleMath::Vector3::Zero, SimpleMath::Vector3::UnitY);

	mProj = SimpleMath::Matrix::CreatePerspectiveFieldOfView(XMConvertToRadians(mFOV), float(mViewPortWidth) / float(mViewPortHeight), kNearZ, kFarZ);
	mBoundingSphere.sphere.Center = pos;
	mBoundingSphere.sphere.Radius = kRadius;
	mBoundingSphere.collision = DISJOINT;
}

Camera::~Camera() {};

void Camera::CalculateLookAt()
{
	float y = sinf(mPitch);
	float r = cosf(mPitch);
	float z = r * cosf(mYaw);
	float x = r * sinf(mYaw);	

	mLookAt = mPosition + SimpleMath::Vector3(x, y, z);
}

void Camera::CalculateView()
{
	mView = SimpleMath::Matrix::CreateLookAt(mPosition, mLookAt, SimpleMath::Vector3::Up);
}

void Camera::Update(const Mouse::State& mouseState, const Keyboard::State& keyboardState, const GamePad::State& gamepadState)
{
	if (keyboardState.Escape || gamepadState.buttons.back)
	{
		PostQuitMessage(0);
	}

	SimpleMath::Vector3 delta;
	SimpleMath::Vector3 move = SimpleMath::Vector3::Zero;

	if (gamepadState.IsConnected())
	{
		delta = SimpleMath::Vector3(float(gamepadState.thumbSticks.rightX), float(gamepadState.thumbSticks.rightY * -1), 0.0f) * kGamePadRotationSpeed;


		mPitch -= delta.y;
		mYaw -= delta.x;

		float limit = XM_PI / 2.0f - 0.01f;
		mPitch = clamp(mPitch, -limit, limit);

		if (mYaw > XM_PI)
		{
			mYaw -= XM_PI * 2.0f;
		}
		else if (mYaw < -XM_PI)
		{
			mYaw += XM_PI * 2.0f;
		}

		move.x = gamepadState.thumbSticks.leftX * -1;
		move.z = gamepadState.thumbSticks.leftY;		

	}
	else
	{
		delta = SimpleMath::Vector3(float(mouseState.x), float(mouseState.y), 0.0f) * kMouseRotationSpeed;

		mPitch -= delta.y;
		mYaw -= delta.x;

		float limit = XM_PI / 2.0f - 0.01f;
		mPitch = clamp(mPitch, -limit, limit);

		if (mYaw > XM_PI)
		{
			mYaw -= XM_PI * 2.0f;
		}
		else if (mYaw < -XM_PI)
		{
			mYaw += XM_PI * 2.0f;
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

	SimpleMath::Quaternion q = SimpleMath::Quaternion::CreateFromYawPitchRoll(mYaw, 0.0f, 0.0f);//pitch (param 2) set to zero to avoid ascending and descending
	move = SimpleMath::Vector3::Transform(move, q);

	move *= kMoveSpeed;

	//collision detection here
	mPreviewMove = mPosition + move;

	//mPosition += move;

	CalculateLookAt();
	CalculateView();
}

void Camera::Move()
{
	if (mPreviewMove != SimpleMath::Vector3::Zero)
	{
		mPreviousPos = mPosition;
		mPosition = mPreviewMove;
		mBoundingSphere.sphere.Center = mPosition;
	}
	CalculateLookAt();
	CalculateView();
}

void Camera::handleCollision(SimpleMath::Vector3 nttPos)
{
	//SimpleMath::Vector3 collisionMove = SimpleMath::Vector3::Zero;	
	//SimpleMath::Vector3 relativePos = nttPos - mPosition;
	
	//float wallNormalX = 0;


	//if (relativePos.x < 3.0f)
	//{
	//	//to the right of the wall
	//	wallNormalX = 1.0f;
	//}
	//else
	//{
	//	//to the left of the wall
	//	wallNormalX = -1.0f;
	//}

	//if (wallNormalX != 0)
	//{
	//	collisionMove.x += wallNormalX;
	//}

	//mPosition += collisionMove;
	mPosition = mPreviousPos;
	mBoundingSphere.sphere.Center = mPosition;

	CalculateLookAt();
	CalculateView();
}