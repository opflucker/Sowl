#ifndef UNICODE
#define UNICODE
#endif 

#include <windows.h>
#include "WindowClassBuilder.h"
#include "WindowClass.h"
#include "CustomWindow.h"
#include "ButtonWindow.h"
#include "StockObjects.h"
#include "SolidBrush.h"
#include "PredefinedCursors.h"
#include "MessageLoop.h"

class MyWindow : public CustomWindow
{
public:
    MyWindow(const WindowClass& wc)
        : CustomWindow(wc.CreateHandleBuilder().WithTitle(L"Hello World!!!"))
        , helloButton(ButtonWindow::CreateHandleBuilder(*this, 101).WithTitle(L"Hello").WithRect(10, 10, 100, 30))
        , toggleButton(ButtonWindow::CreateHandleBuilder(*this, 102).WithTitle(L"Toggle Hello").WithRect(10, 50, 100, 30))
        , closeButton(ButtonWindow::CreateHandleBuilder(*this, 103).WithTitle(L"Close").WithRect(10, 90, 100, 30))
    {
    }

    virtual void OnPaint(const PaintDeviceContext& dc) override
    {
        SolidBrush brush(RGB(200, 225, 255));
        dc.FillRect(brush.GetHandle());
    }

    virtual bool OnCommand(int notificationCode, int senderId, HWND controlHandle)
    {
        if (senderId == helloButton.GetId())
        {
            MessageBox(GetHandle(), L"Hello", L"Information", MB_OK | MB_ICONEXCLAMATION);
            return true;
        }
        if (senderId == toggleButton.GetId())
        {
            helloButton.Enable(!helloButton.IsEnabled());
            helloButton.SetClassCursor(PredefinedCursors::GetHandle(IDC_CROSS));
            return true;
        }
        if (senderId == closeButton.GetId())
        {
            Destroy();
            return true;
        }
        return false;
    }

private:
    ButtonWindow helloButton;
    ButtonWindow toggleButton;
    ButtonWindow closeButton;
};

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR pCmdLine, int nCmdShow)
{
    WindowClass wc = WindowClassBuilder(hInstance, L"My Window Class")
        .WithBackgroundBrush(StockObjects::LightGrayBrushHandle())
        .WithCursor(PredefinedCursors::GetHandle(IDC_ARROW))
        .Build();

    MyWindow window(wc);
    if (window.GetHandle() == NULL)
        return 0;

    window.Show(nCmdShow);
    MessageLoop().Run();
    return 0;
}
