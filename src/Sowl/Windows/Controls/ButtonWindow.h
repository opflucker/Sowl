#pragma once
#include "ControlWindow.h"
#include "../WindowHandleCreator.h"

namespace sowl
{
	class ButtonWindow : public ControlWindow
	{
	public:
		static WindowHandleCreator HandleCreator(const Window& parentWindow, WORD id);
		ButtonWindow() = default;
		explicit ButtonWindow(HWND hwnd);
		~ButtonWindow() = default;

		// move constructor and move assigment
		ButtonWindow(ButtonWindow&& other) noexcept;
		ButtonWindow& operator=(ButtonWindow&& other) noexcept;

		// set-handle with assigment
		ButtonWindow& operator=(HWND hwnd) noexcept;
	};
}