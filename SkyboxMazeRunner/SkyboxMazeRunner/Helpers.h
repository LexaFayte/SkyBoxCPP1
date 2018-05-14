#pragma once
#include <DirectXCollision.h>

using namespace DirectX;

struct CollisionSphere
{
	BoundingSphere sphere;
	ContainmentType collision;
};

namespace Constants
{
	const extern float k_ModelPositionModifier = 200 * 0.06f;
	XMGLOBALCONST XMVECTORF32 k_ColorDeepDarkGray = { { { 0.150000000f, 0.150000000f, 0.150000000f, 1.000000000f } } };
}