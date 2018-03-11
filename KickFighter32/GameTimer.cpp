#include "GameTimer.h"
#include <windows.h>


GameTimer::GameTimer() : mSecondsPerCount(0.0), mDeltaTime(-1.0), mBaseTime(0), mPausedTime(0),
mPrevTime(0), mCurrTime(0), mStopped(false)
{
	__int64 countsPerSec;
	QueryPerformanceFrequency((LARGE_INTEGER*)&countsPerSec);
	mSecondsPerCount = 1.0 / (double)countsPerSec;
}


GameTimer::~GameTimer()
{
}

void GameTimer::Tick()
{
	if (mStopped)
	{
		mDeltaTime = 0.0;
		return;
	}

	//get the time this frame
	__int64 currTime;
	QueryPerformanceCounter((LARGE_INTEGER*)&currTime);
	mCurrTime = currTime;

	//Calculate Delta Time
	mDeltaTime = (mCurrTime - mPrevTime) * mSecondsPerCount;

	//set up for next frame
	mPrevTime = mCurrTime;

	//it's possible for Delta Time to become negative
	//in the case of getting swapped over to another processor
	//or if the processor goes into power save mode
	if (mDeltaTime < 0.0)
	{
		mDeltaTime = 0.0;
	}
}

float GameTimer::DeltaTime() const
{
	return (float)mDeltaTime;
}

void GameTimer::Reset()
{
	__int64 currTime;
	QueryPerformanceCounter((LARGE_INTEGER*)&currTime);

	mBaseTime = currTime;
	mPrevTime = currTime;
	mStopTime = 0;
	mStopped = false;
}

void GameTimer::Stop()
{
	if (!mStopped)
	{
		__int64 currTime;
		QueryPerformanceCounter((LARGE_INTEGER*)&currTime);

		mStopTime = currTime;
		mStopped = true;
	}
}

void GameTimer::Start()
{
	__int64 startTime;
	QueryPerformanceCounter((LARGE_INTEGER*)&startTime);

	//we are resuming from a stopped state
	if (mStopped)
	{
		//accumulate paused time
		mPausedTime += (startTime - mStopTime);

		//reset current time since it's invalid since time paused
		mPrevTime = startTime;

		//we are no longer stopped
		mStopTime = 0;
		mStopped = false;
	}
}

float GameTimer::TotalTime() const
{
	if (mStopped)
	{
		return (float)(((mStopTime - mPausedTime) - mBaseTime)*mSecondsPerCount);
	}
	else
	{
		return (float)(((mCurrTime - mPausedTime) - mBaseTime)*mSecondsPerCount);
	}
}


