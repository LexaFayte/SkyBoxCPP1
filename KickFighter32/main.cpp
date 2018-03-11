#include <windows.h>
#include <windowsx.h>
#include <sstream>
#include <string>
#include "Helper.h"
#include "GameTimer.h"
#include "Game.h"

//screen resolution
#define SCREEN_WIDTH 550
#define SCREEN_HEIGHT 100

//INPUT CODES
#define VK_A 0x41
#define VK_D 0x44
#define VK_S 0x53
#define VK_W 0x57

//globals
HWND hWnd;
GameTimer timer;
Game game;

//prototypes
void CalculateFPS(void);

/*
	prototype for WndProc
*/
LRESULT CALLBACK WindowProc(
	HWND hWnd,
	UINT message,
	WPARAM wParam,
	LPARAM lParam);

/*
	Entry point for windows program
*/
int WINAPI WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nShowCmd)
{
	WNDCLASSEX wc;

	ZeroMemory(&wc, sizeof(WNDCLASSEX));

	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WindowProc;
	wc.hInstance = hInstance;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	//wc.hbrBackground = (HBRUSH)COLOR_WINDOW; //not needed for fullscreen
	wc.lpszClassName = L"WindowClass";

	RegisterClassEx(&wc);

	RECT wr = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
	AdjustWindowRect(&wr, WS_OVERLAPPEDWINDOW, FALSE);

	hWnd = CreateWindowEx(NULL,
		L"WindowClass",
		L"Our First Direct3D Program",
		WS_OVERLAPPEDWINDOW,
		300,
		300,
		wr.right - wr.left,
		wr.bottom - wr.top,
		NULL,
		NULL,
		hInstance,
		NULL);

	ShowWindow(hWnd, nShowCmd);

	//MSG is a struct that holds Windows events messages
	MSG msg;
	timer.Reset();

	while (TRUE)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);

			if (msg.message == WM_QUIT)
				break;
		}
		else
		{
			//run game code...
			timer.Tick();
			CalculateFPS();
			//update all game logic with timer.DeltaTime();
			game.Update(timer.DeltaTime());
			if (game.GetUpdateStrings())
			{
				InvalidateRect(hWnd, NULL, TRUE);
			}
		}	
	}
	return msg.wParam;
}

std::string s;

/*
	main message handler for the program
*/
LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	RECT	rect;
	HDC hdc = GetDC(hWnd);

	

	switch (message)
	{
		case WM_PAINT:
			hdc = BeginPaint(hWnd, &ps);//get a handle to a device context for drawing
			GetClientRect(hWnd, &rect);//define drawing area for clipping	
			FillRect(hdc, &rect, (HBRUSH)GetStockObject(WHITE_BRUSH));
			SetBkMode(hdc, TRANSPARENT);//set text background to transparent
			SetTextColor(hdc, 0x00000000);

			TextOutA(hdc, 150, 25, game.mAction.c_str(), game.mAction.length());
			TextOutA(hdc, 150, 50, game.mHealth.c_str(), game.mHealth.length());
			TextOutA(hdc, 150, 75, game.mWinStatus.c_str(), game.mWinStatus.length());
			game.SetUpdateStrings();
			EndPaint(hWnd, &ps);
			break;

		case WM_KEYUP:
			
			switch (wParam)
			{
				case VK_LEFT:
				case VK_A://A
					game.SetPlayerAction(Helper::Actions::HighBlock);
					break;

				case VK_RIGHT:
				case VK_D://D
					game.SetPlayerAction(Helper::Actions::LowBlock);
					break;

				case VK_DOWN:
				case VK_S://S
					game.SetPlayerAction(Helper::Actions::LowKick);
					break;

				case VK_UP:
				case VK_W://W
					game.SetPlayerAction(Helper::Actions::HighKick);
					break;
			}
			
			//RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW);
			break;

		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;
	}

	return DefWindowProc(hWnd, message, wParam, lParam);
}

void CalculateFPS(void)
{
	static int frameCount = 0;
	static float timeElapsed = 0.0f;

	frameCount++;

	if ((timer.TotalTime() - timeElapsed) >= 1.0f)
	{
		float fps = (float)frameCount;
		float mspf = 1000.0f / fps;

		std::wostringstream outs;
		outs.precision(6);
		outs << L"KickFighter32 || FPS: " << fps << L" " << L"Frame Time: " << mspf << L" (ms)";
		SetWindowText(hWnd, outs.str().c_str());

		frameCount = 0;
		timeElapsed += 1.0f;
	}
}
