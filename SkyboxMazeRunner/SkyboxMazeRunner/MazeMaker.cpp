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
				InitDataStructure(m_Height, m_Width);
			}
		}
		else
		{
			for (size_t i = 0; i < line.size(); ++i)
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

void MazeMaker::InitDataStructure(int rows, int cols)
{
	std::vector<std::vector<int>> maze(rows, std::vector<int>(cols, 0));
	m_Maze = maze;
}

void MazeMaker::GenerateMazeWalls()
{
	for (int i = 0; i < m_Size + 2; ++i)
	{
		m_Maze[0][i] = 1;
		m_Maze[m_Size + 1][i] = 1;
		m_Maze[i][0] = 1;
		m_Maze[i][m_Size + 1] = 1;
	}
}

void MazeMaker::Divide(int x, int y, int width, int height, bool horizontal)
{
	// check if this is the target size
	if (width < 2 || height < 2)
	{
		return;
	}

	int wallX, wallY, pathX, pathY, directionX, directionY, length;

	// Determine the start point of the wall
	wallX = x + (horizontal ? 0 : (std::rand()) % (width - 2));
	if (!horizontal && wallX % 2 != 0)
	{
		++wallX;
	}

	wallY = y + (horizontal ? (std::rand()) % (width - 2) : 0);
	if (horizontal && wallY % 2 != 0)
	{
		++wallY;
	}

	// Determine the position of the path through the wall
	pathX = wallX + (horizontal ? (std::rand()) % width : 0);
	if (horizontal && pathX % 2 == 0)
	{
		++pathX;
	}

	pathY = wallY + (horizontal ? 0 : (std::rand()) % height);
	if (!horizontal && pathY % 2 == 0)
	{
		++pathY;
	}

	// Determine the direction of the wall
	directionX = horizontal ? 1 : 0;
	directionY = horizontal ? 0 : 1;

	// Determine the length of the wall
	length = horizontal ? width : height;

	// Create the wall
	for (size_t i = 0; i < length; i++)
	{
		if (horizontal)
		{
			if (wallX != pathX)
			{
				m_Maze[wallY][wallX] = 1;
			}
		}
		else
		{
			if (wallY != pathY)
			{
				m_Maze[wallY][wallX] = 1;
			}
		}

		wallX += directionX;
		wallY += directionY;
	}

	//can print maze here

	int newX, newY, newWidth, newHeight;

	// Recurse on one side of the wall
	newX = x;
	newY = y;
	newWidth = horizontal ? width : wallX - x;
	newHeight = horizontal ? wallY - y : height;

	Divide(newX, newY, newWidth, newHeight, ChooseOrientation(newWidth, newHeight));

	// Recurse on the other side of the wall
	newX = horizontal ? x : wallX + 1;
	newY = horizontal ? wallY + 1 : y;
	newWidth = horizontal ? width : x + width - wallX - 1;
	newHeight = horizontal ? y + height - wallY - 1 : height;

	Divide(newX, newY, newWidth, newHeight, ChooseOrientation(newWidth, newHeight));
}

bool MazeMaker::ChooseOrientation(int width, int height)
{
	if (width < height)
	{
		return true;
	}
	else if (height < width)
	{
		return false;
	}
	else
	{
		return std::rand() % 2 == 0;
	}
}

void MazeMaker::BuildMaze()
{
	Divide(1, 1, m_Size, m_Size, ChooseOrientation(m_Size, m_Size));
	GenerateStartAndEnd();
}

void MazeMaker::GenerateStartAndEnd()
{
	int startWall = std::rand() % 4;
	int endWall = 0;
	bool horizontal = false;

	switch (startWall)
	{
	case 0:
		horizontal = false;
		break;

	case 1:
		horizontal = true;
		break;

	case 2:
		horizontal = false;
		break;

	case 4:
		horizontal = true;
	}

	startWall = 1;
	endWall = m_Size;

	// Place the start and end
	int randStartPos, randEndPos;

	if (horizontal)
	{
		do
		{
			randStartPos = std::rand() % m_Size;
		} while (m_Maze[startWall][randStartPos] == 1);

		do
		{
			randEndPos = std::rand() % m_Size;
		} while (m_Maze[endWall][randEndPos] == 1);

		m_StartingPosition.x = randStartPos;
		m_StartingPosition.z = startWall;
		m_Maze[m_StartingPosition.x][m_StartingPosition.z] = 2;

		m_EndPosition.x = randEndPos;
		m_EndPosition.z = endWall;
		m_Maze[m_EndPosition.x][m_EndPosition.z] = 3;
	}
	else
	{
		do
		{
			randStartPos = std::rand() % m_Size;
		} while (m_Maze[randStartPos][startWall] == 1);

		do
		{
			randEndPos = std::rand() % m_Size;
		} while (m_Maze[randEndPos][endWall] == 1);

		m_StartingPosition.x = randStartPos;
		m_StartingPosition.z = startWall;
		m_Maze[m_StartingPosition.x][m_StartingPosition.z] = 2;

		m_EndPosition.x = randEndPos;
		m_EndPosition.z = endWall;
		m_Maze[m_EndPosition.x][m_EndPosition.z] = 3;
	}
}

void MazeMaker::PrintMaze()
{
	for (int row = 0; row < m_Size + 2; ++row)
	{
		for (int col = 0; col < m_Size + 2; ++col)
		{
			std::cout << m_Maze[row][col] << " ";
		}
		std::cout << std::endl;
	}
}

void MazeMaker::NewMaze(int mazeSize)
{
	if (mazeSize % 2 == 0)
	{
		++mazeSize;
	}

	m_Size = mazeSize;
	m_Width = m_Size + 2;
	m_Height = m_Size + 2;

	InitDataStructure(m_Height, m_Width);
	GenerateMazeWalls();
	BuildMaze();
}