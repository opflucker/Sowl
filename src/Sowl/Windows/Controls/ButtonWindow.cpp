#include "ButtonWindow.h"
#include <utility>

using namespace sowl;

WindowHandleBuilder ButtonWindow::CreateHandleBuilder(const Window& parentWindow, WORD id)
{
    return ControlWindow::CreateHandleBuilder(parentWindow, L"BUTTON", id)
        .WithAddStyle(BS_DEFPUSHBUTTON);
}

ButtonWindow::ButtonWindow(const Window& parentWindow, WORD id)
    : ControlWindow(parentWindow, id)
{
}

ButtonWindow::ButtonWindow(WindowHandleBuilder builder)
    : ControlWindow(builder)
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

ButtonWindow& ButtonWindow::operator=(WindowHandleBuilder builder) noexcept
{
    ControlWindow::operator=(builder);
    return *this;
}
