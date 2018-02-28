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

	float GetVolume() override { return 10.0f; }
	float GetSurfaceArea() override { return (2.0f * mWidth * mHeight) + (2.0f * mHeight * mDepth) + (2.0f * mWidth * mDepth); }

	void Print() override;

private:
	float mWidth;
	float mHeight;
	float mDepth;
};

#endif // #ifndef CUBE_H