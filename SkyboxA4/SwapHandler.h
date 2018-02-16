#pragma once
#include <string>
class SwapHandler
{
public:
	SwapHandler();
	~SwapHandler();

	void run();

private:
	void swap(int &a, int &b);


	void swap(bool &a, bool &b);

	void swap(std::string &a, std::string &b);
};