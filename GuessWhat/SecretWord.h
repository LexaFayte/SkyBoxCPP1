#pragma once
#include <string>
#include <array>
#include <vector>
#include <ctime>
#include <cstdlib>

class SecretWord
{
private:
	const int MAX_WORDS = 10;

	std::array<std::string, 10> mFiveLetterWordsIso{ "quake","super","crime","laser","virus","shift","trade","storm","canid","lucky" };
	std::array<std::string, 10> mFiveLetterWords{ "apple","error","order","paper","legal","elite","coach","aware","river","sense" };

	std::array<std::string, 10> mSevenLetterWordsIso{ "abolish","decrypt","warship","whistle","sandbox","fighter","network","ketchup","padlock","latency" };
	std::array<std::string, 10> mSevenLetterWords{ "attempt","context","outlook","primary","warrant","tonight","realize","program","minimal","premium" };

	std::array<std::string, 10> mTenLetterWordsIso{ "pathfinder","aftershock","formidable","trampoline","subjection","blacksmith","downstream","timberland","shoplifter","slumbering" };
	std::array<std::string, 10> mTenLetterWords{ "additional","compassion","monolithic","leadership","rendezvous","heartbreak","wavelength","earthquake","particular","waterproof" };
	
	std::string mWord = "";

	std::string makeCowsString(const std::vector<int> &indecies, std::string &word) const;
	std::string makeNonBullString(const std::vector<int> &indecies, std::string &word) const;
public:
	SecretWord();
	~SecretWord();

	void checkLikeness(std::string &userGuess, int &bulls, int &cows);
	
	void checkLikenessNonIso(std::string &userGuess, int &bulls, int &cows);
	void checkCows(std::string &cowsLeft, std::string &guessCows, int& GuessIndex, int &cows);

	const std::string& getCurrentWord();

	void setWord(bool& iso, int &difficulty);
};