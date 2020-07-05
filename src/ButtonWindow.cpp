#include "ButtonWindow.h"

WindowHandleBuilder ButtonWindow::CreateHandleBuilder(const Window& parentWindow, WORD id)
{
    return ControlWindow::CreateHandleBuilder(parentWindow, L"BUTTON", id)
        .WithAddStyle(BS_DEFPUSHBUTTON);
}

ButtonWindow::ButtonWindow(WindowHandleBuilder builder)
    : ControlWindow(builder)
{
}
