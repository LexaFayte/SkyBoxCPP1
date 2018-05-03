#pragma once
#include <vector>
#include <functional>

namespace _ButtonCallBack
{
	struct CallBack
	{
	private:
		std::vector<std::function<void()>> mRegisteredFunctions;
	public:
		void operator+=(std::function<void()>& rhs)
		{
			mRegisteredFunctions.push_back(rhs);
		}

		void operator-=(std::function<void()>& rhs)
		{
			for (auto it = mRegisteredFunctions.begin(); it != mRegisteredFunctions.end(); ++it)
			{
				if (it->target_type() == rhs.target_type())
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

	

public:
	_ButtonCallBack::CallBack PressCallBack;
	_ButtonCallBack::CallBack ReleaseCallBack;

	void Press();
	void Release();	

	/*void Register(std::function<void()>& fn);
	void Unregister(std::function<void()>& fn);*/
};
