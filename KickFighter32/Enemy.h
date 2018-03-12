#pragma once
#include "Helper.h"

class Enemy
{
private:
	int mHealth = 100;
	const int mAttackDamage = 10;
	
	Helper::Actions mCurrentAction = Helper::Actions::none;
	bool mIsBlocking = false;
	bool mActionChanged = true;

	const int NUM_ACTIONS = 4;
	const float TIME_BEFORE_ACTION = 1.0f;
	float timer = TIME_BEFORE_ACTION;

	void ProcessAction();

public:
	Enemy() { srand(time(0)); }
	~Enemy() {}

	const Helper::Actions getAction() const noexcept { return mCurrentAction; }
	int GetHealth() const noexcept { return mHealth; }
	void TakeDamage (const int damage, const Helper::Actions action) noexcept;
	void Update(float deltaTime);
	int GetAttack();
};