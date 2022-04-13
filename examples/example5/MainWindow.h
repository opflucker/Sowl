#pragma once
#include <Sowl/Sowl.h>
#include <vector>

class MainWindow : public sowl::CustomWindow
{
public:
    explicit MainWindow(HINSTANCE processHandle);
    virtual ~MainWindow() = default;

    void OnPaint(const sowl::PaintDeviceContext& dc) override;
    bool OnLButtonDown(int mouseKeys, int x, int y) override;

private:
    std::vector<POINT> points;
};
