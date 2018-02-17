#pragma once
#include <string>
#include <array>
#include <vector>
#include <ctime>
#include <cstdlib>

class SecretWord
{
private:
	std::array<std::string, 10> mFiveLetterWords{ "quake","array","crime","error","virus","mouse","trade","storm","river","lucky" };
	std::string mWord = "";

	std::string makeCowsString(const std::vector<int> &indecies) const;
public:
	SecretWord();
	~SecretWord();

	void checkLikeness(std::string &userGuess, int &bulls, int &cows);
	const std::string& getCurrentWord();
	void newWord();
};