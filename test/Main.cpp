#ifndef UNICODE
#define UNICODE
#endif 

#include <windows.h>
#include <typeinfo>
#include "WindowClassBuilder.h"
#include "WindowClassRegistered.h"
#include "CustomWindow.h"
#include "ButtonWindow.h"
#include "StockObjects.h"
#include "SolidBrush.h"
#include "PredefinedCursors.h"
#include "MessageLoop.h"
#include "DialogWindow.h"
#include "resource.h"

class MyDialog : public DialogWindow
{
public:
    MyDialog(const Window& parentWindow)
        : DialogWindow(parentWindow, IDD_DIALOG1)
    {
    }

    virtual BOOL OnInitDialog(HWND hFocusWindow) override
    {
        okButton.Attach(*this, IDOK);
        return TRUE;
    }

    virtual BOOL OnCommand(int notificationCode, int senderId, HWND controlHandle)
    {
        if (senderId == okButton.GetId())
        {
            okButton.Enable(false);
            return true;
        }
        return false;
    }

private:
    ButtonWindow okButton;
};

class MyWindow : public CustomWindow
{
private:
    static WindowClassRegistered RegisterClass(HINSTANCE hInstance)
    {
        return WindowClassRegistered(
            CreateClassBuilder(hInstance, L"MyWindow")
                .WithBackgroundBrush(StockObjects::LightGrayBrushHandle())
                .WithCursor(PredefinedCursors::ArrowHandle())
                .Result());
    }

public:
    MyWindow(HINSTANCE hInstance)
        : CustomWindow(RegisterClass(hInstance).CreateHandleBuilder().WithTitle(L"Hello World!!!"))
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
            MyDialog dlg(*this);
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

private:
    ButtonWindow helloButton;
    ButtonWindow toggleButton;
    ButtonWindow closeButton;
};

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR pCmdLine, int nCmdShow)
{
    MyWindow window(hInstance);
    if (window.GetHandle() == NULL)
        return 0;

    window.Show(nCmdShow);
    MessageLoop().Run();
    return 0;
}
