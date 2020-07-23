#pragma once
#include <Sowl/Windows/Customs/CustomWindow.h>
#include <Sowl/Windows/WindowHandleBuilder.h>
#include <Sowl/Windows/Controls/ButtonWindow.h>

class MainWindow : public sowl::CustomWindow
{
public:
    MainWindow(HINSTANCE processHandle);
    virtual bool OnCommand(int notificationCode, int senderId, HWND controlHandle);

private:
    sowl::ButtonWindow showMessageButton;
    sowl::ButtonWindow closeButton;
};
