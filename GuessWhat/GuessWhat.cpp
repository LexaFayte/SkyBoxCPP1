#include "GuessWhat.h"
#include "Constants.h"
#include <iostream>
#include <stdlib.h>

GuessWhat::GuessWhat() {};
GuessWhat::~GuessWhat() {};


void GuessWhat::run()
{
	printModeAndDifficulty();

	while (mGuessesLeft >= 1)
	{
		mCows = 0;
		mBulls = 0;
		std::cout << "guesses left: " << mGuessesLeft << "\n" << std::endl;
		std::cout << "please enter your guess: " << std::endl;
		std::cin >> mUsersGuess;

		if (mUsersGuess == "quit")
		{
			break;
		}

		bool isValid = checkValidGuess();
		if (!isValid)
		{
			std::cout << "try again" << std::endl;
			continue;
		}

		if (mIsoMode)
		{
			mWordToGuess.checkLikeness(mUsersGuess, mBulls, mCows);
		}
		else
		{
			mWordToGuess.checkLikenessNonIso(mUsersGuess, mBulls, mCows);
		}

		if (mBulls == WORD_LENGTH)
		{
			std::cout << "you guessed the word!\n" << std::endl;
			mWin = true;
			break;
		}
		else if (mGuessesLeft <= 1)
		{
			std::cout << "you ran out of guesses!\nthe word was " << mWordToGuess.getCurrentWord() << std::endl;
			mWin = false;
			break;
		}
		else
		{
			std::cout << std::endl;
			std::cout << "letters in the correct spot: " << mBulls << std::endl;
			std::cout << "letters in the wrong spot:" << mCows << std::endl;
			--mGuessesLeft;
		}
	}
}

void GuessWhat::reset()
{
	mWordToGuess.setWord(mIsoMode, mDifficulty);
	mGuessesLeft = MAX_GUESSES;
	system("cls");
}

bool GuessWhat::checkValidGuess()
{
	if (mUsersGuess.size() != WORD_LENGTH)
	{
		std::cout << "\ninvalid input; the word must be " << WORD_LENGTH << " letters long\n" << std::endl;
		return false;
	}

	std::transform(mUsersGuess.begin(), mUsersGuess.end(), mUsersGuess.begin(), ::tolower);

	if (mIsoMode)
	{
		int halfLength = ::ceil((float)WORD_LENGTH / 2);

		for (int i = 0; i < halfLength; ++i)
		{
			for (int j = i + 1; j < WORD_LENGTH; ++j)
			{
				if (mUsersGuess[i] == mUsersGuess[j])
				{
					std::cout << "\ninvalid input; the word must be an isogram (no reapeating letters)\n" << std::endl;
					return false;
				}
			}
		}
	}

	return true;
}

void GuessWhat::setModeAndDifficulty(int &mode, int &difficulty)
{
	switch (mode)
	{
	case 1:
		mIsoMode = true;
		break;
	case 2:
		mIsoMode = false;
		break;
	default:
		break;
	}

	mDifficulty = difficulty;
	switch (difficulty)
	{
	case 1:
		MAX_GUESSES = 5;
		WORD_LENGTH = 5;
		break;
	case 2:
		MAX_GUESSES = 7;
		WORD_LENGTH = 7;
		break;
	case 3:
		MAX_GUESSES = 10;
		WORD_LENGTH = 10;
		break;
	default:
		break;
	}

	mWordToGuess.setWord(mIsoMode, mDifficulty);
	mGuessesLeft = MAX_GUESSES;
	//std::cout << mWordToGuess.getCurrentWord() << std::endl;
}

const bool& GuessWhat::getWin() const
{
	return mWin;
}

void GuessWhat::printModeAndDifficulty()
{
	if (mIsoMode)
	{
		std::cout << isoModeString;
	}
	else
	{
		std::cout << nonIsoModeString;
	}

	switch (mDifficulty)
	{
	case 1:
		std::cout << difficultyEasyString << std::endl;
		break;
	case 2:
		std::cout << difficultyNormalString << std::endl;
		break;
	case 3:
		std::cout << difficultyHardString << std::endl;
		break;
	}
}