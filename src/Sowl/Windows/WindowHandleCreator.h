#pragma once
#include <Windows.h>

namespace sowl
{
	/// @brief Builds a call to <a href="https://docs.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-createwindowexw">CreateWindowEx</a>.
	class WindowHandleCreator
	{
	public:
		WindowHandleCreator(HINSTANCE processHandle, LPCWSTR className);

		HINSTANCE ProcessHandle() const;
		LPCWSTR ClassName() const;

		WindowHandleCreator& WithTitle(LPCWSTR title);
		WindowHandleCreator& WithStyle(DWORD style);
		WindowHandleCreator& AndStyle(DWORD style);
		WindowHandleCreator& WithRect(int x, int y, int width, int height);
		WindowHandleCreator& WithParent(HWND hParentWindow);
		WindowHandleCreator& WithMenu(HMENU hMenu);
		WindowHandleCreator& WithParams(LPVOID lpParam);
		HWND Create() const;

	private:
		CREATESTRUCT cp;
	};
}
