#pragma once
#include <Windows.h>

namespace sowl
{
	/// @brief Builds a call to ::RegisterClass.
	class CustomWindowClassRegisterer
	{
	public:
		CustomWindowClassRegisterer(HINSTANCE processHandle, LPCWSTR className);
		CustomWindowClassRegisterer& WithBackgroundBrush(HBRUSH handle);
		CustomWindowClassRegisterer& WithCursor(HCURSOR handle);
		CustomWindowClassRegisterer& WithIcon(HICON handle);
		CustomWindowClassRegisterer& WithMenu(LPCWSTR name);
		CustomWindowClassRegisterer& WithStyle(UINT style);
		WNDCLASS Register() const;
		static void EnsureRegistered(HINSTANCE processHandle, LPCWSTR className);

	private:
		WNDCLASS wc;
	};
}