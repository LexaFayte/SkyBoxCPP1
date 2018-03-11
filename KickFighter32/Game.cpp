#include "Game.h"

void Game::Update(float deltaTime)
{
	timer -= deltaTime;

	if (!mGameOver)
	{
		//update the AI
		enemy.Update(deltaTime);
		player.Update(deltaTime, playerAction);

		//calculate damage if any
		enemy.TakeDamage(player.GetAttack(), player.getAction());
		player.TakeDamage(enemy.GetAttack(), enemy.getAction());
		

		//check health of player for gameover
		if (player.GetHealth() == 0 || enemy.GetHealth() == 0)
		{
			if (player.GetHealth() == 0)
			{
				mPlayerWin = false;
			}
			else
			{
				mPlayerWin = true;
			}
			
			mGameOver = true;
		}
	}

	if (timer <= 0.0f)
	{
		UpdateStrings();
		timer = DISPLAY_UPDATE_DELAY;
	}
	
}

void Game::SetPlayerAction(const Helper::Actions action)
{
	if (!mGameOver)
	{
		playerAction = action;
	}
}

void Game::UpdateStrings()
{
	mActionStrings[ACTION_STRINGS_OFFSET] = Helper::ParseAction(playerAction);
	mActionStrings[ACTION_STRINGS_OFFSET + 1] = Helper::ParseAction(enemy.getAction());
	playerAction = Helper::Actions::none;

	mHealthStrings[HEALTH_STRINGS_OFFSET] = std::to_string(player.GetHealth());
	mHealthStrings[HEALTH_STRINGS_OFFSET + 1] = std::to_string(enemy.GetHealth());

	mAction = Helper::BuildString(mActionStrings, ACTION_STRINGS_OFFSET);
	mHealth = Helper::BuildString(mHealthStrings, HEALTH_STRINGS_OFFSET);

	if (mGameOver)
	{
		if (mPlayerWin)
		{
			mWinStatus = "WIN";
		}
		else
		{
			mWinStatus = "LOSE";
		}
	}
	mUpdateStrings = true;
}

