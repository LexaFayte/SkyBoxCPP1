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
	float GetRadius() const { return mRadius; }

	float GetVolume() override { return 4.0f * mPie * mRadius * mRadius * mRadius / 3.0f; }
	float GetSurfaceArea() override { return 4.0f * mPie * mRadius * mRadius; }

	void Print() override;

private:
	float mRadius;
	const float mPie;
};

#endif // #ifndef SPHERE_H