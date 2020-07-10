#pragma once
#include <Windows.h>
#include "WindowClassRegistered.h"

class WindowClassBuilder
{
public:
	WindowClassBuilder(HINSTANCE hInstance, LPCWSTR className, WNDPROC wndProc);
	WindowClassBuilder& WithBackgroundBrush(HBRUSH handle);
	WindowClassBuilder& WithCursor(HCURSOR handle);
	WindowClassBuilder& WithIcon(HICON handle);
	WindowClassBuilder& WithMenu(LPCWSTR name);
	WindowClassBuilder& WithStyle(UINT style);
	const WNDCLASS& Result() const;
	const WindowClassRegistered& Register() const;

private:
	WNDCLASS wc;
};
