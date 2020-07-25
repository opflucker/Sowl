#pragma once
#include <Windows.h>
#include "WindowHandleBuilder.h"

namespace sowl
{
	/// @brief Builds a call to ::RegisterClass.
	class WindowClassBuilder
	{
	public:
		WindowClassBuilder(HINSTANCE processHandle, LPCWSTR className, WNDPROC wndProc);
		WindowClassBuilder& WithBackgroundBrush(HBRUSH handle);
		WindowClassBuilder& WithCursor(HCURSOR handle);
		WindowClassBuilder& WithIcon(HICON handle);
		WindowClassBuilder& WithMenu(LPCWSTR name);
		WindowClassBuilder& WithStyle(UINT style);
		WNDCLASS Register() const;
		WindowHandleBuilder RegisterAndCreateHandleBuilder() const;

	private:
		WNDCLASS wc;
	};
}