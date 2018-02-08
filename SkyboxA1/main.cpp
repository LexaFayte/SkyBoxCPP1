#include <iostream>
#include <vector>
int UserInteger();
int MultiplyInts(const std::vector<int> &nums);
int AddInts(const std::vector<int> &nums);

int main()
{
	std::vector<int> UsersNumbers;
	for (int i = 0; i < 3; ++i)
	{
		UsersNumbers.push_back(UserInteger());
		std::cout << "You entered the number: " << UsersNumbers[i] << std::endl;
	}

	int Number = MultiplyInts(UsersNumbers);
	std::cout << "Your numbers multiplied together: " << Number << std::endl;

	Number = AddInts(UsersNumbers);
	std::cout << "Your numbers added together: " << Number << std::endl;

	system("pause");

	return 0;
}

int UserInteger()
{
	int input;
	std::cout << "please enter an integer: ";
	std::cin >> input;

	return input;
}

int MultiplyInts(const std::vector<int> &nums)
{
	int result = 1;
	for (auto it = nums.begin(); it != nums.end(); it++)
	{
		result *= *it;
	}
	return result;
}

int AddInts(const std::vector<int> &nums)
{
	int result = 0;
	for (auto it = nums.begin(); it != nums.end(); it++)
	{
		result += *it;
	}
	return result;
}

/*
	5. you can write comments using two forward slashes ex. //
	these are only single line comments however

	you can also write comments using two slahses and two asterisks, such as how this answer is written; this is a comment block
	comment blocks allow for comments to span multiple lines.
	
	I believe a comment block is a better way to comment if the comment needs to be long; quick one-line comments can be written in this way as well.
	Single line comments are limited.

	
	6. self commenting code means to write code that is clear i.e. code that doesn't need a lot of extra documentation; that when another person looks at it they will be able to understand
	what the piece of code is doing.
	This can be achieved by having meaningful variable names, as well as keeping code clean and organized.
	It doesn't mean that there won't be any other comments or documentation, but it will reduce the amount of comments in code where they shouldn't be necessary.

	
	7. a string is a class which contains a string literal;
	a string literal is only an array of chars that make up the string plus the null terminating character.

	
	8.the main() function is the entry point for a program, changing the signature by using CamelCase would make the program have no entry point, and would not compile.

	
	9.the std namespace contains cout, cin, and string; these are accessed by using the scope resolution operator ::
	std::cout << "Foo";

	
	10.the #include preprocessor directive searches for the file specified and pastes the contents into the current file

	
	11.the danger of using the statement: using namespace std; is there could be clashing if the std namespace contains a function with the same signature as some other namespace
	that has been included, or another function withing the file or class that has the same signature; it will be an ambiguous call and the code will fail to compile.

	
	12.psuedo code is half-code, half-plain english; it's used to give a simple (high-level) overview while planning/outlining how some code will function or be written.
*/