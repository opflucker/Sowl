#pragma once
#include <Windows\Customs\CustomWindow.h>
#include <Windows\WindowHandleBuilder.h>
#include <Windows\Controls\ButtonWindow.h>

class MainWindow : public CustomWindow
{
public:
    MainWindow(HINSTANCE processHandle);
    virtual bool OnCommand(int notificationCode, int senderId, HWND controlHandle);

private:
    ButtonWindow showMessageButton;
    ButtonWindow closeButton;
};
