#pragma once
#include <Sowl/Windows/Customs/CustomWindow.h>
#include <Sowl/Windows/MessageLoop.h>
#include "TestDialog.h"

class MainWindow : public sowl::CustomWindow, public sowl::MessageLoop
{
public:
    MainWindow(HINSTANCE processHandle);
    virtual void ProcessMessage(MSG& message) override;
    virtual bool OnCommand(int notificationCode, int senderId, HWND controlHandle) override;

private:
    TestDialog modelessDialog;
};
