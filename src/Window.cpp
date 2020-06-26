#include "Window.h"

Window::Window(WindowClass & wc, LPCWSTR title)
{
    hwnd = wc.CreateBuilder(this).WithTitle(title).Build();
}

bool Window::IsCreated()
{
    return hwnd != NULL;
}

bool Window::Show(int nCmdShow)
{
    return ::ShowWindow(hwnd, nCmdShow);
}

LRESULT Window::Process(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
        case WM_PAINT:
            {
                PAINTSTRUCT ps;
                HDC hdc = BeginPaint(hwnd, &ps);
                FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));
                EndPaint(hwnd, &ps);
            }
            return 0;
    }

    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
