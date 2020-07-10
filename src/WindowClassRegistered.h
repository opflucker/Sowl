#pragma once
#include <windows.h>
#include "WindowHandleBuilder.h"

class WindowClassRegistered
{
public:
	WindowClassRegistered(HINSTANCE hInstance, LPCWSTR className);
	WindowHandleBuilder CreateHandleBuilder() const;

private:
	HINSTANCE hInstance;
	LPCWSTR className;
};
