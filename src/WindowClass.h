#pragma once
#include <windows.h>
#include "WindowBuilder.h"
#include "MessageTarget.h"

class WindowClass
{
public:
	WindowClass(HINSTANCE hInstance, LPCWSTR className);
	WindowBuilder CreateBuilder(MessageTarget * pMessageTarget) const;

private:
	WNDCLASS wc;
	ATOM wcAtom;
};

