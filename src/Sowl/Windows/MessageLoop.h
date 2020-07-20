#pragma once
#include <windows.h>
#include "Window.h"

class MessageLoop
{
public:
	MessageLoop();

	virtual int Run();
	virtual bool GetMessage(MSG& message);
	virtual bool HandleErrorAndExit();
	virtual void ProcessMessage(MSG& message);
	void SetResult(int result);

protected:
	int result;
};
