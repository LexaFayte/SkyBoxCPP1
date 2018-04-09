#pragma once
#include <DirectXCollision.h>

using namespace DirectX;

struct CollisionSphere
{
	BoundingSphere sphere;
	ContainmentType collision;
};