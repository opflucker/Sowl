#pragma once
#include <Windows.h>

namespace sowl
{
	/// @brief Builds a call to ::RegisterClass.
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
		WNDCLASS Register() const;

	private:
		WNDCLASS wc;
	};
}