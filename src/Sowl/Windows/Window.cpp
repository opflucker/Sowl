#include "Window.h"
#include <utility>

using namespace sowl;

Window::Window()
    : hwnd(nullptr)
{
}

Window::Window(HWND hwnd)
    : hwnd(hwnd)
{
}

Window::Window(Window&& other) noexcept
    : hwnd(other.hwnd)
{
    other.hwnd = nullptr;
}

/// @brief Release the encapsulated HWND, if it is valid.
Window::~Window()
{
    Destroy();
}

/// @brief Release the encapsulated HWND if it is valid.
void Window::Destroy()
{
    if (IsWindow(hwnd))
    {
        DestroyWindow(hwnd);
        hwnd = nullptr;
    }
}

Window& sowl::Window::operator=(Window&& other) noexcept
{
    std::swap(hwnd, other.hwnd);
    return *this;
}

/// @brief Replace the encapsulated HWND by the one passed as parameter.
/// @param hwnd New handle to encapsulate.
void Window::BindToHandle(HWND newHandle)
{
    if (hwnd != nullptr)
        RaiseException(1, 0, 0, nullptr); // TODO: Improve this
    if (newHandle == nullptr)
        RaiseException(2, 0, 0, nullptr); // TODO: Improve this

    hwnd = newHandle;
}

void sowl::Window::UnbindHandle()
{
    hwnd = nullptr;
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
    SetClassLong(hwnd, GCLP_HCURSOR, (LONG)(intptr_t)hcursor);
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
    return ::InvalidateRect(hwnd, nullptr, erase);
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

/// @brief Encapsulates a call to ::ShowWindow.
/// @param nCmdShow Indicates how the window is to be shown.
/// @return Indicates if the window was previously visible.
bool Window::Show(int nCmdShow) const
{
    return ::ShowWindow(hwnd, nCmdShow);
}
