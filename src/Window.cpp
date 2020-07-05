#include "Window.h"

Window::Window(HWND hwnd)
{
    this->hwnd = hwnd;
}

HWND Window::GetHandle() const
{
    return hwnd;
}

HINSTANCE Window::GetInstanceHandle() const
{
    return (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE);
}

void Window::SetHandle(HWND hwnd)
{
    this->hwnd = hwnd;
}

void Window::Enable(bool enable)
{
    EnableWindow(hwnd, enable);
}

bool Window::IsEnabled()
{
    return IsWindowEnabled(hwnd);
}

void Window::SetClassCursor(HCURSOR hcursor)
{
    SetClassLong(hwnd, GCL_HCURSOR, (LONG)hcursor);
}

void Window::Destroy()
{
    DestroyWindow(hwnd);
}
