#include "WindowClassBuilder.h"

using namespace sowl;

/// @brief Initialize the builder with given parameters and defaults.
/// @param processHandle Handle of the process where the window class to be registered must belongs to.
/// @param className A valid window class name.
/// @param wndProc A pointer to the window procedure.
/// @return A builder. If parameters are valid, a call to Register() must return a valid registered window class.
WindowClassBuilder::WindowClassBuilder(HINSTANCE processHandle, LPCWSTR className, WNDPROC wndProc)
{
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hbrBackground = NULL;
    wc.hCursor = NULL;
    wc.hIcon = NULL;
    wc.lpszClassName = className;
    wc.lpszMenuName = NULL;
    wc.style = 0;
    wc.hInstance = processHandle;
    wc.lpfnWndProc = wndProc;
}

WindowClassBuilder& WindowClassBuilder::WithBackgroundBrush(HBRUSH handle)
{
    wc.hbrBackground = handle;
    return *this;
}

WindowClassBuilder& WindowClassBuilder::WithCursor(HCURSOR handle)
{
    wc.hCursor = handle;
    return *this;
}

WindowClassBuilder& WindowClassBuilder::WithIcon(HICON handle)
{
    wc.hCursor = handle;
    return *this;
}

WindowClassBuilder& WindowClassBuilder::WithMenu(LPCWSTR name)
{
    wc.lpszMenuName = name;
    return *this;
}

WindowClassBuilder& WindowClassBuilder::WithStyle(UINT style)
{
    wc.style = style;
    return *this;
}

/// @brief If the class was not registered, register it. Otherwise, retrieve the registered class information.
/// @return Structure with information about the registered class.
WNDCLASS WindowClassBuilder::Register() const
{
    WNDCLASS wcFound;
    if (GetClassInfo(wc.hInstance, wc.lpszClassName, &wcFound) == FALSE)
        RegisterClass(&wc);

    return wc;
}

/// @brief Calls to Register(), creates a WindowHandleBuilder using the registered class and returns it. 
/// @return A WindowHandleBuilder object.
WindowHandleBuilder WindowClassBuilder::RegisterAndCreateHandleBuilder() const
{
    Register();
    return WindowHandleBuilder(wc.hInstance, wc.lpszClassName);
}
