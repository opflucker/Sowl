#pragma once
#include "ControlWindow.h"

class ButtonWindow : public ControlWindow
{
public:
	static WindowHandleBuilder CreateHandleBuilder(Window parentWindow, WORD id);
	ButtonWindow(WindowHandleBuilder builder);
};
