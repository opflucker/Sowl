#include "WindowHandleCreator.h"

using namespace sowl;

/// @brief Initialize the builder with given parameters and defaults.
/// @param processHandle Handle of the process where the window to be created must belongs to.
/// @param className Name of a valid registered window class.
/// @return A builder. If parameters are valid, an inmediate call to Build() must return a valid created window.
WindowHandleCreator::WindowHandleCreator(HINSTANCE processHandle, LPCWSTR className)
{
    cp.lpszClass = className;
    cp.lpszName = L"";
    cp.style = WS_OVERLAPPEDWINDOW;
    cp.x = CW_USEDEFAULT;
    cp.y = CW_USEDEFAULT;
    cp.cx = CW_USEDEFAULT;
    cp.cy = CW_USEDEFAULT;
    cp.hwndParent = nullptr;
    cp.hMenu = nullptr;
    cp.hInstance = processHandle;
    cp.lpCreateParams = nullptr;
}

HINSTANCE WindowHandleCreator::ProcessHandle() const
{
    return cp.hInstance;
}

LPCWSTR WindowHandleCreator::ClassName() const
{
    return cp.lpszClass;
}

WindowHandleCreator& WindowHandleCreator::WithTitle(LPCWSTR title)
{
    cp.lpszName = title;
    return *this;
}

WindowHandleCreator& WindowHandleCreator::WithStyle(DWORD style)
{
    cp.style = style;
    return *this;
}

WindowHandleCreator& WindowHandleCreator::AndStyle(DWORD style)
{
    cp.style |= style;
    return *this;
}

WindowHandleCreator& WindowHandleCreator::WithRect(int x, int y, int width, int height)
{
    cp.x = x;
    cp.y = y;
    cp.cx = width;
    cp.cy = height;
    return *this;
}

WindowHandleCreator& WindowHandleCreator::WithParent(HWND hParentWindow)
{
    cp.hwndParent = hParentWindow;
    return *this;
}

WindowHandleCreator& WindowHandleCreator::WithMenu(HMENU hMenu)
{
    cp.hMenu = hMenu;
    return *this;
}

WindowHandleCreator& WindowHandleCreator::WithParams(LPVOID lpCreateParams)
{
    cp.lpCreateParams = lpCreateParams;
    return *this;
}

HWND WindowHandleCreator::Create() const
{
    return CreateWindowEx(
        0, // Optional window styles.
        cp.lpszClass,
        cp.lpszName,
        cp.style,
        cp.x, cp.y, cp.cx, cp.cy,
        cp.hwndParent,
        cp.hMenu,
        cp.hInstance, // Instance handle
        cp.lpCreateParams // Additional application data
    );
}
