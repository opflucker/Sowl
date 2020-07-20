#pragma once
#include <Sowl/Windows/Customs/CustomWindow.h>
#include <Sowl/Windows/WindowHandleBuilder.h>

class MainWindow : public CustomWindow
{
public:
    MainWindow(HINSTANCE processHandle);
    virtual bool OnCommand(int notificationCode, int senderId, HWND controlHandle);
};
