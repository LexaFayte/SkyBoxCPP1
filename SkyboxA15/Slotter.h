#pragma once
#include <string>	
#include "SlotterExceptions.h"
class Slotter
{
public:
	Slotter() {};
	~Slotter() {};

	const std::string& GetName() const noexcept { return mName; };
	const int GetNumLegs() const noexcept { return mNumLegs; };
	const float GetLength() const noexcept { return mLength; };

	void SetName(std::string& name);
	void SetNumLegs(int numLegs);
	void SetLength(float length);


private:
	std::string mName = "";
	int mNumLegs = 0;
	float mLength = 0;
};