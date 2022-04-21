#include "WindowWithMessages.h"

using namespace sowl;

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
            pWindow->BindHandle(hwnd);
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
        pWindow->UnbindHandle();
    }

    return result;
}
