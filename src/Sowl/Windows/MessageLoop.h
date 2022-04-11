#pragma once
#include "Window.h"

namespace sowl
{
	/// @brief Encapsulates a generic message loop.
	class MessageLoop
	{
	public:
		virtual int Run();
		virtual int GetMessage(MSG& message);
		virtual bool HandleErrorAndExit();
		virtual void ProcessMessage(MSG& message);
	};
}