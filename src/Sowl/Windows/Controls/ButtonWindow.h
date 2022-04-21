#pragma once
#include "ControlWindow.h"
#include "ControlWindowCreator.h"

namespace sowl
{
	/// @brief Encapsulates a <a href="https://docs.microsoft.com/en-us/windows/win32/controls/buttons">button window</a> handle.
	class ButtonWindow : public ControlWindow
	{
	public:
		static ControlWindowCreator<ButtonWindow> Creator(const Window& parentWindow, WORD id);

		ButtonWindow() = default;
		explicit ButtonWindow(HWND hwnd);
		~ButtonWindow() = default;

		// move constructor and move assigment
		ButtonWindow(ButtonWindow&& other) noexcept;
		ButtonWindow& operator=(ButtonWindow&& other) noexcept;
	};
}