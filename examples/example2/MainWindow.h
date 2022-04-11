#pragma once
#include <Sowl/Sowl.h>

class MainWindow : public sowl::CustomWindow
{
public:
    explicit MainWindow(HINSTANCE processHandle);
    bool OnCommand(int notificationCode, int senderId, HWND controlHandle) override;

private:
    sowl::ButtonWindow showMessageButton;
    sowl::ButtonWindow closeButton;
};
