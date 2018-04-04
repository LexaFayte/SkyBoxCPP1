#pragma once

class Platyporse
{
public:
	Platyporse() {};
	Platyporse(float lengthOfBill) : mLengthOfBill(lengthOfBill) {};
	~Platyporse() {};

	const float GetLengthOfBill() const noexcept{ return mLengthOfBill; }
	friend bool operator<(const Platyporse& lhs, const Platyporse& rhs)
	{
		return lhs.mLengthOfBill < rhs.mLengthOfBill;
	}
private:
	float mLengthOfBill = 0.0f;
};


