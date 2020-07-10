#pragma once
#include <Windows.h>

class WindowClassBuilder
{
public:
	WindowClassBuilder(HINSTANCE hInstance, LPCWSTR className, WNDPROC wndProc);
	WindowClassBuilder& WithBackgroundBrush(HBRUSH handle);
	WindowClassBuilder& WithCursor(HCURSOR handle);
	WindowClassBuilder& WithIcon(HICON handle);
	WindowClassBuilder& WithMenu(LPCWSTR name);
	WindowClassBuilder& WithStyle(UINT style);
	WNDCLASS Register() const;
	WNDCLASS Result() const;

private:
	WNDCLASS wc;
};
