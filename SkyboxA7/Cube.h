#ifndef CUBE_H
#define CUBES_H

#include <string>

#include "ThreeDimensional.h"

class Cube : public ThreeDimensional
{
public:
	Cube(std::string name, float width, float height, float depth);
	~Cube();

	void SetWidth(float width);
	void SetHeight(float height);
	void SetDepth(float depth);

	const float& GetWidth() const noexcept { return mWidth; }
	const float& GetHeight() const noexcept { return mHeight; }
	const float& GetDepth() const noexcept { return mDepth; }

	float GetVolume() override { return std::powf(mHeight,3); }
	float GetSurfaceArea() override { return 6.0f * std::powf(mHeight,2); }

	void Print() override;

private:
	float mWidth;
	float mHeight;
	float mDepth;
};

#endif // #ifndef CUBE_H