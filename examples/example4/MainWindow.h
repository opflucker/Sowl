#pragma once
#include <CustomWindow.h>
#include <WindowHandleBuilder.h>
#include "TestDialog.h"

class MainWindow : public CustomWindow
{
private:
    static WindowHandleBuilder CreateHandleBuilder(HINSTANCE processHandle);
    TestDialog modelessDialog;

public:
    MainWindow(HINSTANCE processHandle);
    void Run();

    virtual bool OnCommand(int notificationCode, int senderId, HWND controlHandle);
};
