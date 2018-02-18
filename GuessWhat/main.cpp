#include "GuessWhat.h"
#include "Constants.h"

bool checkValidInput(int &input, const options &optionType);
void printIntro();
void selectGameMode(int &gameMode);
void selectDifficulty(int &difficulty);
void checkPlayAgain(bool &play);

int main()
{
	printIntro();
	bool play = true;
	int gameMode = 0;
	int difficulty = 0;
	GuessWhat game;

	while (play)
	{
		selectGameMode(gameMode);
		system("cls");

		selectDifficulty(difficulty);
		system("cls");

		game.setModeAndDifficulty(gameMode, difficulty);
		game.run();

		checkPlayAgain(play);
	}
	

	std::cout << "\nThanks for playing!\n" << std::endl;
	system("pause");
	
	return 0;
}

bool checkValidInput(int &input, const options &optionType)
{
	switch (input)
	{
		case 1:
			return true;
			break;
		case 2:
			return true;
			break;
		case 3:
			if (optionType == options::difficulty)
			{
				return true;
			}
			return false;
		default:
			std::cout << "input: " << input << " not a valid option\n\n" << std::endl;
			return false;
	}
}

void printIntro()
{
	std::cout << introString << std::endl;
}

void selectGameMode(int &gameMode)
{
	std::cout << "chose a game mode: " << std::endl;
	std::cout << "1 - Isogram words only (word cannot have repeating letters)" << std::endl;
	std::cout << "2 - Non-Isogram words (word can have repeating letters)" << std::endl;

	std::cin >> gameMode;

	while (!checkValidInput(gameMode, options::gameMode))
	{
		std::cin >> gameMode;
	}
}

void selectDifficulty(int &difficulty)
{
	std::cout << "chose a difficulty: " << std::endl;
	std::cout << "1 - easy (5 letter words)" << std::endl;
	std::cout << "2 - normal (7 letter words)" << std::endl;
	std::cout << "3 - hard (10 letter words)" << std::endl;

	std::cin >> difficulty;

	while (!checkValidInput(difficulty, options::difficulty))
	{
		std::cin >> difficulty;
	}
}

void checkPlayAgain(bool &play)
{
	std::string playAgain;
	std::cout << "\nwould you like to play again? y/n: " << std::endl;
	std::cin >> playAgain;

	std::transform(playAgain.begin(), playAgain.end(), playAgain.begin(), ::tolower);

	if (playAgain == "y")
	{
		play = true;
	}
	else
	{
		play = false;
	}

	system("cls");
}