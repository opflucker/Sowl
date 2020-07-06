#include "Window.h"

Window::Window(HWND hwnd, bool ensureDestroy)
{
    this->hwnd = hwnd;
    this->ensureDestroy = ensureDestroy;
}

Window::~Window()
{
    if (ensureDestroy)
    {
        Destroy();
    }
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
    if (IsWindow(hwnd))
    {
        DestroyWindow(hwnd);
        hwnd = NULL;
    }
}
