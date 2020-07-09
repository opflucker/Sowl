#pragma once
#include <windows.h>
#include "Window.h"

class MessageLoop
{
public:
	static void Run();
	static void Run(const Window& dlgWindow);
};
