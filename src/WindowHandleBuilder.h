#pragma once
#include <windows.h>

class WindowHandleBuilder
{
public:
	WindowHandleBuilder(HINSTANCE hInstance, LPCWSTR className);
	WindowHandleBuilder& WithParam(LPVOID lpParam);
	WindowHandleBuilder& WithTitle(LPCWSTR title);
	HWND Build();

private:
	HINSTANCE hInstance;
	LPCWSTR className;
	LPVOID lpParam;
	LPCWSTR title;
};
