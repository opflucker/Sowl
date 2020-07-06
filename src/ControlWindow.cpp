#include "ControlWindow.h"

WindowHandleBuilder ControlWindow::CreateHandleBuilder(const Window& parentWindow, LPCWSTR className, WORD id)
{
    return WindowHandleBuilder(parentWindow.GetInstanceHandle(), className)
        .WithParent(parentWindow.GetHandle())
        .WithMenu((HMENU)id)
        .WithStyle(WS_TABSTOP | WS_VISIBLE | WS_CHILD);
}

ControlWindow::ControlWindow(WindowHandleBuilder builder)
    : Window(builder.Build(), true)
{
    // TODO: Assert "id" is in [8, 0xDFFF]
}

ControlWindow::ControlWindow()
    : Window(NULL, false)
{
}

void ControlWindow::Attach(const Window& parentWindow, WORD id)
{
    SetHandle(GetDlgItem(parentWindow.GetHandle(), id));
}

int ControlWindow::GetId() const
{
	return (int)GetMenu(GetHandle());
}
