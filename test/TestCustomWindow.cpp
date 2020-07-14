#include "TestCustomWindow.h"
#include <StockBrushesHandles.h>
#include <PredefinedCursorHandles.h>
#include <SolidBrush.h>
#include <ModalDialogWindow.h>
#include "resource.h"

enum ControlIds
{
    SHOW_MODAL_ID = 101,
    SHOW_MODELESS_ID,
    TOGGLE_ID,
    CLOSE_ID
};

WindowHandleBuilder TestCustomWindow::CreateHandleBuilder(HINSTANCE processHandle)
{
    return WindowHandleBuilder(
        CreateClassBuilder(processHandle, L"MyWindow")
            .WithBackgroundBrush(StockBrushesHandles::LightGray())
            .WithCursor(PredefinedCursorHandles::Arrow())
            .Register());
}

TestCustomWindow::TestCustomWindow(HINSTANCE processHandle)
    : CustomWindow(CreateHandleBuilder(processHandle).WithTitle(L"Hello World!!!"))
{
    modelessDialog.SetParent(*this);
    showModalDialogButton = ButtonWindow::CreateHandleBuilder(*this, SHOW_MODAL_ID).WithTitle(L"Show Modal").WithRect(10, 10, 100, 30);
    showModelessDialogButton = ButtonWindow::CreateHandleBuilder(*this, SHOW_MODELESS_ID).WithTitle(L"Show Modeless").WithRect(10, 50, 100, 30);
    toggleButton = ButtonWindow::CreateHandleBuilder(*this, TOGGLE_ID).WithTitle(L"Toggle Hello").WithRect(10, 90, 100, 30);
    closeButton = ButtonWindow::CreateHandleBuilder(*this, CLOSE_ID).WithTitle(L"Close").WithRect(10, 130, 100, 30);
}

void TestCustomWindow::OnPaint(const PaintDeviceContext& dc)
{
    SolidBrush brush(RGB(200, 225, 255));
    dc.FillRect(brush.GetHandle());
}

bool TestCustomWindow::OnCommand(int notificationCode, int senderId, HWND controlHandle)
{
    switch (senderId)
    {
    case SHOW_MODAL_ID:
        {
            ModalDialogWindow dlg(*this, IDD_DIALOG1);
            dlg.CreateAndShow();
        }
        return true;
    case SHOW_MODELESS_ID:
        modelessDialog.CreateAndShow();
        return true;
    case TOGGLE_ID:
        showModalDialogButton.Enable(!showModalDialogButton.IsEnabled());
        showModalDialogButton.SetClassCursor(PredefinedCursorHandles::Cross());
        return true;
    case CLOSE_ID:
        Destroy();
        return true;
    default:
        return false;
    }
}
