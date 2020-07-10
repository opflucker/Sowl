#include "CustomWindow.h"

LRESULT CALLBACK CustomWindow::WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    CustomWindow* pWindow;

    if (uMsg == WM_CREATE)
    {
        CREATESTRUCT* pCreate = reinterpret_cast<CREATESTRUCT*>(lParam);
        pWindow = reinterpret_cast<CustomWindow*>(pCreate->lpCreateParams);
        SetWindowLongPtr(hwnd, GWLP_USERDATA, (LONG_PTR)pWindow);
    }
    else
    {
        LONG_PTR ptr = GetWindowLongPtr(hwnd, GWLP_USERDATA);
        pWindow = reinterpret_cast<CustomWindow*>(ptr);
    }

    if (pWindow != NULL)
        return pWindow->Process(uMsg, wParam, lParam);

    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

WindowClassBuilder CustomWindow::CreateClassBuilder(HINSTANCE hInstance, LPCWSTR className)
{
    return WindowClassBuilder(hInstance, className, WindowProc);
}

CustomWindow::CustomWindow(WindowHandleBuilder builder)
    : Window(NULL)
{
    // Can not be done when calling base class constructor because "this" is invalid there
    SetHandle(builder.WithParam(this).Build());
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
