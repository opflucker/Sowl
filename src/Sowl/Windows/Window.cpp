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

/// @brief Release the encapsulated HWND, if it is valid.
Window::~Window()
{
    Destroy();
}

HWND Window::GetHandle() const
{
    return hwnd;
}

/// @brief Get the process handle (HINSTANCE) where the encapsulated handle window belongs to.
/// @return The process handle.
HINSTANCE Window::GetProcessHandle() const
{
    return (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE);
}

/// @brief Encapsulates a call to ::GetDlgItem.
/// @param id Control id.
/// @return Control handle.
HWND Window::GetDialogItem(int id) const
{
    return GetDlgItem(hwnd, id);
}

/// @brief Replace the encapsulated HWND by the one passed as parameter.
/// @param hwnd New handle to encapsulate.
/// @return The old encapsulated handle.
HWND Window::SetHandle(HWND hwnd)
{
    HWND oldHandle = this->hwnd;
    this->hwnd = hwnd;
    return oldHandle;
}

/// @brief Encapsulates a call to ::EnableWindow.
/// @param Indicates whether to enable or disable the window.
void Window::Enable(bool enable)
{
    EnableWindow(hwnd, enable);
}

/// @brief Encapsulates a call to ::IsWindowEnabled.
/// @return Indicates if the window is enabled.
bool Window::IsEnabled()
{
    return IsWindowEnabled(hwnd);
}

/// @brief Encapsulates a call to ::SetClassLong with index GCL_HCURSOR.
/// @param hcursor The cursor to be set. 
void Window::SetClassCursor(HCURSOR hcursor)
{
    SetClassLong(hwnd, GCL_HCURSOR, (LONG)hcursor);
}

/// @brief Encapsulates a call to ::SetWindowText.
/// @param title The window title to be set.
void Window::SetText(LPCWSTR title)
{
    ::SetWindowText(hwnd, title);
}

/// @brief Encapsulates a call to ::InvalidateRect with lpRect to NULL.
/// @param erase Indicates the invalidated area should be erased (using the window class brush) before be repainted.
/// @return Indicates if the method call was successful.
bool Window::InvalidateRect(bool erase)
{
    return ::InvalidateRect(hwnd, NULL, erase);
}

/// @brief Encapsulates a call to ::InvalidateRect.
/// @param rect Area to be invalidated.
/// @param erase Indicates the invalidated area should be erased (using the window class brush) before be repainted.
/// @return Indicates if the method call was successful.
bool Window::InvalidateRect(const RECT& rect, bool erase)
{
    return ::InvalidateRect(hwnd, &rect, erase);
}

/// @brief Encapsulates a call to ::GetClientRect.
/// @return The client rect area.
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

/// @brief Release the encapsulated HWND if it is valid.
void Window::Destroy()
{
    if (IsWindow(hwnd))
    {
        DestroyWindow(hwnd);
        hwnd = NULL;
    }
}

/// @brief Encapsulates a call to ::ShowWindow.
/// @param nCmdShow Indicates how the window is to be shown.
/// @return Indicates if the window was previously visible.
bool Window::Show(int nCmdShow) const
{
    return ::ShowWindow(GetHandle(), nCmdShow);
}
