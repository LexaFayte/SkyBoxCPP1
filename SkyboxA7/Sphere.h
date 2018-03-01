#ifndef SPHERE_H
#define SPHERE_H

#include <string>

#include "ThreeDimensional.h"

class Sphere : public ThreeDimensional
{
public:
	Sphere(const std::string& name, float radius);
	~Sphere();

	void SetRadius(float radius);
	const float& GetRadius() const noexcept { return mRadius; }

	float GetVolume() override { return 4.0f * mPie * ((std::powf(mRadius, 3)) / 3.0f); }
	float GetSurfaceArea() override { return 4.0f * mPie * (std::powf(mRadius,2)); }

	void Print() override;

private:
	float mRadius;
	const float mPie;
};

#endif // #ifndef SPHERE_H