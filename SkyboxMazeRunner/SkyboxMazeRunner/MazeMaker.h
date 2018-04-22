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
	size_t m_Size = 0;
	int m_Width = 0;
	int m_Height = 0;
	DirectX::SimpleMath::Vector3 m_StartingPosition = DirectX::SimpleMath::Vector3::Zero;
	DirectX::SimpleMath::Vector3 m_EndPosition = DirectX::SimpleMath::Vector3::Zero;
	std::vector<std::vector<int>> m_Maze;

	void InitDataStructure(int rows, int cols);
	void GenerateStartAndEnd();
	void GenerateMazeWalls();
	void Divide(int x, int y, int width, int height, bool horizontal);
	bool ChooseOrientation(int width, int height);
	void BuildMaze();

public:
	MazeMaker() { std::srand(time(0)); };
	~MazeMaker() {};

	const int getRows() const noexcept { return m_Height; };
	const int getCols() const noexcept { return m_Width; };
	std::vector<std::vector<int>>& getMaze() noexcept { return m_Maze; };
	DirectX::SimpleMath::Vector3& getStartPosition() noexcept{ return m_StartingPosition; }
	DirectX::SimpleMath::Vector3& getEndPosition() noexcept { return m_EndPosition; }

	bool LoadMazeFromFile(std::string filename);
	void NewMaze(int mazeSize);
	void PrintMaze();
};
