#include <string>

#include"TwoDimensional.h"

class Rectangle : public TwoDimensional
{
public:
	Rectangle(std::string name, float width, float height);
	~Rectangle();

	void SetWidth(float width);
	void SetHeight(float height);

	float GetWidth() { return mWidth; }
	float GetHeight() { return mHeight; }

	virtual float GetAreas() { return mWidth * mHeight; }
	virtual float GetPerimeters() { return (mWidth * 2.0f) + (mHeight * 2.0f); }

	void Print() override;

private:
	float mWidth;
	float mHeight;
};