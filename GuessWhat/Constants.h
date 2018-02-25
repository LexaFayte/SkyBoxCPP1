#pragma once
#include <string>

enum options {gameMode, difficulty};
const std::string introString = "WELCOME TO \"GUESS WHAT!\", THE WORD GUESSING GAME\n\n";
const std::string isoModeString = "GameMode: Isogram (repeating letters not allowed); ";
const std::string nonIsoModeString = "GameMode: Non-Isogram (repeating letters allowed); ";
const std::string difficultyEasyString = "Difficulty: Easy - 5 letters\n";
const std::string difficultyNormalString = "Difficulty: Normal - 7 letters\n";
const std::string difficultyHardString = "Difficulty: Hard - 10 letters\n";
