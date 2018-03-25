#pragma once
#include <utility>
#include <iostream>
class Cash
{
private:
	int mDollars = 0;
	int mCents = 0;
	const int CENTS_IN_DOLLAR = 100;

	void SimplifyCash();

public:
	Cash(int dollars, int cents);

	~Cash() {};

	Cash(const Cash& other);
	Cash(Cash &&other) noexcept;

	Cash& operator=(const Cash& other);
	Cash& operator=(Cash&& other) noexcept;

	Cash& operator++()//prefix
	{
		++mDollars;
		return *this;
	}

	Cash operator++(int)//postfix
	{
		Cash result(*this);
		++result.mCents;
		result.SimplifyCash();
		return result;
	}

	Cash& operator--()//prefix
	{
		--mDollars;
		return *this;
	}

	Cash operator--(int)//postfix
	{
		Cash result(*this);
		--result.mCents;
		result.SimplifyCash();
		return result;
	}

	Cash& operator+=(const Cash& rhs)
	{
		mDollars += rhs.mDollars;
		mCents += rhs.mCents;
		SimplifyCash();
		return *this;
	}

	friend Cash operator+(Cash lhs, const Cash& rhs)
	{
		lhs += rhs;
		return lhs;
	}

	friend Cash operator+(const Cash& lhs, Cash rhs)
	{
		rhs += lhs;
		return rhs;
	}

	Cash& operator-=(const Cash& rhs)
	{
		mDollars -= rhs.mDollars;
		mCents -= rhs.mCents;
		SimplifyCash();
		return *this;
	}

	friend Cash operator-(Cash lhs, const Cash& rhs)
	{
		lhs -= rhs;
		return lhs;
	}

	friend Cash operator-(const Cash& lhs, Cash rhs)
	{
		rhs -= lhs;
		return rhs;
	}

	Cash& operator*=(const int& rhs)
	{
		mDollars *= rhs;
		mCents *= rhs;
		SimplifyCash();
		return *this;
	}

	friend Cash operator*(Cash lhs, const int& rhs)
	{
		lhs *= rhs;
		return lhs;
	}

	friend Cash operator*(const int& lhs , Cash rhs)
	{
		rhs *= lhs;
		return rhs;
	}

	inline bool operator==(const Cash& other)
	{
		return mDollars == other.mDollars && mCents == other.mCents;
	}

	inline bool operator<(const Cash& other)
	{
		return mDollars <= other.mDollars && mCents < other.mCents;
	}

	bool operator<=(const Cash& other)
	{
		if (*this == other)
		{
			return true;
		}
		return *this < other;
	}
	
	inline bool operator>(const Cash& other)
	{
		return !(*this < other);
	}


	bool operator>=(const Cash& other)
	{
		if (*this == other)
		{
			return true;
		}
		return *this > other;
	}

	inline bool operator != (const Cash& other)
	{
		return !(*this == other);
	}

	friend std::ostream& operator<<(std::ostream& outs, const Cash& c)
	{
		outs << "$" << c.mDollars << "." << c.mCents << std::endl;
		return outs;
	}
};