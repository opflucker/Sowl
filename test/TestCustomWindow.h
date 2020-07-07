#pragma once
#include <CustomWindow.h>
#include <WindowClassRegistered.h>
#include <ButtonWindow.h>

class TestCustomWindow : public CustomWindow
{
private:
    static WindowClassRegistered RegisterClass(HINSTANCE hInstance);

public:
    TestCustomWindow(HINSTANCE hInstance);
    virtual void OnPaint(const PaintDeviceContext& dc) override;
    virtual bool OnCommand(int notificationCode, int senderId, HWND controlHandle);

private:
    ButtonWindow helloButton;
    ButtonWindow toggleButton;
    ButtonWindow closeButton;
};
