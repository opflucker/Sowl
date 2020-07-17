#include "MainWindow.h"
#include "TestDialog.h"
#include "Resources.h"

enum ControlIds
{
    SHOW_MODAL_1_ID = 101,
    SHOW_MODAL_2_ID
};

WindowHandleBuilder MainWindow::CreateHandleBuilder(HINSTANCE processHandle)
{
    return WindowHandleBuilder(CreateClassBuilder(processHandle, L"MyWindow").Register());
}

MainWindow::MainWindow(HINSTANCE processHandle)
    : CustomWindow(CreateHandleBuilder(processHandle).WithTitle(L"Hello World!!!"))
{
    ButtonWindow::CreateHandleBuilder(*this, SHOW_MODAL_1_ID).WithTitle(L"Show Modal 1").WithRect(10, 10, 100, 30).Build();
    ButtonWindow::CreateHandleBuilder(*this, SHOW_MODAL_2_ID).WithTitle(L"Show Modal 2").WithRect(10, 50, 100, 30).Build();
}

bool MainWindow::OnCommand(int notificationCode, int senderId, HWND controlHandle)
{
    switch (senderId)
    {
    case SHOW_MODAL_1_ID:
        ModalDialogWindow(*this, IDD_DIALOG1).CreateAndShow();
        return true;
    case SHOW_MODAL_2_ID:
        TestDialog(*this).CreateAndShow();
        return true;
    default:
        return false;
    }
}
