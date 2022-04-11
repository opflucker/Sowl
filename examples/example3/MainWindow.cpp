#include "MainWindow.h"
#include "TestDialog.h"
#include "Resources.h"

using namespace sowl;

const int SHOW_MODAL_1_ID = 101;
const int SHOW_MODAL_2_ID = 102;

MainWindow::MainWindow(HINSTANCE processHandle)
    : CustomWindow(WindowHandleCreator(processHandle, L"MainWindow").WithTitle(L"Hello World!!!"))
{
    ButtonWindow::HandleCreator(*this, SHOW_MODAL_1_ID).WithTitle(L"Show Modal 1").WithRect(10, 10, 100, 30).Create();
    ButtonWindow::HandleCreator(*this, SHOW_MODAL_2_ID).WithTitle(L"Show Modal 2").WithRect(10, 50, 100, 30).Create();
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
