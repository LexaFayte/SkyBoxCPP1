#pragma once
#include <vector>
#include <map>
#include <functional>

struct CallBackFunction
{

private:
	int mTicket = 0;
public:
	std::function<void()> mFunction;

	CallBackFunction(std::function<void()>& fn, int ticket)
	{
		mFunction = fn;
		mTicket = ticket;
	}

	bool operator==(CallBackFunction& rhs)
	{
		if (mTicket == rhs.mTicket)
		{
			return true;
		}
		return false;
	}
};

namespace _ButtonCallBack
{
	struct CallBack
	{
	private:
		std::vector<CallBackFunction> mRegisteredFunctions;
	public:
		void operator+=(CallBackFunction rhs)
		{
			mRegisteredFunctions.push_back(rhs);
		}

		void operator-=(CallBackFunction rhs)
		{
			for (auto it = mRegisteredFunctions.begin(); it != mRegisteredFunctions.end(); ++it)
			{
				if (*it == rhs)
				{
					mRegisteredFunctions.erase(it);
					break;
				}
			}
		}

		friend void Execute(CallBack c);
	};
}


class Button
{
private:	
	int mTicketCounter = 0;
public:
	_ButtonCallBack::CallBack PressCallBack;
	_ButtonCallBack::CallBack ReleaseCallBack;

	void Press();
	void Release();	
	CallBackFunction CreateCallBackFunction(std::function<void()>& fn)
	{
		CallBackFunction function(std::forward<decltype(fn)>(fn), mTicketCounter++);
		return function;
	}
};
