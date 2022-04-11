#pragma once
#include <Windows.h>

namespace sowl
{
	/// @brief Builds a call to ::RegisterClass.
	class WindowClassRegisterer
	{
	public:
		WindowClassRegisterer(HINSTANCE processHandle, LPCWSTR className);
		WindowClassRegisterer& WithBackgroundBrush(HBRUSH handle);
		WindowClassRegisterer& WithCursor(HCURSOR handle);
		WindowClassRegisterer& WithIcon(HICON handle);
		WindowClassRegisterer& WithMenu(LPCWSTR name);
		WindowClassRegisterer& WithStyle(UINT style);
		WNDCLASS Register() const;
		static void EnsureRegistered(HINSTANCE processHandle, LPCWSTR className);

	private:
		WNDCLASS wc;

		static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	};
}