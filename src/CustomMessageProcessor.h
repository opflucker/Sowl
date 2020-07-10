#pragma once
#include <windows.h>

class CustomMessageProcessor
{
public:

	virtual LRESULT Process(UINT uMsg, WPARAM wParam, LPARAM lParam) = 0;
};
