#include "WindowClass.h"
#include <wtypes.h>

WindowClass::WindowClass(HINSTANCE hInstance, LPCWSTR className, HBRUSH hbrush, HCURSOR hcursor, HICON hicon, LPCWSTR menuName, UINT style)
{
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hbrBackground = hbrush;
    wc.hCursor = hcursor;
    wc.hIcon = hicon;
    wc.lpszMenuName = menuName;
    wc.style = style;

    wc.hInstance = hInstance;
    wc.lpfnWndProc = WindowProc;
    wc.lpszClassName = className;

    wcAtom = RegisterClass(&wc);
}

WindowHandleBuilder WindowClass::CreateBuilder(MessageTarget* pMessageTarget) const
{
    return WindowHandleBuilder(wc.hInstance, wc.lpszClassName).WithParam(pMessageTarget);
}

LRESULT CALLBACK WindowClass::WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    MessageTarget* pMessageTarget;

    if (uMsg == WM_CREATE)
    {
        CREATESTRUCT* pCreate = reinterpret_cast<CREATESTRUCT*>(lParam);
        pMessageTarget = reinterpret_cast<MessageTarget*>(pCreate->lpCreateParams);
        SetWindowLongPtr(hwnd, GWLP_USERDATA, (LONG_PTR)pMessageTarget);
    }
    else
    {
        LONG_PTR ptr = GetWindowLongPtr(hwnd, GWLP_USERDATA);
        pMessageTarget = reinterpret_cast<MessageTarget*>(ptr);
    }

    if (pMessageTarget != NULL)
        return pMessageTarget->Process(uMsg, wParam, lParam);
    
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}