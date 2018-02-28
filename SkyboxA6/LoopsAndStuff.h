#pragma once
#include <iostream>
#include <string>

class LoopsAndStuff
{
private:
	const int THE_NUMBER = 5;
	const int MAX_TRIES = 10;
	const std::string REPRIMAND = "HEY! WHY DID YOU ENTER 5!? YOU AREN'T SUPPOSED TO!";
	const std::string REPRIMAND_V2 = "YOU HAD ONE JOB!";
	const std::string WIN_V1 = "Congratulations! you did not give in and type 5; you have a will of steel";
	const std::string WIN_V2 = "You did it! You made it to the end! What did you do? Who knows! :D";
public:
	LoopsAndStuff() {};
	~LoopsAndStuff() {};

	void ReversePsychology();
	void ReversePsychologyV2();
	void ReversePsychologyV3();
};
