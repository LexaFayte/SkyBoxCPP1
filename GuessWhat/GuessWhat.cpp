#include "GuessWhat.h"
#include <iostream>

GuessWhat::GuessWhat() {};

GuessWhat::~GuessWhat() {};


void GuessWhat::run()
{
	while (mPlay)
	{
		printIntro();
		
		while (mGuessesLeft >= 1)
		{
			mCows = 0;
			mBulls = 0;
			std::cout << "guesses left: " << mGuessesLeft << std::endl;
			std::cout << "please enter your guess: " << std::endl;
			std::cin >> mUsersGuess;

			mWordToGuess.checkLikeness(mUsersGuess, mBulls, mCows);

			if (mBulls == WORD_LENGTH)
			{
				std::cout << "you guessed the word!" << std::endl;
				checkPlayAgain();
				break;
			}
			else if (mGuessesLeft <= 1)
			{
				std::cout << "you ran out of guesses!\nthe word was " << mWordToGuess.getCurrentWord() << std::endl;
				checkPlayAgain();
				break;
			}
			else
			{
				std::cout << "letters in the correct spot: " << mBulls << std::endl;
				std::cout << "letters in the wrong spot:" << mCows << std::endl;
				--mGuessesLeft;
			}
		}
	}
}

void GuessWhat::printIntro()
{
	std::cout << "WELCOME TO \"GUESS WHAT!\", THE WORD GUESSING GAME\n\n" << std::endl;
}

void GuessWhat::reset()
{
	mWordToGuess.newWord();
	mGuessesLeft = MAX_GUESSES;
	system("cls");
}

void GuessWhat::checkPlayAgain()
{
	std::string playAgain;
	std::cout << "would you like to play again? y/n: " << std::endl;
	std::cin >> playAgain;

	std::transform(playAgain.begin(), playAgain.end(), playAgain.begin(), ::tolower);

	if (playAgain == "y")
	{
		mPlay = true;
		reset();
	}
	else
	{
		mPlay = false;
	}
}



