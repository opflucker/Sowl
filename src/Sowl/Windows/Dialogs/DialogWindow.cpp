#include "DialogWindow.h"
#include "../Utilities.h"

using namespace sowl;

LRESULT DialogWindow::Process(UINT uMsg, WPARAM wParam, LPARAM lParam)
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

auto extractor = [](LPARAM param) { return reinterpret_cast<DialogWindow*>(param); };

LRESULT CALLBACK DialogWindow::BindAndProcess(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    Utilities::OutputDebugWindowMessage(uMsg, L"DialogProc");

    return WindowWithMessages::BindAndProcess(hwnd, uMsg, wParam, lParam, WM_INITDIALOG, extractor);
}
