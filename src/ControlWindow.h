#pragma once
#include "Window.h"
#include "WindowHandleBuilder.h"

class ControlWindow : public Window
{
public:
	static WindowHandleBuilder CreateHandleBuilder(const Window& parentWindow, LPCWSTR className, WORD id);
	ControlWindow(WindowHandleBuilder builder);
	int GetId() const;
};
