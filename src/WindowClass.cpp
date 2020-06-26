#include "WindowClass.h"
#include <wtypes.h>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

WindowClass::WindowClass(HINSTANCE hInstance, LPCWSTR className)
{
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hbrBackground = NULL;
    wc.hCursor = NULL;
    wc.hIcon = NULL;
    wc.lpszMenuName = NULL;
    wc.style = 0;

    wc.hInstance = hInstance;
    wc.lpfnWndProc = WindowProc;
    wc.lpszClassName = className;

    wcAtom = RegisterClass(&wc);
}

WindowBuilder WindowClass::CreateBuilder(MessageTarget* pMessageTarget) const
{
    return WindowBuilder(wc.hInstance, wc.lpszClassName).WithParam(pMessageTarget);
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
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