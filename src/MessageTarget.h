#pragma once
#include <windows.h>

class MessageTarget
{
public:
	virtual LRESULT Process(UINT uMsg, WPARAM wParam, LPARAM lParam) = 0;
};

