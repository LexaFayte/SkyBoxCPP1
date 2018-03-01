#ifndef CUBE_H
#define CUBES_H

#include <string>

#include "ThreeDimensional.h"

class Cube : public ThreeDimensional
{
public:
	Cube(std::string name, float sideLength);
	~Cube();

	void SetSideLength(float sideLength);

	const float& GetSideLength() const noexcept { return mSideLength; }

	float GetVolume() override { return std::powf(mSideLength,3); }
	float GetSurfaceArea() override { return 6.0f * std::powf(mSideLength,2); }

	void Print() override;

private:
	float mSideLength;
	float mVolume = 0;
	float mSurfaceArea = 0;
};

#endif // #ifndef CUBE_H