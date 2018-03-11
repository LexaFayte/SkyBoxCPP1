#pragma once
#include <ctime>
#include <cstdlib>
#include <string>
#include <windows.h>
#include "Player.h"
#include "Enemy.h"
#include "Helper.h"

class Game
{
private:
	bool mGameOver = false;
	bool mPlayerWin = false;
	Player player;
	Enemy enemy;
	const float DISPLAY_UPDATE_DELAY = 0.5f;
	float timer = -1;
	bool mUpdateStrings = true;

	const int ACTION_STRINGS_OFFSET = 5;
	const int HEALTH_STRINGS_OFFSET = 5;
	const int PLAYER_WIN_OFFSET = 0.0f;

	Helper::Actions playerAction = Helper::Actions::none;

	std::vector<std::string> mActionStrings{ "Player: ", "%s", " | ", "AI: ", "%s", "none", "none"};
	std::vector<std::string> mHealthStrings{ "Health: ", "%d"," | ", "Heath: ", "%d", "100", "100"};

	void UpdateStrings();

public:
	Game()
	{ 
		srand(time(0)); 
		UpdateStrings();
	}
	~Game() {}

	void Update(float deltaTime);
	void SetPlayerAction(const Helper::Actions action);
	bool GetUpdateStrings() { return mUpdateStrings; }
	void SetUpdateStrings() { mUpdateStrings = false; }

	std::string mAction = "";
	std::string mHealth = "";
	std::string mWinStatus = "";
};