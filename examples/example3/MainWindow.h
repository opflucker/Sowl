#pragma once
#include <CustomWindow.h>
#include <WindowHandleBuilder.h>

class MainWindow : public CustomWindow
{
private:
    static WindowHandleBuilder CreateHandleBuilder(HINSTANCE processHandle);

public:
    MainWindow(HINSTANCE processHandle);
    virtual bool OnCommand(int notificationCode, int senderId, HWND controlHandle);
};
