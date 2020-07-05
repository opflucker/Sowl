#ifndef UNICODE
#define UNICODE
#endif 

#include <windows.h>
#include "WindowClass.h"
#include "Window.h"
#include "MessageLoop.h"
#include "WindowClassBuilder.h"
#include "StockObjects.h"
#include "SolidBrush.h"

class MyWindow : public Window
{
public:
    MyWindow(WindowClass& wc, LPCWSTR title) : Window(wc, title) {}
    virtual void OnPaint(const PaintDeviceContext& dc) override
    {
        SolidBrush brush(RGB(200, 225, 255));
        dc.FillRect(brush.GetHandle());
    }
};

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR pCmdLine, int nCmdShow)
{
    WindowClass wc = WindowClassBuilder(hInstance, L"My Window Class")
        .WithBackgroundBrush(StockObjects::LightGrayBrushHandle())
        .Build();
    MyWindow window(wc, L"Hello World!!!");
    if (!window.IsCreated())
        return 0;

    window.Show(nCmdShow);
    MessageLoop().Run();
    return 0;
}
