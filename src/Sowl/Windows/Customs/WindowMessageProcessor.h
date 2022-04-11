#pragma once
#include <Windows.h>

namespace sowl
{
	class WindowMessageProcessor
	{
	public:
		virtual LRESULT Process(UINT uMsg, WPARAM wParam, LPARAM lParam) = 0;
		virtual ~WindowMessageProcessor() = default;
	};
}