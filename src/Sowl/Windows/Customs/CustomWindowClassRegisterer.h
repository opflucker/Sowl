#pragma once
#include <Windows.h>

namespace sowl
{
	/// @brief Builds a call to ::RegisterClass.
	class CustomWindowClassRegisterer
	{
	public:
		CustomWindowClassRegisterer(HINSTANCE processHandle, LPCWSTR className);

		HINSTANCE ProcessHandle() const;
		LPCWSTR ClassName() const;

		CustomWindowClassRegisterer& WithBackgroundBrush(HBRUSH handle);
		CustomWindowClassRegisterer& WithCursor(HCURSOR handle);
		CustomWindowClassRegisterer& WithIcon(HICON handle);
		CustomWindowClassRegisterer& WithMenu(LPCWSTR name);
		CustomWindowClassRegisterer& WithStyle(UINT style);
		WNDCLASS Register() const;

	private:
		WNDCLASS wc;
	};
}