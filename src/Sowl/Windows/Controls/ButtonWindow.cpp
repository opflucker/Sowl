#include "ButtonWindow.h"
#include <utility>

using namespace sowl;

ControlWindowCreator<ButtonWindow> ButtonWindow::Creator(const Window& parentWindow, WORD id)
{
    return ControlWindowCreator<ButtonWindow>(parentWindow, L"BUTTON", id, WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON);
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
