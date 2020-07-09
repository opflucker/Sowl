#include "DialogWindow.h"

DialogWindow::DialogWindow(const Window& parentWindow, int resourceId)
    : Window(NULL)
{
    hInstance = parentWindow.GetInstanceHandle();
    templateName = MAKEINTRESOURCE(resourceId);
    hParentWindow = parentWindow.GetHandle();
}

int DialogWindow::CreateAndShowModal()
{
    return ::DialogBoxParam(hInstance, templateName, hParentWindow, DialogProc, (LPARAM)this);
}

HWND DialogWindow::CreateAndShowModeless()
{
    return CreateDialogParam(hInstance, templateName, hParentWindow, DialogProc, (LPARAM)this);
}

BOOL DialogWindow::Process(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_INITDIALOG:
        return OnInitDialog((HWND)wParam);
    case WM_COMMAND:
        return OnCommand(HIWORD(wParam), LOWORD(wParam), (HWND)lParam);
    case WM_CLOSE:
        return OnClose();
    }
    return FALSE;
}

BOOL DialogWindow::OnInitDialog(HWND hFocusWindow)
{
    return TRUE;
}

BOOL DialogWindow::OnCommand(int notificationCode, int senderId, HWND controlHandle)
{
    return FALSE;
}

BOOL DialogWindow::DialogProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    DialogWindow* pDialogWindow;

    if (uMsg == WM_INITDIALOG)
    {
        pDialogWindow = reinterpret_cast<DialogWindow*>(lParam);
        pDialogWindow->SetHandle(hwnd);
        SetWindowLongPtr(hwnd, GWLP_USERDATA, (LONG_PTR)pDialogWindow);
    }
    else
    {
        LONG_PTR ptr = GetWindowLongPtr(hwnd, GWLP_USERDATA);
        pDialogWindow = reinterpret_cast<DialogWindow*>(ptr);
    }

    if (pDialogWindow != NULL)
        return pDialogWindow->Process(uMsg, wParam, lParam);

    return FALSE;
}
