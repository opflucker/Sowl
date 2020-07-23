#include "Window.h"

using namespace sowl;

Window::Window(HWND hwnd)
{
    this->hwnd = hwnd;
}

Window::Window(Window&& other) noexcept
{
    hwnd = other.SetHandle(NULL);
}

Window::~Window()
{
    Destroy();
}

HWND Window::GetHandle() const
{
    return hwnd;
}

HINSTANCE Window::GetProcessHandle() const
{
    return (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE);
}

HWND Window::GetDialogItem(int id) const
{
    return GetDlgItem(hwnd, id);
}

HWND Window::SetHandle(HWND hwnd)
{
    HWND oldHandle = this->hwnd;
    this->hwnd = hwnd;
    return oldHandle;
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

void Window::SetText(LPCWSTR title)
{
    ::SetWindowText(hwnd, title);
}

bool Window::InvalidateRect(bool erase)
{
    return ::InvalidateRect(hwnd, NULL, erase);
}

bool Window::InvalidateRect(const RECT& rect, bool erase)
{
    return ::InvalidateRect(hwnd, &rect, erase);
}

RECT Window::GetClientRect()
{
    RECT rect;
    ::GetClientRect(hwnd, &rect);
    return rect;
}

Window& Window::operator=(Window&& other) noexcept
{
    hwnd = other.SetHandle(NULL);
    return *this;
}

void Window::Destroy()
{
    if (IsWindow(hwnd))
    {
        DestroyWindow(hwnd);
        hwnd = NULL;
    }
}

bool Window::Show(int nCmdShow) const
{
    return ::ShowWindow(GetHandle(), nCmdShow);
}
