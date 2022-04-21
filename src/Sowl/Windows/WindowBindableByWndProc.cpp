#include "WindowBindableByWndProc.h"

using namespace sowl;

LRESULT WindowBindableByWndProc::WindowProcedure(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam,
    UINT messageWhereBind,
    const std::function<WindowBindableByWndProc* (LPARAM)>& extractWindowPointer)
{
    WindowBindableByWndProc* pWindow;

    if (uMsg == messageWhereBind)
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
        pWindow = reinterpret_cast<WindowBindableByWndProc*>(ptr);
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
