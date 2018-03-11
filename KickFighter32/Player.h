#pragma once
#include "Helper.h"

class Player
{
private:
	int mHealth = 100;
	const int mAttackDamage = 10;

	const float TIME_BEFORE_ACTION = 0.5f;
	float timer = TIME_BEFORE_ACTION;

	bool mIsBlocking = false;
	bool mCanChangeAction = true;
	bool mActionChanged = false;

	Helper::Actions mCurrentAction = Helper::Actions::none;

public:
	Player() {}
	~Player() {}

	void Update(float deltaTime, Helper::Actions action);
	bool SetAction(const Helper::Actions action) noexcept;
	const Helper::Actions getAction() const noexcept { return mCurrentAction; }
	int GetHealth() const noexcept { return mHealth; }
	int GetAttack();
	void TakeDamage (const int damage, const Helper::Actions action) noexcept;
	
};