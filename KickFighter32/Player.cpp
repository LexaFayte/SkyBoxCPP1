#include "Player.h"
#include <math.h>

void Player::Update(float deltaTime, Helper::Actions action)
{
	timer -= deltaTime;
	SetAction(action);
	if (timer <= 0.0f)
	{
		mCanChangeAction = true;
		mIsBlocking = false;
		timer = TIME_BEFORE_ACTION;
	}
}

void Player::TakeDamage(const int damage, const Helper::Actions action) noexcept
{
	//do calculations for if blocking
	int finalDamage = damage;
	if (action != Helper::Actions::none)
	{
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


bool Player::SetAction(const Helper::Actions action) noexcept
{
	//check what the timer is at; can we change our action?
	if(mCanChangeAction)
	{
		mCanChangeAction = false;
		mCurrentAction = action;
		mActionChanged = true;

		if (mCurrentAction == Helper::Actions::HighBlock ||
			mCurrentAction == Helper::Actions::LowBlock)
		{
			mIsBlocking = true;
		}
		else
		{
			mIsBlocking = false;
		}

		return true;
	}

	return false;
}

int Player::GetAttack()
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