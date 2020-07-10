#include "TestCustomWindow.h"
#include <StockObjects.h>
#include <PredefinedCursors.h>
#include <SolidBrush.h>
#include <ModalDialogWindow.h>
#include "resource.h"

WindowHandleBuilder TestCustomWindow::CreateHandleBuilder(HINSTANCE hInstance)
{
    return WindowHandleBuilder(
        CreateClassBuilder(hInstance, L"MyWindow")
            .WithBackgroundBrush(StockObjects::LightGrayBrushHandle())
            .WithCursor(PredefinedCursors::ArrowHandle())
            .Register());
}

TestCustomWindow::TestCustomWindow(HINSTANCE hInstance)
    : CustomWindow(CreateHandleBuilder(hInstance).WithTitle(L"Hello World!!!"))
    , showModalDialogButton(ButtonWindow::CreateHandleBuilder(*this, 101).WithTitle(L"Show Modal").WithRect(10, 10, 100, 30))
    , showModelessDialogButton(ButtonWindow::CreateHandleBuilder(*this, 102).WithTitle(L"Show Modeless").WithRect(10, 50, 100, 30))
    , toggleButton(ButtonWindow::CreateHandleBuilder(*this, 103).WithTitle(L"Toggle Hello").WithRect(10, 90, 100, 30))
    , closeButton(ButtonWindow::CreateHandleBuilder(*this, 104).WithTitle(L"Close").WithRect(10, 130, 100, 30))
    , modelessDialog(*this)
{
}

void TestCustomWindow::OnPaint(const PaintDeviceContext& dc)
{
    SolidBrush brush(RGB(200, 225, 255));
    dc.FillRect(brush.GetHandle());
}

bool TestCustomWindow::OnCommand(int notificationCode, int senderId, HWND controlHandle)
{
    if (senderId == showModalDialogButton.GetId())
    {
        ModalDialogWindow dlg(*this, IDD_DIALOG1);
        dlg.ShowModal();
        return true;
    }
    if (senderId == showModelessDialogButton.GetId())
    {
        modelessDialog.ShowModeless();
        return true;
    }
    if (senderId == toggleButton.GetId())
    {
        showModalDialogButton.Enable(!showModalDialogButton.IsEnabled());
        showModalDialogButton.SetClassCursor(PredefinedCursors::CrossHandle());
        return true;
    }
    if (senderId == closeButton.GetId())
    {
        Destroy();
        return true;
    }
    return false;
}
