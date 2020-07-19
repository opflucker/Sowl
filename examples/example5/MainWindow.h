#pragma once
#include <Windows\Customs\CustomWindow.h>
#include <vector>

class MainWindow : public CustomWindow
{
public:
    MainWindow(HINSTANCE processHandle);
    virtual void OnPaint(const PaintDeviceContext& dc) override;
    virtual bool OnLButtonDown(int mouseKeys, int x, int y) override;

private:
    std::vector<POINT> points;
};
