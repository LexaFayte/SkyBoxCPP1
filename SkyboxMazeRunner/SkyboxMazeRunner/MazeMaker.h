#pragma once
#include "pch.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <ctime>
#include "Entity.h"

class MazeMaker
{
private:
	size_t mSize = 0;
	int mWidth = 0;
	int mHeight = 0;
	DirectX::SimpleMath::Vector3 mStartingPosition = DirectX::SimpleMath::Vector3::Zero;
	DirectX::SimpleMath::Vector3 mEndPosition = DirectX::SimpleMath::Vector3::Zero;
	std::vector<std::vector<int>> mMaze;

	void InitDataStructure(int rows, int cols);
	void GenerateStartAndEnd();
	void GenerateMazeWalls();
	void Divide(int x, int y, int width, int height, bool horizontal);
	bool ChooseOrientation(int width, int height);
	void BuildMaze();

public:
	MazeMaker() { std::srand(time(0)); };
	~MazeMaker() {};

	const int getRows() const noexcept { return mHeight; };
	const int getCols() const noexcept { return mWidth; };
	std::vector<std::vector<int>>& getMaze() noexcept { return mMaze; };
	DirectX::SimpleMath::Vector3& getStartPosition() noexcept{ return mStartingPosition; }
	DirectX::SimpleMath::Vector3& getEndPosition() noexcept { return mEndPosition; }

	bool LoadMazeFromFile(std::string filename);
	void NewMaze(int mazeSize);
	void PrintMaze();
};
