#include "DialogWindow.h"
#include "../Utilities.h"

using namespace sowl;

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
    Utilities::OutputDebugWindowMessage(uMsg, L"DialogProc");

    DialogWindow* pDialogWindow;

    if (uMsg == WM_INITDIALOG)
    {
        pDialogWindow = reinterpret_cast<DialogWindow*>(lParam);
        pDialogWindow->BindToHandle(hwnd, (LONG_PTR)pDialogWindow);
    }
    else
    {
        LONG_PTR ptr = GetWindowLongPtr(hwnd, GWLP_USERDATA);
        pDialogWindow = reinterpret_cast<DialogWindow*>(ptr);
    }

    if (pDialogWindow != nullptr)
    {
        LRESULT result = pDialogWindow->Process(uMsg, wParam, lParam);

        if (uMsg == WM_NCDESTROY)
        {
            pDialogWindow->UnbindHandle();
        }

        return result;
    }

    return FALSE;
}
