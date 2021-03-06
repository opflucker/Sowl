#include "MainWindow.h"
#include <Sowl/Graphics/Brushes/StockBrushesHandles.h>
#include <Sowl/Graphics/Brushes/SolidBrush.h>
#include <Sowl/Graphics/Cursors/PredefinedCursorHandles.h>

using namespace sowl;

MainWindow::MainWindow(HINSTANCE processHandle)
    : CustomWindow(CreateClassBuilder(processHandle, L"MainWindow")
        .WithBackgroundBrush(StockBrushesHandles::LightGray())
        .WithCursor(PredefinedCursorHandles::Arrow())
        .RegisterAndCreateHandleBuilder()
        .WithTitle(L"Hello World!!!"))
{
}

void MainWindow::OnPaint(const PaintDeviceContext& dc)
{
    SolidBrush brush(RGB(200, 225, 255));
    dc.FillRect(brush.GetHandle());

    dc.SetBackgroundMode(TRANSPARENT);
    dc.DrawText(L"Click window area to draw circles", GetClientRect(), DT_TOP | DT_LEFT);

    const int circleRadio = 50;
    for(unsigned int i = 0; i < points.size(); i++)
    {
        auto p = points[i];
        RECT r;
        r.left = p.x - circleRadio;
        r.right = p.x + circleRadio;
        r.top = p.y - circleRadio;
        r.bottom = p.y + circleRadio;
        dc.Ellipse(r);
    }
}

bool MainWindow::OnLButtonDown(int mouseKeys, int x, int y)
{
    POINT p = { x, y };
    points.push_back(p);
    InvalidateRect(false);
    return true;
}
