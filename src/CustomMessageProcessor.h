#pragma once
#include <windows.h>

class CustomMessageProcessor
{
public:
	static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	virtual LRESULT Process(UINT uMsg, WPARAM wParam, LPARAM lParam) = 0;
};
