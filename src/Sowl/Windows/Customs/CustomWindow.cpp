#include "CustomWindow.h"
#include "WindowClassRegisterer.h"
#include <windowsx.h>
#include "../Utilities.h"

using namespace sowl;

CustomWindow::CustomWindow(HINSTANCE processHandle, LPCWSTR className)
    : CustomWindow(ClassRegisterer(processHandle, className), WindowHandleCreator(processHandle, className))
{
}

CustomWindow::CustomWindow(const WindowHandleCreator& handleCreator)
    : CustomWindow(ClassRegisterer(handleCreator.ProcessHandle(), handleCreator.ClassName()), handleCreator)
{
}

sowl::CustomWindow::CustomWindow(const WindowClassRegisterer& classRegisterer)
    : CustomWindow(classRegisterer, WindowHandleCreator(classRegisterer.ProcessHandle(), classRegisterer.ClassName()))
{
}

CustomWindow::CustomWindow(const WindowClassRegisterer& classRegisterer, WindowHandleCreator handleCreator)
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

WindowClassRegisterer sowl::CustomWindow::ClassRegisterer(HINSTANCE processHandle, LPCWSTR className)
{
    return WindowClassRegisterer(processHandle, className, BindAndProcess);
}

auto extractor = [](LPARAM param) {
    auto* pCreate = reinterpret_cast<CREATESTRUCT*>(param);
    auto* pWindow = pCreate == nullptr ? nullptr : reinterpret_cast<CustomWindow*>(pCreate->lpCreateParams);
    return pWindow;
};

LRESULT CALLBACK CustomWindow::BindAndProcess(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    Utilities::OutputDebugWindowMessage(uMsg, L"CustomWindow::WindowProc");

    return WindowWithMessages::BindAndProcess(hwnd, uMsg, wParam, lParam, WM_CREATE, extractor);
}
