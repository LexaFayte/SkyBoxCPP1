#pragma once
#include <ctime>
#include <cstdlib>
#include <vector>
#include <sstream>

class Helper
{
public:
	enum Actions { HighKick, LowBlock, LowKick, HighBlock, none };

	static float RandomFloat(float min, float max)
	{
		float random = ((float)rand()) / (float)RAND_MAX;
		float diff = max - min;
		float r = random * diff;
		return min + r;
	}

	static std::string ParseAction(Actions action)
	{
		switch (action)
		{
			case Actions::HighBlock:
				return "HighBlock";
			case Actions::HighKick:
				return "HighKick";
			case Actions::LowBlock:
				return "LowBlock";
			case Actions::LowKick:
				return "LowKick";
			case Actions::none:
				return "none";
		}

		return  "";
	}
	
	static std::string BuildString(std::vector<std::string> strings, int formatOffset)
	{
		int formatIndex = formatOffset;
		int length = formatOffset;

		std::ostringstream ss;
		
		for (int i = 0; i < length; ++i)
		{
			if (strings[i] == "%s" || strings[i] == "%d")
			{
				//format
				ss << strings[formatIndex];
				formatIndex++;
				continue;
			}
			else
			{
				ss << strings[i];
			}

		}
		
		std::string toReturn = ss.str();
		return toReturn;
	}
};
