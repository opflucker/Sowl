#pragma once
#include <windows.h>

namespace sowl
{
	/// @brief Builds a call to ::CreateWindowEx.
	class WindowHandleBuilder
	{
	public:
		WindowHandleBuilder(HINSTANCE processHandle, LPCWSTR className);
		WindowHandleBuilder(const WNDCLASS& wc);
		WindowHandleBuilder& WithTitle(LPCWSTR title);
		WindowHandleBuilder& WithStyle(DWORD style);
		WindowHandleBuilder& WithAddStyle(DWORD style);
		WindowHandleBuilder& WithRect(int x, int y, int width, int height);
		WindowHandleBuilder& WithParent(HWND hParentWindow);
		WindowHandleBuilder& WithMenu(HMENU hMenu);
		WindowHandleBuilder& WithParam(LPVOID lpParam);
		HWND Build();

	private:
		LPCWSTR className;
		LPCWSTR title;
		DWORD style;
		int x;
		int y;
		int width;
		int height;
		HWND hParentWindow;
		HMENU hMenu;
		HINSTANCE hInstance;
		LPVOID lpParam;
	};
}
