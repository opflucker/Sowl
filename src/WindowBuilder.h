#pragma once
#include <windows.h>

class WindowBuilder
{
public:
	WindowBuilder(HINSTANCE hInstance, LPCWSTR className);
	WindowBuilder& WithParam(LPVOID lpParam);
	WindowBuilder& WithTitle(LPCWSTR title);
	HWND Build();

private:
	HINSTANCE hInstance;
	LPCWSTR className;
	LPVOID lpParam;
	LPCWSTR title;
};

