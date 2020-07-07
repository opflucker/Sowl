#pragma once
#include <windows.h>
#include "WindowHandleBuilder.h"

class WindowClassRegistered
{
public:
	WindowClassRegistered(const WNDCLASS& wc);
	WindowHandleBuilder CreateHandleBuilder() const;

private:
	HINSTANCE hInstance;
	LPCWSTR className;
};
