#include "SecretWord.h"

SecretWord::SecretWord() { srand(time(0)); };
SecretWord::~SecretWord() {};

void SecretWord::checkLikeness(std::string &userGuess, int &bulls, int &cows)
{
	for (auto itGuess = userGuess.begin(), itWord = mWord.begin(); itWord < mWord.end(); ++itWord, ++itGuess)
	{
		if (*itWord == *itGuess)
		{
			bulls++;
		}
		else if (mWord.find(*itGuess, 0) != std::string::npos)
		{
			cows++;
		}
	}
}

std::string SecretWord::makeCowsString(const std::vector<int> &indecies, std::string &word) const
{
	std::string toReturn(indecies.size(), 'e');
	for (int i = 0; i < indecies.size(); ++i)
	{
		toReturn[i] = word[indecies[i]];
	}

	return toReturn;
}

std::string SecretWord::makeNonBullString(const std::vector<int> &indecies, std::string &word) const
{
	std::string toReturn = word;
	int erasedOffset = 0;
	for (int i = 0; i < indecies.size(); ++i)
	{
		toReturn.erase(toReturn.begin() + (indecies[i] - erasedOffset));
		erasedOffset++;
	}

	return toReturn;
}

const std::string& SecretWord::getCurrentWord()
{
	return mWord;
}

void SecretWord::checkLikenessNonIso(std::string &userGuess, int &bulls, int &cows)
{
	std::vector<int> possibleCowIndecies;
	possibleCowIndecies.reserve(mWord.size());
	std::vector<int> bullIndecies;
	bullIndecies.reserve(mWord.size());
	for (auto itGuess = userGuess.begin(), itWord = mWord.begin(); itWord < mWord.end(); ++itWord, ++itGuess)
	{
		if (*itWord == *itGuess)
		{
			bulls++;
			bullIndecies.push_back(std::distance(mWord.begin(), itWord));
		}
		else if (mWord.find(*itGuess, 0) != std::string::npos)
		{
			possibleCowIndecies.push_back(std::distance(mWord.begin(), itWord));
		}
	}

	if (possibleCowIndecies.size() > 0)
	{
		std::string wordNonBullString = makeNonBullString(bullIndecies, mWord);
		std::string guessCowsString = makeCowsString(possibleCowIndecies, userGuess);
		int guessIndex = 0;
		checkCows(wordNonBullString, guessCowsString, guessIndex, cows);
	}
}

void SecretWord::checkCows(std::string &cowsLeft, std::string &guessCows, int &GuessIndex, int &cows)
{
	if (GuessIndex >= guessCows.size())
	{
		return;
	}

	int cowIndex = -1;
	for (int i = 0; i < cowsLeft.size(); ++i)
	{
		if (guessCows[GuessIndex] == cowsLeft[i])
		{
			cows++;
			cowIndex = i;
			break;
		}
	}

	GuessIndex++;

	if (cowIndex > -1)
	{
		cowsLeft.erase(cowsLeft.begin() + cowIndex);
	}

	checkCows(cowsLeft, guessCows, GuessIndex, cows);

}

void SecretWord::setWord(bool& iso, int &difficulty)
{
	switch (difficulty)
	{
	case 1:
		if (iso)
		{
			mWord = mFiveLetterWordsIso[(rand() % MAX_WORDS)];
		}
		else
		{
			mWord = mFiveLetterWords[(rand() % MAX_WORDS)];
		}
		break;
	case 2:
		if (iso)
		{
			mWord = mSevenLetterWordsIso[(rand() % MAX_WORDS)];
		}
		else
		{
			mWord = mSevenLetterWords[(rand() % MAX_WORDS)];
		}
		break;
	case 3:
		if (iso)
		{
			mWord = mTenLetterWordsIso[(rand() % MAX_WORDS)];
		}
		else
		{
			mWord = mTenLetterWords[(rand() % MAX_WORDS)];
		}
		break;

	default:
		break;
	}

}