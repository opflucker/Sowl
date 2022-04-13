#pragma once

namespace sowl
{
	class Utilities
	{
	public:
		static const wchar_t* GetWindowMessageText(unsigned int msg);
		static void OutputDebugWindowMessage(unsigned int msg, const wchar_t* const description);
	};
}
