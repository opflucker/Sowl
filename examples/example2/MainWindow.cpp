#include "MainWindow.h"
#include <StockBrushesHandles.h>
#include <PredefinedCursorHandles.h>
#include <SolidBrush.h>
#include <ModalDialogWindow.h>

enum ControlIds
{
    SHOW_MESSAGE_ID,
    CLOSE_ID
};

WindowHandleBuilder MainWindow::CreateHandleBuilder(HINSTANCE processHandle)
{
    return WindowHandleBuilder(CreateClassBuilder(processHandle, L"MyWindow").Register());
}

MainWindow::MainWindow(HINSTANCE processHandle)
    : CustomWindow(CreateHandleBuilder(processHandle).WithTitle(L"Hello World!!!"))
{
    showMessageButton = ButtonWindow::CreateHandleBuilder(*this, SHOW_MESSAGE_ID).WithTitle(L"Show Message").WithRect(10, 10, 150, 30);
    closeButton = ButtonWindow::CreateHandleBuilder(*this, CLOSE_ID).WithTitle(L"Close").WithRect(10, 50, 150, 30);
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
