#pragma once
#include <Windows.h>

namespace sowl
{
	/// @brief Builds a call to <a href"https://docs.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-registerclassw">RegisterClass</a>.
	class WindowClassRegisterer
	{
	public:
		WindowClassRegisterer(HINSTANCE processHandle, LPCWSTR className, WNDPROC windowProcedure);

		HINSTANCE ProcessHandle() const;
		LPCWSTR ClassName() const;

		WindowClassRegisterer& WithBackgroundBrush(HBRUSH handle);
		WindowClassRegisterer& WithCursor(HCURSOR handle);
		WindowClassRegisterer& WithIcon(HICON handle);
		WindowClassRegisterer& WithMenu(LPCWSTR name);
		WindowClassRegisterer& WithStyle(UINT style);
		void Register() const;

	private:
		WNDCLASS wc;
	};
}