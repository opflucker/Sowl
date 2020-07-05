#pragma once
#include "Window.h"
#include "WindowHandleBuilder.h"

class ControlWindow : public Window
{
public:
	static WindowHandleBuilder CreateHandleBuilder(Window parentWindow, LPCWSTR className, WORD id);
	ControlWindow(WindowHandleBuilder builder);
	int GetId() const;
};
