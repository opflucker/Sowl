#pragma once
#include "ControlWindow.h"

namespace sowl
{
	class ButtonWindow : public ControlWindow
	{
	public:
		static WindowHandleBuilder CreateHandleBuilder(const Window& parentWindow, WORD id);

		ButtonWindow() = default;
		ButtonWindow(const Window& parentWindow, WORD id);
		ButtonWindow(WindowHandleBuilder builder);
		ButtonWindow(ButtonWindow&& other) noexcept;

		ButtonWindow& operator=(WindowHandleBuilder builder) noexcept;
		ButtonWindow& operator=(ButtonWindow&& other) noexcept;
	};
}