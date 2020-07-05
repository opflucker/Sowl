#pragma once
#include <windows.h>
#include "WindowHandleBuilder.h"
#include "MessageTarget.h"

class WindowClass
{
public:
	WindowClass(HINSTANCE hInstance, LPCWSTR className, 
		HBRUSH hbrush = NULL, 
		HCURSOR hcursor = NULL,
		HICON hicon = NULL,
		LPCWSTR menuName = NULL,
		UINT style = 0);
	WindowHandleBuilder CreateBuilder(MessageTarget * pMessageTarget) const;

private:
	static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	WNDCLASS wc;
	ATOM wcAtom;
};

