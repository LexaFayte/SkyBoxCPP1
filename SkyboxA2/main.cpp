#include <iostream>
#include <bitset>
#include <string>

void ForLoop(int start, int end);
void DoWhile(int start);
void WhileLoop(int start);

int main()
{
	const int start = 0;
	const int end = 50;
	std::cout << "==================>>>> FOR LOOP FUNCTION <<<<==================" << std::endl;
	ForLoop(start, end);
	std::cout << "\n==================>>>> DO WHILE FUNCTION <<<<==================" << std::endl;
	DoWhile(start);
	std::cout << "\n==================>>>> WHILE LOOP FUNCTION <<<<==================" << std::endl;
	WhileLoop(start);

	{
		std::cout << "\n==================>>>> INT IN MEMORY <<<<==================" << std::endl;
		int memoryViewInteger = 504530;
		const size_t sizeOfIntInBits = sizeof(int) * 8;
		std::cout << "\nthe number 504,530 represented in binary (bits): ";
		std::cout << std::bitset<sizeOfIntInBits>(memoryViewInteger).to_string() << std::endl;
	}

	{
		std::cout << "\n==================>>>> STRING IN MEMORY <<<<==================\n" << std::endl;
		std::string ThereIsNoSpoon = "There is no spoon!";
		for (size_t i = 0; i < ThereIsNoSpoon.size(); ++i)
		{
			const size_t charSize = sizeof(ThereIsNoSpoon[i]) * 8;
			std::cout << "\'" << ThereIsNoSpoon[i] << "\'" << " - " << (int)ThereIsNoSpoon[i] << " - " << std::bitset<charSize>(ThereIsNoSpoon[i]).to_string() << std::endl;
		}
	}

	system("pause");
	return 0;
}


void ForLoop(int start, int end)
{
	for (size_t i = start; i < end + 1; ++i)
	{
		std::cout << i << std::endl;
	}
}

void DoWhile(int start)
{
	bool UserContinue = 0;
	int number = start;
	do
	{
		std::cout << number << std::endl;
		std::cout << "print the next number? Enter 1 for yes, 0 for no: ";
		std::cin >> UserContinue;
		++number;
	} while (UserContinue);
}

void WhileLoop(int start)
{
	int number = start;
	bool UserContinue = 0;
	std::cout << "print a number? Enter 1 for yes, 0 for no: ";
	std::cin >> UserContinue;

	while (UserContinue)
	{
		std::cout << number << std::endl;
		std::cout << "print the next number? Enter 1 for yes, 0 for no: ";
		std::cin >> UserContinue;
		++number;
	}
}