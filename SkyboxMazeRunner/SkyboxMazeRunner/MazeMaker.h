#pragma once
#include "pch.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "Entity.h"

class MazeMaker
{
public:
	MazeMaker() {};
	~MazeMaker() {};

	const int getRows() const noexcept { return m_Height; };
	const int getCols() const noexcept { return m_Width; };
	std::vector<std::vector<int>>& getMaze() noexcept { return m_Maze; };
	DirectX::SimpleMath::Vector3& getStartPosition() noexcept{ return m_StartingPosition; }
	DirectX::SimpleMath::Vector3& getEndPosition() noexcept { return m_EndPosition; }

	bool LoadMazeFromFile(std::string filename);

private:
	int m_Width = 0;
	int m_Height = 0;
	DirectX::SimpleMath::Vector3 m_StartingPosition = DirectX::SimpleMath::Vector3::Zero;
	DirectX::SimpleMath::Vector3 m_EndPosition = DirectX::SimpleMath::Vector3::Zero;
	std::vector<std::vector<int>> m_Maze;

	void initDataStructure(int rows, int cols);
};
