#pragma once
#include <exception>

class SlotterNameException : public std::exception
{
public:
	char const* what() const override
	{
		return "Name doesn't start with a vowel";
	}
};

class SlotterEvenLegNumberException : public std::exception
{
public:
	char const* what() const override
	{
		return "The number of legs is not odd";
	}
};

class SlotterLengthException : public std::exception
{
public:
	char const* what() const override
	{
		return "The length is greater than 0.1f or less than 0.001f";
	}
};