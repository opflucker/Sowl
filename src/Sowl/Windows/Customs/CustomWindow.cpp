#include "CustomWindow.h"
#include "WindowClassRegisterer.h"
#include <windowsx.h>

using namespace sowl;

CustomWindow::CustomWindow(HINSTANCE processHandle, LPCWSTR className)
{
    WindowClassRegisterer::EnsureRegistered(processHandle, className);
    SetHandle(WindowHandleCreator(processHandle, className).WithParams(this).Create());
}

CustomWindow::CustomWindow(WindowHandleCreator& builder)
{
    WindowClassRegisterer::EnsureRegistered(builder.ProcessHandle(), builder.ClassName());
    SetHandle(builder.WithParams(this).Create());
}

LRESULT CustomWindow::Process(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_SHOWWINDOW:
        if (OnShow((bool)wParam, (int)lParam))
            return 0;
        break;
    case WM_DESTROY:
        SetHandle(nullptr);
        PostQuitMessage(0);
        return 0;
    case WM_PAINT:
        OnPaint(PaintDeviceContext(GetHandle()));
        return 0;
    case WM_COMMAND:
        if (OnCommand(HIWORD(wParam), LOWORD(wParam), (HWND)lParam))
            return 0;
        break;
    case WM_LBUTTONDOWN:
        if (OnLButtonDown((int)wParam, GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam)))
            return 0;
        break;
    default:
        break;
    }

    return DefWindowProc(GetHandle(), uMsg, wParam, lParam);
}

bool CustomWindow::OnShow(bool show, int showStatus)
{
    return true;
}

void CustomWindow::OnPaint(const PaintDeviceContext& dc)
{
}

bool CustomWindow::OnCommand(int notificationCode, int senderId, HWND controlHandle)
{
    return false;
}

bool CustomWindow::OnLButtonDown(int mouseKeys, int x, int y)
{
    return false;
}
