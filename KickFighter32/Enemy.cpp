#include "Enemy.h"
#include <math.h>

void Enemy::TakeDamage(const int damage, Helper::Actions action) noexcept
{
	int finalDamage = damage;

	if (action != Helper::Actions::none)
	{ 	//do calculations for if blocking
		if (mIsBlocking)
		{
			int damageReduction = 0;

			if (action == Helper::Actions::HighKick &&
				mCurrentAction == Helper::Actions::HighBlock ||
				action == Helper::Actions::LowKick &&
				mCurrentAction == Helper::Actions::LowBlock)
			{
				damageReduction = Helper::RandomFloat(0.25, 1);
				finalDamage = floor(damage * damageReduction);
			}
		}

		mHealth -= finalDamage;
	}

	

	if (mHealth < 0)
	{
		mHealth = 0;
	}
}

void Enemy::Update(float deltaTime)
{
	timer -= deltaTime;
	if (timer <= 0.0f)
	{
		ProcessAction();
		timer = TIME_BEFORE_ACTION;
	}
}

void Enemy::ProcessAction()
{
	int action = rand() % NUM_ACTIONS;

	switch (action)
	{
		case 0:
			mCurrentAction = Helper::Actions::HighKick;
			mIsBlocking = false;
			break;
		case 1:
			mCurrentAction = Helper::Actions::LowBlock;
			mIsBlocking = true;
			break;
		case 2:
			mCurrentAction = Helper::Actions::LowKick;
			mIsBlocking = false;
			break;
		case 3:
			mCurrentAction = Helper::Actions::HighBlock;
			mIsBlocking = true;
			break;
	}
	mActionChanged = true;
}

int Enemy::GetAttack()
{
	if (mActionChanged)
	{
		mActionChanged = false;
		if (mIsBlocking)
		{
			return 0;
		}
		return mAttackDamage;
	}

	return 0;
}