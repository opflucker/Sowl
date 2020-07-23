#pragma once
#include <Sowl/Windows/Customs/CustomWindow.h>
#include <vector>

class MainWindow : public sowl::CustomWindow
{
public:
    MainWindow(HINSTANCE processHandle);
    virtual void OnPaint(const sowl::PaintDeviceContext& dc) override;
    virtual bool OnLButtonDown(int mouseKeys, int x, int y) override;

private:
    std::vector<POINT> points;
};
