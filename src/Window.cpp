#include "Window.h"
#include "PaintDeviceContext.h"
#include "StockObjects.h"

Window::Window(WindowClass & wc, LPCWSTR title)
{
    hwnd = wc.CreateBuilder(this).WithTitle(title).Build();
}

bool Window::IsCreated() const
{
    return hwnd != NULL;
}

bool Window::Show(int nCmdShow) const
{
    return ::ShowWindow(hwnd, nCmdShow);
}

LRESULT Window::Process(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
        case WM_PAINT:
            OnPaint(PaintDeviceContext(hwnd));
            return 0;
    }

    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

void Window::OnPaint(const PaintDeviceContext& dc)
{
}
