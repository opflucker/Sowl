#include "MainWindow.h"
#include "Resources.h"
#include <Sowl/Windows/MessageLoop.cpp>

const int SHOW_MODAL_ID = 101;

MainWindow::MainWindow(HINSTANCE processHandle)
    : CustomWindow(WindowHandleCreator(processHandle, L"MainWindow").WithTitle(L"Hello World!!!"))
{
    ButtonWindow::HandleCreator(*this, SHOW_MODAL_ID).WithTitle(L"Show Modal").WithRect(10, 10, 100, 30).Create();
}

void MainWindow::ProcessMessage(MSG& message)
{
    if (pModelessDialog == nullptr 
        || !IsWindow(pModelessDialog->GetHandle()) 
        || !IsDialogMessage(pModelessDialog->GetHandle(), &message))
    {
        MessageLoop::ProcessMessage(message);
    }
}

bool MainWindow::OnCommand(int notificationCode, int senderId, HWND controlHandle)
{
    switch (senderId)
    {
    case SHOW_MODAL_ID:
        pModelessDialog = std::make_unique<TestDialog>();
        pModelessDialog->CreateAndShow();
        return true;
    default:
        return false;
    }
}
