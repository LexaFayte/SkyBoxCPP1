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
			if (mWidth == 0)
			{
				mWidth = atoi(line.c_str());//col
			}
			else
			{
				mHeight = atoi(line.c_str());//row
				dimensionsParsed = true;
				InitDataStructure(mHeight, mWidth);
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
					mMaze[rowCount][colCount] = 0;
					break;
				case 1:
					mMaze[rowCount][colCount] = 1;
					break;
				case 2:
					mMaze[rowCount][colCount] = 2;
					mStartingPosition = DirectX::SimpleMath::Vector3(rowCount, 0, colCount);//based on wall-width
					break;
				case 3:
					mMaze[rowCount][colCount] = 3;
					mEndPosition = DirectX::SimpleMath::Vector3(rowCount, 0, colCount);//based on wall-width
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
	mMaze = maze;
}

void MazeMaker::GenerateMazeWalls()
{
	for (int i = 0; i < mSize + 2; ++i)
	{
		mMaze[0][i] = 1;
		mMaze[mSize + 1][i] = 1;
		mMaze[i][0] = 1;
		mMaze[i][mSize + 1] = 1;
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
				mMaze[wallY][wallX] = 1;
			}
		}
		else
		{
			if (wallY != pathY)
			{
				mMaze[wallY][wallX] = 1;
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
	Divide(1, 1, mSize, mSize, ChooseOrientation(mSize, mSize));
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
	endWall = mSize;

	// Place the start and end
	int randStartPos, randEndPos;

	if (horizontal)
	{
		do
		{
			randStartPos = std::rand() % mSize;
		} while (mMaze[startWall][randStartPos] == 1);

		do
		{
			randEndPos = std::rand() % mSize;
		} while (mMaze[endWall][randEndPos] == 1);

		mStartingPosition.x = randStartPos;
		mStartingPosition.z = startWall;
		mMaze[mStartingPosition.x][mStartingPosition.z] = 2;

		mEndPosition.x = randEndPos;
		mEndPosition.z = endWall;
		mMaze[mEndPosition.x][mEndPosition.z] = 3;
	}
	else
	{
		do
		{
			randStartPos = std::rand() % mSize;
		} while (mMaze[randStartPos][startWall] == 1);

		do
		{
			randEndPos = std::rand() % mSize;
		} while (mMaze[randEndPos][endWall] == 1);

		mStartingPosition.x = randStartPos;
		mStartingPosition.z = startWall;
		mMaze[mStartingPosition.x][mStartingPosition.z] = 2;

		mEndPosition.x = randEndPos;
		mEndPosition.z = endWall;
		mMaze[mEndPosition.x][mEndPosition.z] = 3;
	}
}

void MazeMaker::PrintMaze()
{
	for (int row = 0; row < mSize + 2; ++row)
	{
		for (int col = 0; col < mSize + 2; ++col)
		{
			std::cout << mMaze[row][col] << " ";
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

	mSize = mazeSize;
	mWidth = mSize + 2;
	mHeight = mSize + 2;

	InitDataStructure(mHeight, mWidth);
	GenerateMazeWalls();
	BuildMaze();
}