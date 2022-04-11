#include "WindowClassRegisterer.h"
#include "WindowMessageProcessor.h"
#include "../Utilities.h"

using namespace sowl;

/// @brief Initialize the builder with given parameters and defaults.
/// @param processHandle Handle of the process where the window class to be registered must belongs to.
/// @param className A valid window class name.
/// @param wndProc A pointer to the window procedure.
/// @return A builder. If parameters are valid, a call to Register() must return a valid registered window class.
WindowClassRegisterer::WindowClassRegisterer(HINSTANCE processHandle, LPCWSTR className)
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
    wc.lpfnWndProc = WindowProc;
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
WNDCLASS WindowClassRegisterer::Register() const
{
    WNDCLASS wcFound;
    if (GetClassInfo(wc.hInstance, wc.lpszClassName, &wcFound) == TRUE)
        return wcFound;

    RegisterClass(&wc);
    return wc;
}

void WindowClassRegisterer::EnsureRegistered(HINSTANCE processHandle, LPCWSTR className)
{
    WNDCLASS wcFound;
    if (GetClassInfo(processHandle, className, &wcFound) == TRUE)
        return;

    WindowClassRegisterer builder(processHandle, className);
    RegisterClass(&(builder.wc));
}

LRESULT CALLBACK WindowClassRegisterer::WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    wchar_t text[200];
    wsprintf(text, L"WndProc: msg = %x (%s)\n", uMsg, Utilities::GetWindowMessageText(uMsg));
    OutputDebugStringW(text);

    WindowMessageProcessor* pWindow;

    if (uMsg == WM_CREATE)
    {
        auto* pCreate = reinterpret_cast<CREATESTRUCT*>(lParam);
        pWindow = reinterpret_cast<WindowMessageProcessor*>(pCreate->lpCreateParams);
        SetWindowLongPtr(hwnd, GWLP_USERDATA, (LONG_PTR)pWindow);
    }
    else
    {
        LONG_PTR ptr = GetWindowLongPtr(hwnd, GWLP_USERDATA);
        pWindow = reinterpret_cast<WindowMessageProcessor*>(ptr);
    }

    if (pWindow != nullptr)
        return pWindow->Process(uMsg, wParam, lParam);

    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
