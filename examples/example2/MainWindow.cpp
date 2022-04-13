#include "MainWindow.h"

using namespace sowl;

const int SHOW_MESSAGE_ID = 100;
const int CLOSE_ID = 101;

MainWindow::MainWindow(HINSTANCE processHandle)
    : CustomWindow(WindowHandleCreator(processHandle, L"MainWindow").WithTitle(L"Hello World!!!"))
{
    showMessageButton = ButtonWindow::Creator(*this, SHOW_MESSAGE_ID).WithTitle(L"Show Message").WithRect(10, 10, 150, 30).Create();
    closeButton = ButtonWindow::Creator(*this, CLOSE_ID).WithTitle(L"Close").WithRect(10, 50, 150, 30).Create();
}

bool MainWindow::OnCommand(int notificationCode, int senderId, HWND controlHandle)
{
    switch (senderId)
    {
    case SHOW_MESSAGE_ID:
        MessageBox(GetHandle(), L"Hello", L"Message", MB_OK);
        return true;
    case CLOSE_ID:
        Destroy();
        return true;
    default:
        return false;
    }
}
