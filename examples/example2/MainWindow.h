#pragma once
#include <Windows\Customs\CustomWindow.h>
#include <Windows\WindowHandleBuilder.h>
#include <Windows\Controls\ButtonWindow.h>

class MainWindow : public CustomWindow
{
private:
    static WindowHandleBuilder CreateHandleBuilder(HINSTANCE processHandle);

public:
    MainWindow(HINSTANCE processHandle);
    virtual bool OnCommand(int notificationCode, int senderId, HWND controlHandle);

private:
    ButtonWindow showMessageButton;
    ButtonWindow closeButton;
};
