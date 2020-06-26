#pragma once
#include <windows.h>
#include "MessageTarget.h"
#include "WindowClass.h"

class Window : MessageTarget
{
public:
	Window(WindowClass & wc, LPCWSTR title);
	bool IsCreated();
	bool Show(int nCmdShow);

	virtual LRESULT Process(UINT uMsg, WPARAM wParam, LPARAM lParam) override;

private:
	HWND hwnd;
};

