#pragma once
#include <string>
#include <array>

#define NUM_VOWELS 6

class Helper
{
public:
	static bool CheckVowel(char c)
	{
		if (std::find(vowels.begin(), vowels.end(), c) != vowels.end())
		{
			return true;
		}
		return false;
	}

private:
	static std::array<char, NUM_VOWELS> vowels;
};
