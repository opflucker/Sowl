#pragma once
#include <Windows\Customs\CustomWindow.h>
#include <Windows\WindowHandleBuilder.h>
#include <vector>

class MainWindow : public CustomWindow
{
private:
    static WindowHandleBuilder CreateHandleBuilder(HINSTANCE processHandle);
    std::vector<POINT> points;

public:
    MainWindow(HINSTANCE processHandle);
    virtual void OnPaint(const PaintDeviceContext& dc) override;
    virtual bool OnLButtonDown(int mouseKeys, int x, int y) override;
};
