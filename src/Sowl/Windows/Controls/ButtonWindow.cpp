#include "ButtonWindow.h"
#include <utility>

using namespace sowl;

WindowHandleCreator ButtonWindow::HandleCreator(const Window& parentWindow, WORD id)
{
    return WindowHandleCreator(parentWindow.GetProcessHandle(), L"BUTTON")
        .WithParent(parentWindow.GetHandle())
        .WithMenu((HMENU)(uintptr_t)id)
        .WithStyle(WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON);
}

ButtonWindow::ButtonWindow(HWND hwnd)
    : ControlWindow(hwnd)
{
}

ButtonWindow::ButtonWindow(ButtonWindow&& other) noexcept
    : ControlWindow(std::move(other))
{
}

ButtonWindow& ButtonWindow::operator=(ButtonWindow&& other) noexcept
{
    ControlWindow::operator=(std::move(other));
    return *this;
}
