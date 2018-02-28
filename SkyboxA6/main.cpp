#include "LoopsAndStuff.h"

int main()
{
	LoopsAndStuff psychologicalGame;

	psychologicalGame.ReversePsychology();
	std::cout << std::endl;
	psychologicalGame.ReversePsychologyV2();
	std::cout << std::endl;
	psychologicalGame.ReversePsychologyV3();
	std::cout << std::endl;
	std::cout << "That's it! Thanks; see ya!" << std::endl;

	system("pause");
	return 0;
}

/*
	5. Switch statement has cases based on a single variable - each of these cases executes a code block if that case is true; and if-else if-else code block condition if usually 
	based off more than one variable. Switches can use more than one conditional, but the following conditional(s) would be specific to, and inside, the case code block.
	
	both will break out of checking conditionals once one is met, however, switches are preferable since they are much cleaner and less convoluted.
	if-else if-else are more specific and can be useful sometimes, but if there start too be many "if else" statements, then it's most likely better to use a switch.

	6. Answer is 27

	(1)Rabbit + Cat = 10
	(2)Rabbit + Dog = 20
	(3)Cat + Dog = 24

	(4) = (1)+(2) = 30

	(5) = (4)-(3) = 6 <-- this is 2 Rabbits
	(6) = (5)/2 = 3 <-- this is 1 Rabbit

	Rabbit = 3
	Cat = 10 - Rabbit = 7
	Dog = 20 - Rabbit = 17

	Cat + Dog + Rabbit = 27

*/