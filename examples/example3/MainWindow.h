#pragma once
#include <Sowl/Sowl.h>

class MainWindow : public sowl::CustomWindow
{
public:
    explicit MainWindow(HINSTANCE processHandle);
    virtual ~MainWindow() = default;

    bool OnCommand(int notificationCode, int senderId, HWND controlHandle) override;
};
