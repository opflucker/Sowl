#pragma once
#include "../Window.h"

namespace sowl
{
	/// @brief Encapsulates a <a href="https://docs.microsoft.com/en-us/windows/win32/controls/window-controls">control window</a> handle.
	class ControlWindow : public Window
	{
	public:
		ControlWindow();
		explicit ControlWindow(HWND hwnd);

		// move constructor and move assigment
		ControlWindow(ControlWindow&& other) noexcept;
		ControlWindow& operator=(ControlWindow&& other) noexcept;

		int GetId() const;
	};
}