#pragma once
#include <iostream>
#include "SecretWord.h"

class GuessWhat
{
private:
	int MAX_GUESSES = 5;
	int WORD_LENGTH = 5;
	SecretWord mWordToGuess;
	std::string mUsersGuess;
	int mGuessesLeft = MAX_GUESSES;
	int mBulls = 0;
	int mCows = 0;
	int mDifficulty = 0;
	bool mPlay = true;
	bool mIsoMode = true;
	bool mWin = false;
	
	bool checkValidGuess();
	void printModeAndDifficulty();


public:
	GuessWhat();
	~GuessWhat();

	void run();
	void setModeAndDifficulty(int &mode, int &difficulty);
	void reset();

	const bool& getWin() const;
};