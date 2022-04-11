#pragma once
#include "../Window.h"

namespace sowl
{
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