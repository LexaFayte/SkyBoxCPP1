#include "Button.h"

void Button::Press()
{
	Execute(PressCallBack);
}

void Button::Release()
{
	Execute(ReleaseCallBack);
}

void _ButtonCallBack::Execute(CallBack c)
{
	for (auto& function : c.mRegisteredFunctions)
	{
		function();
	}
}
