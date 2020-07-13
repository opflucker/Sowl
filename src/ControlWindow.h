#pragma once
#include "Window.h"
#include "WindowHandleBuilder.h"

class ControlWindow : public Window
{
public:
	static WindowHandleBuilder CreateHandleBuilder(const Window& parentWindow, LPCWSTR className, WORD id);

	ControlWindow();
	ControlWindow(const Window& parentWindow, WORD id);
	ControlWindow(WindowHandleBuilder builder);
	ControlWindow(ControlWindow&& other) noexcept;

	ControlWindow& operator=(WindowHandleBuilder builder) noexcept;
	ControlWindow& operator=(ControlWindow&& other) noexcept;

	HWND SetHandle(const Window& parentWindow, WORD id);
	int GetId() const;

protected:
	using Window::SetHandle;
};
