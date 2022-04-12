#include "ControlWindow.h"
#include <utility>
using namespace sowl;

ControlWindow::ControlWindow() = default;

ControlWindow::ControlWindow(HWND hwnd)
    : Window(hwnd)
{
}

ControlWindow::ControlWindow(ControlWindow&& other) noexcept
    : Window(std::move(other))
{
}

ControlWindow& ControlWindow::operator=(ControlWindow&& other) noexcept
{
    Window::operator=(std::move(other));
    return *this;
}

int ControlWindow::GetId() const
{
	return (int)(uintptr_t)GetMenu(GetHandle());
}
