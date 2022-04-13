#include "CustomWindowClassRegisterer.h"
#include "CustomWindow.h"

using namespace sowl;

/// @brief Initialize the builder with given parameters and defaults.
/// @param processHandle Handle of the process where the window class to be registered must belongs to.
/// @param className A valid window class name.
/// @param wndProc A pointer to the window procedure.
/// @return A builder. If parameters are valid, a call to Register() must return a valid registered window class.
CustomWindowClassRegisterer::CustomWindowClassRegisterer(HINSTANCE processHandle, LPCWSTR className)
{
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hbrBackground = nullptr;
    wc.hCursor = nullptr;
    wc.hIcon = nullptr;
    wc.lpszClassName = className;
    wc.lpszMenuName = nullptr;
    wc.style = 0;
    wc.hInstance = processHandle;
    wc.lpfnWndProc = CustomWindow::WindowProc;
}

HINSTANCE sowl::CustomWindowClassRegisterer::ProcessHandle() const
{
    return wc.hInstance;
}

LPCWSTR sowl::CustomWindowClassRegisterer::ClassName() const
{
    return wc.lpszClassName;
}

CustomWindowClassRegisterer& CustomWindowClassRegisterer::WithBackgroundBrush(HBRUSH handle)
{
    wc.hbrBackground = handle;
    return *this;
}

CustomWindowClassRegisterer& CustomWindowClassRegisterer::WithCursor(HCURSOR handle)
{
    wc.hCursor = handle;
    return *this;
}

CustomWindowClassRegisterer& CustomWindowClassRegisterer::WithIcon(HICON handle)
{
    wc.hCursor = handle;
    return *this;
}

CustomWindowClassRegisterer& CustomWindowClassRegisterer::WithMenu(LPCWSTR name)
{
    wc.lpszMenuName = name;
    return *this;
}

CustomWindowClassRegisterer& CustomWindowClassRegisterer::WithStyle(UINT style)
{
    wc.style = style;
    return *this;
}

/// @brief If the class was not registered, register it. Otherwise, retrieve the registered class information.
/// @return Structure with information about the registered class.
WNDCLASS CustomWindowClassRegisterer::Register() const
{
    WNDCLASS wcFound;
    if (GetClassInfo(wc.hInstance, wc.lpszClassName, &wcFound) == TRUE)
        return wcFound;

    RegisterClass(&wc);
    return wc;
}
