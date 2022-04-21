#include "WindowClassRegisterer.h"

using namespace sowl;

/// @brief Initialize the builder with given parameters and defaults.
/// @param processHandle Handle of the process where the window class to be registered must belongs to.
/// @param className A valid window class name.
/// @param windowProcedure A pointer to the window procedure.
/// @return A builder. If parameters are valid, a call to Register() must return a valid registered window class.
WindowClassRegisterer::WindowClassRegisterer(HINSTANCE processHandle, LPCWSTR className, WNDPROC windowProcedure)
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
    wc.lpfnWndProc = windowProcedure;
}

HINSTANCE sowl::WindowClassRegisterer::ProcessHandle() const
{
    return wc.hInstance;
}

LPCWSTR sowl::WindowClassRegisterer::ClassName() const
{
    return wc.lpszClassName;
}

WindowClassRegisterer& WindowClassRegisterer::WithBackgroundBrush(HBRUSH handle)
{
    wc.hbrBackground = handle;
    return *this;
}

WindowClassRegisterer& WindowClassRegisterer::WithCursor(HCURSOR handle)
{
    wc.hCursor = handle;
    return *this;
}

WindowClassRegisterer& WindowClassRegisterer::WithIcon(HICON handle)
{
    wc.hCursor = handle;
    return *this;
}

WindowClassRegisterer& WindowClassRegisterer::WithMenu(LPCWSTR name)
{
    wc.lpszMenuName = name;
    return *this;
}

WindowClassRegisterer& WindowClassRegisterer::WithStyle(UINT style)
{
    wc.style = style;
    return *this;
}

/// @brief If the class was not registered, register it. Otherwise, retrieve the registered class information.
/// @return Structure with information about the registered class.
void WindowClassRegisterer::Register() const
{
    WNDCLASS wcFound;
    if (GetClassInfo(wc.hInstance, wc.lpszClassName, &wcFound) == TRUE)
        return;

    RegisterClass(&wc);
}
