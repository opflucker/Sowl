#include "CustomWindow.h"

CustomWindow::CustomWindow(WindowHandleBuilder builder)
    : Window(NULL, true)
{
    // Can not be done when calling base class constructor because "this" is invalid there
    SetHandle(builder.WithParam(this).Build());
}

bool CustomWindow::Show(int nCmdShow) const
{
    return ::ShowWindow(GetHandle(), nCmdShow);
}

LRESULT CustomWindow::Process(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_DESTROY:
        SetHandle(NULL);
        PostQuitMessage(0);
        return 0;
    case WM_PAINT:
        OnPaint(PaintDeviceContext(GetHandle()));
        return 0;
    case WM_COMMAND:
        if (OnCommand(HIWORD(wParam), LOWORD(wParam), (HWND)lParam))
            return 0;
        break;
    }

    return DefWindowProc(GetHandle(), uMsg, wParam, lParam);
}

void CustomWindow::OnPaint(const PaintDeviceContext& dc)
{
}

bool CustomWindow::OnCommand(int notificationCode, int senderId, HWND controlHandle)
{
    return false;
}
