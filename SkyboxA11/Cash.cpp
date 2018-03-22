#include "Cash.h"

Cash::Cash(int dollars, int cents) : mDollars(dollars), mCents(cents)
{
	SimplifyCash();
}

Cash::Cash(const Cash& other) : mDollars(other.mDollars), mCents(other.mCents)
{

}

Cash::Cash(Cash&& other) noexcept : 
	mDollars{ std::exchange(other.mDollars,0) }, 
	mCents{ std::exchange(other.mCents,0) }
{
}

Cash& Cash::operator=(const Cash& other)
{
	if (this != &other)
	{
		mDollars = other.mDollars;
		mCents = other.mCents;
	}

	return *this;
}

Cash& Cash::operator=(Cash&& other) noexcept
{
	if (this != &other)
	{
		mDollars = std::exchange(other.mDollars, 0);
		mCents = std::exchange(other.mCents, 0);
	}

	return *this;
}

void Cash::SimplifyCash()
{
	if (mCents >= CENTS_IN_DOLLAR)
	{
		while (mCents >= CENTS_IN_DOLLAR)
		{
			++mDollars;
			mCents -= 100;
		}
	}

	if (mCents < 0)
	{
		while (mCents < CENTS_IN_DOLLAR)
		{
			mCents = 100 + mCents;
			--mDollars;
		}
	}
}