#include "pch.h"
#include "MazeMaker.h"

bool MazeMaker::LoadMazeFromFile(std::string filename)
{
	std::fstream inFile;
	std::string line;
	int current = -1;
	inFile.open(filename);
	if (!inFile)
	{
		std::cout << "unable to open file " << filename << std::endl;
		return false;
	}

	int rowCount = 0;
	int colCount = 0;
	bool dimensionsParsed = false;

	while (std::getline(inFile, line))
	{
		if (!dimensionsParsed)
		{
			if (m_Width == 0)
			{
				m_Width = atoi(line.c_str());//col
			}
			else
			{
				m_Height = atoi(line.c_str());//row
				dimensionsParsed = true;
				initDataStructure(m_Height, m_Width);
			}
		}
		else
		{
			for (int i = 0; i < line.size(); ++i)
			{
				current = line[i] - 48;
				switch (current)
				{
				case 0:
					m_Maze[rowCount][colCount] = 0;
					break;
				case 1:
					m_Maze[rowCount][colCount] = 1;
					//std::cout << " ";
					break;
				case 2:
					m_Maze[rowCount][colCount] = 2;
					m_StartingPosition = DirectX::SimpleMath::Vector3(rowCount, 0, colCount);//based on wall-width
					//std::cout << "S";
					break;
				case 3:
					m_Maze[rowCount][colCount] = 3;
					m_EndPosition = DirectX::SimpleMath::Vector3(rowCount, 0, colCount);//based on wall-width 
					//std::cout << "E"
					break;
				}

				if (dimensionsParsed)
				{
					++colCount;
				}
			}

			if (dimensionsParsed)
			{
				++rowCount;
				colCount = 0;
			}
		}
	}

	inFile.close();
}

void MazeMaker::initDataStructure(int rows, int cols)
{
	std::vector<std::vector<int>> maze(rows, std::vector<int>(cols, 0));
	m_Maze = maze;
}