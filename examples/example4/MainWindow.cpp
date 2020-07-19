#include "MainWindow.h"
#include "Resources.h"
#include <Windows\MessageLoop.cpp>

enum ControlIds
{
    SHOW_MODAL_ID = 101
};

MainWindow::MainWindow(HINSTANCE processHandle)
    : CustomWindow(CreateHandleBuilder(processHandle, L"MainWindow").WithTitle(L"Hello World!!!"))
{
    modelessDialog.SetParent(*this);
    ButtonWindow::CreateHandleBuilder(*this, SHOW_MODAL_ID).WithTitle(L"Show Modal").WithRect(10, 10, 100, 30).Build();
}

void MainWindow::ProcessMessage(MSG& message)
{
    HWND dialogHandle = modelessDialog.GetHandle();
    if (!IsWindow(dialogHandle) || !IsDialogMessage(dialogHandle, &message))
    {
        MessageLoop::ProcessMessage(message);
    }
}

bool MainWindow::OnCommand(int notificationCode, int senderId, HWND controlHandle)
{
    switch (senderId)
    {
    case SHOW_MODAL_ID:
        if (modelessDialog.GetHandle() == NULL)
        {
            modelessDialog.CreateAndShow();
        }
        return true;
    default:
        return false;
    }
}
