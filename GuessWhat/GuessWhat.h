#pragma once
#include <iostream>
#include "SecretWord.h"

class GuessWhat
{
private:
	const int MAX_GUESSES = 5;
	const int WORD_LENGTH = 5;
	SecretWord mWordToGuess;
	std::string mUsersGuess;
	int mGuessesLeft = MAX_GUESSES;
	int mBulls = 0;
	int mCows = 0;
	bool mPlay = true;
	
	void printIntro();
	void reset();
	void checkPlayAgain();

public:
	GuessWhat();
	~GuessWhat();

	void run();
};