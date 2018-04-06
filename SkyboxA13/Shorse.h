#pragma once

class Shorse
{
public:
	Shorse() {};
	Shorse(int numTeeth) : mNumTeeth(numTeeth) {};
	~Shorse() {};

	const int GetNumberOfTeeth() const noexcept { return mNumTeeth; }

	friend bool operator<(const Shorse& lhs, const Shorse& rhs)
	{
		return lhs.mNumTeeth < rhs.mNumTeeth;
	}
private:
	int mNumTeeth = 0;
};
