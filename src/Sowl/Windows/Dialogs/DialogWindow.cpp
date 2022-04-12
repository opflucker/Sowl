#include "DialogWindow.h"

using namespace sowl;

DialogWindow::DialogWindow(int resourceId)
    : Window(nullptr), templateName(MAKEINTRESOURCE(resourceId))
{
}

DialogWindow::DialogWindow(const Window& parentWindow, int resourceId)
    : Window(nullptr), processHandle(parentWindow.GetProcessHandle())
    , parentHandle(parentWindow.GetHandle())
    , templateName(MAKEINTRESOURCE(resourceId))
{
}

int DialogWindow::CreateAndShowModal()
{
    if (GetHandle() == nullptr)
    {
        return (int)::DialogBoxParam(processHandle, templateName, parentHandle, DialogProc, (LPARAM)this);
    }
    return 0;
}

void DialogWindow::CreateModeless()
{
    if (GetHandle() == nullptr)
    {
        CreateDialogParam(processHandle, templateName, parentHandle, DialogProc, (LPARAM)this);
    }
}

bool DialogWindow::Process(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_INITDIALOG:
        return OnInitDialog((HWND)wParam);
    case WM_COMMAND:
        return OnCommand(HIWORD(wParam), LOWORD(wParam), (HWND)lParam);
    case WM_CLOSE:
        return OnClose();
    default:
        break;
    }
    return false;
}

bool DialogWindow::OnInitDialog(HWND hFocusWindow)
{
    return false;
}

bool DialogWindow::OnCommand(int notificationCode, int senderId, HWND controlHandle)
{
    return false;
}

INT_PTR DialogWindow::DialogProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    DialogWindow* pDialogWindow;

    if (uMsg == WM_INITDIALOG)
    {
        pDialogWindow = reinterpret_cast<DialogWindow*>(lParam);
        pDialogWindow->BindToHandle(hwnd);
        SetWindowLongPtr(hwnd, GWLP_USERDATA, (LONG_PTR)pDialogWindow);
    }
    else
    {
        LONG_PTR ptr = GetWindowLongPtr(hwnd, GWLP_USERDATA);
        pDialogWindow = reinterpret_cast<DialogWindow*>(ptr);
    }

    if (pDialogWindow != nullptr)
        return pDialogWindow->Process(uMsg, wParam, lParam);

    return FALSE;
}
