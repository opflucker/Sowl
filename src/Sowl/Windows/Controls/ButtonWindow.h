#pragma once
#include "ControlWindow.h"
#include "ControlCreator.h"

namespace sowl
{
	class ButtonWindow : public ControlWindow
	{
	public:
		static ControlCreator<ButtonWindow> Creator(const Window& parentWindow, WORD id);

		ButtonWindow() = default;
		explicit ButtonWindow(HWND hwnd);
		~ButtonWindow() = default;

		// move constructor and move assigment
		ButtonWindow(ButtonWindow&& other) noexcept;
		ButtonWindow& operator=(ButtonWindow&& other) noexcept;
	};
}