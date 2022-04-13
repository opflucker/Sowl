#include "CustomWindow.h"
#include "CustomWindowClassRegisterer.h"
#include <windowsx.h>
#include "../Utilities.h"

using namespace sowl;

CustomWindow::CustomWindow(HINSTANCE processHandle, LPCWSTR className)
    : CustomWindow(CustomWindowClassRegisterer(processHandle, className), WindowHandleCreator(processHandle, className))
{
}

CustomWindow::CustomWindow(const WindowHandleCreator& handleCreator)
    : CustomWindow(CustomWindowClassRegisterer(handleCreator.ProcessHandle(), handleCreator.ClassName()), handleCreator)
{
}

sowl::CustomWindow::CustomWindow(const CustomWindowClassRegisterer& classRegisterer)
    : CustomWindow(classRegisterer, WindowHandleCreator(classRegisterer.ProcessHandle(), classRegisterer.ClassName()))
{
}

CustomWindow::CustomWindow(const CustomWindowClassRegisterer& classRegisterer, WindowHandleCreator handleCreator)
{
    classRegisterer.Register();
    handleCreator.WithParams(this).Create();
}

LRESULT CustomWindow::Process(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_SHOWWINDOW:
        if (OnShow((bool)wParam, (int)lParam))
            return 0;
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    case WM_PAINT:
        OnPaint(PaintDeviceContext(GetHandle()));
        return 0;
    case WM_COMMAND:
        if (OnCommand(HIWORD(wParam), LOWORD(wParam), (HWND)lParam))
            return 0;
        break;
    case WM_LBUTTONDOWN:
        if (OnLButtonDown((int)wParam, GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam)))
            return 0;
        break;
    default:
        break;
    }

    return DefWindowProc(GetHandle(), uMsg, wParam, lParam);
}

bool CustomWindow::OnShow(bool show, int showStatus)
{
    return true;
}

void CustomWindow::OnPaint(const PaintDeviceContext& dc)
{
}

bool CustomWindow::OnCommand(int notificationCode, int senderId, HWND controlHandle)
{
    return false;
}

bool CustomWindow::OnLButtonDown(int mouseKeys, int x, int y)
{
    return false;
}

LRESULT CALLBACK CustomWindow::WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    Utilities::OutputDebugWindowMessage(uMsg, L"CustomWindow::WindowProc");

    CustomWindow* pWindow;

    if (uMsg == WM_CREATE)
    {
        auto* pCreate = reinterpret_cast<CREATESTRUCT*>(lParam);
        pWindow = reinterpret_cast<CustomWindow*>(pCreate->lpCreateParams);
        pWindow->BindToHandle(hwnd, (LONG_PTR)pWindow);
    }
    else
    {
        LONG_PTR ptr = GetWindowLongPtr(hwnd, GWLP_USERDATA);
        pWindow = reinterpret_cast<CustomWindow*>(ptr);
    }

    if (pWindow != nullptr)
    {
        LRESULT result = pWindow->Process(uMsg, wParam, lParam);

        if (uMsg == WM_NCDESTROY)
        {
            pWindow->UnbindHandle();
        }

        return result;
    }

    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
