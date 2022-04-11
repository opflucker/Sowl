#include "ControlWindow.h"

using namespace sowl;

ControlWindow::ControlWindow() = default;

ControlWindow::ControlWindow(HWND hwnd)
    : Window(hwnd)
{
}

ControlWindow::ControlWindow(ControlWindow&& other) noexcept
    : Window(other.SetHandle(nullptr))
{
}

ControlWindow& ControlWindow::operator=(ControlWindow&& other) noexcept
{
    SetHandle(other.SetHandle(nullptr));
    return *this;
}

int ControlWindow::GetId() const
{
	return (int)(uintptr_t)GetMenu(GetHandle());
}
