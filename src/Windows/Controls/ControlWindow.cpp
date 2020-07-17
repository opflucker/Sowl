#include "ControlWindow.h"

WindowHandleBuilder ControlWindow::CreateHandleBuilder(const Window& parentWindow, LPCWSTR className, WORD id)
{
    // TODO: Check "id" is in [8, 0xDFFF]
    return WindowHandleBuilder(parentWindow.GetProcessHandle(), className)
        .WithParent(parentWindow.GetHandle())
        .WithMenu((HMENU)id)
        .WithStyle(WS_TABSTOP | WS_VISIBLE | WS_CHILD);
}

ControlWindow::ControlWindow(WindowHandleBuilder builder)
    : Window(builder.Build())
{
}

ControlWindow::ControlWindow(ControlWindow&& other) noexcept
    : Window(other.SetHandle(NULL))
{
}

ControlWindow& ControlWindow::operator=(ControlWindow&& other) noexcept
{
    SetHandle(other.SetHandle(NULL));
    return *this;
}

ControlWindow& ControlWindow::operator=(WindowHandleBuilder builder) noexcept
{
    SetHandle(builder.Build());
    return *this;
}

ControlWindow::ControlWindow()
    : Window(NULL)
{
}

ControlWindow::ControlWindow(const Window& parentWindow, WORD id)
    : Window(parentWindow.GetDialogItem(id))
{
}

HWND ControlWindow::SetHandle(const Window& parentWindow, WORD id)
{
    return SetHandle(parentWindow.GetDialogItem(id));
}

int ControlWindow::GetId() const
{
	return (int)GetMenu(GetHandle());
}
