#include "WindowWithMessages.h"

using namespace sowl;

/// @brief Handles the binding between a Window-object and a window-handle.
/// @param hwnd 
/// @param uMsg 
/// @param wParam 
/// @param lParam 
/// @param bindingMessage The message where binding has to be set. Binding is always unset on WM_NCDESTROY.
/// @param extractWindowPointer A function that knows how extract a pointer to a Window-object passed as creation-parameter when the window was created.
/// @return 
LRESULT WindowWithMessages::BindAndProcess(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam,
    UINT bindingMessage,
    const std::function<WindowWithMessages* (LPARAM)>& extractWindowPointer)
{
    WindowWithMessages* pWindow;

    if (uMsg == bindingMessage)
    {
        pWindow = extractWindowPointer(lParam);
        if (pWindow != nullptr)
        {
            pWindow->SetHandle(hwnd);
            SetWindowLongPtr(hwnd, GWLP_USERDATA, (LONG_PTR)pWindow);
        }
    }
    else
    {
        LONG_PTR ptr = GetWindowLongPtr(hwnd, GWLP_USERDATA);
        pWindow = reinterpret_cast<WindowWithMessages*>(ptr);
    }

    if (pWindow == nullptr)
        return DefWindowProc(hwnd, uMsg, wParam, lParam);

    LRESULT result = pWindow->Process(uMsg, wParam, lParam);

    if (uMsg == WM_NCDESTROY)
    {
        SetWindowLongPtr(hwnd, GWLP_USERDATA, 0);
        pWindow->UnsetHandle();
    }

    return result;
}
