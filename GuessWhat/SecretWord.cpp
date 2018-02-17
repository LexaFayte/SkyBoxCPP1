#include "SecretWord.h"

SecretWord::SecretWord()
{
	srand(time(0));
	mWord = mFiveLetterWords[(rand() % mFiveLetterWords.size()) + 1];
};

SecretWord::~SecretWord() {};

void SecretWord::checkLikeness(std::string &userGuess, int &bulls, int &cows)
{
	std::vector<int> nonBullIndecies;

	for (auto itGuess = userGuess.begin(), itWord = mWord.begin(); itWord < mWord.end(); ++itWord, ++itGuess)
	{
		if (*itWord == *itGuess)
		{
			bulls++;
		}
		else
		{
			nonBullIndecies.push_back(std::distance(mWord.begin(), itWord));
		}
	}

	if (nonBullIndecies.size() > 0)
	{
		std::string cowString = makeCowsString(nonBullIndecies);
		for (int i = 0; i < nonBullIndecies.size(); i++)
		{
			if (cowString.find(userGuess[nonBullIndecies[i]]) != std::string::npos)
			{
				cows++;
			}
		}
	}
}

std::string SecretWord::makeCowsString(const std::vector<int> &indecies) const
{
	std::string toReturn(indecies.size(),'e');
	for(int i = 0; i < indecies.size(); ++i)
	{
		toReturn[i] = mWord[indecies[i]];
	}

	return toReturn;
}

void SecretWord::newWord()
{
	srand(time(0));
	mWord = mFiveLetterWords[(rand() % mFiveLetterWords.size()) + 1];
}

const std::string& SecretWord::getCurrentWord()
{
	return mWord;
}