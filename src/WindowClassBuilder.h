#pragma once
#include "WindowClass.h"

class WindowClassBuilder
{
public:
	WindowClassBuilder(HINSTANCE hInstance, LPCWSTR className);
	WindowClassBuilder& WithBackgroundBrush(HBRUSH handle);
	WindowClassBuilder& WithCursor(HCURSOR handle);
	WindowClassBuilder& WithIcon(HICON handle);
	WindowClassBuilder& WithMenu(LPCWSTR name);
	WindowClassBuilder& WithStyle(UINT style);
	WindowClass Build() const;

private:
	HINSTANCE hInstance;
	LPCWSTR className;
	HBRUSH hbrush;
	HCURSOR hcursor;
	HICON hicon;
	LPCWSTR menuName;
	UINT style;
};
