#include "MainWindow.h"

using namespace sowl;

MainWindow::MainWindow(HINSTANCE processHandle)
    : CustomWindow(ClassRegisterer(processHandle, L"MainWindow")
        .WithBackgroundBrush(StockBrushesHandles::LightGray())
        .WithCursor(PredefinedCursorHandles::Arrow()))
{
}

void MainWindow::OnPaint(const PaintDeviceContext& dc)
{
    SolidBrush brush(RGB(200, 225, 255));
    dc.FillRect(brush.GetHandle());

    dc.SetBackgroundMode(TRANSPARENT);
    dc.DrawText(L"Click window area to draw circles", GetClientRect(), DT_TOP | DT_LEFT);

    const int circleRadio = 50;
    for (auto p : points)
    {
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
