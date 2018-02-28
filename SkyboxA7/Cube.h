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

	float GetWidth() { return mWidth; }
	float GetHeight() { return mHeight; }
	float GetDepth() { return mDepth; }

	float GetVolume() override { return std::powf(mHeight,3); }
	float GetSurfaceArea() override { return 6.0f * std::powf(mHeight,2); }

	void Print() override;

private:
	float mWidth;
	float mHeight;
	float mDepth;
};

#endif // #ifndef CUBE_H