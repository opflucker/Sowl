#include "TestCustomWindow.h"
#include <StockObjects.h>
#include <PredefinedCursors.h>
#include <SolidBrush.h>
#include "TestDialog.h"

WindowClassRegistered TestCustomWindow::RegisterClass(HINSTANCE hInstance)
{
    return WindowClassRegistered(
        CreateClassBuilder(hInstance, L"MyWindow")
        .WithBackgroundBrush(StockObjects::LightGrayBrushHandle())
        .WithCursor(PredefinedCursors::ArrowHandle())
        .Result());
}

TestCustomWindow::TestCustomWindow(HINSTANCE hInstance)
    : CustomWindow(RegisterClass(hInstance).CreateHandleBuilder().WithTitle(L"Hello World!!!"))
    , helloButton(ButtonWindow::CreateHandleBuilder(*this, 101).WithTitle(L"Hello").WithRect(10, 10, 100, 30))
    , toggleButton(ButtonWindow::CreateHandleBuilder(*this, 102).WithTitle(L"Toggle Hello").WithRect(10, 50, 100, 30))
    , closeButton(ButtonWindow::CreateHandleBuilder(*this, 103).WithTitle(L"Close").WithRect(10, 90, 100, 30))
{
}

void TestCustomWindow::OnPaint(const PaintDeviceContext& dc)
{
    SolidBrush brush(RGB(200, 225, 255));
    dc.FillRect(brush.GetHandle());
}

bool TestCustomWindow::OnCommand(int notificationCode, int senderId, HWND controlHandle)
{
    if (senderId == helloButton.GetId())
    {
        TestDialog dlg(*this);
        dlg.ShowModal();
        return true;
    }
    if (senderId == toggleButton.GetId())
    {
        helloButton.Enable(!helloButton.IsEnabled());
        helloButton.SetClassCursor(PredefinedCursors::CrossHandle());
        return true;
    }
    if (senderId == closeButton.GetId())
    {
        Destroy();
        return true;
    }
    return false;
}
