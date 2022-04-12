#pragma once
#include "TestDialog.h"
#include <memory>

class MainWindow : public sowl::CustomWindow, public sowl::MessageLoop
{
public:
    explicit MainWindow(HINSTANCE processHandle);
    virtual ~MainWindow() = default;

    void ProcessMessage(MSG& message) override;
    bool OnCommand(int notificationCode, int senderId, HWND controlHandle) override;

private:
    std::unique_ptr<TestDialog> pModelessDialog;
};
