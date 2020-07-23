#pragma once
#include <windows.h>
#include "Window.h"

namespace sowl
{
	class MessageLoop
	{
	public:
		virtual int Run();
		virtual int GetMessage(MSG& message);
		virtual bool HandleErrorAndExit();
		virtual void ProcessMessage(MSG& message);
	};
}