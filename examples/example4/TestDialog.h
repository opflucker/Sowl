#pragma once
#include <Windows\Dialogs\ModelessDialogWindow.h>
#include <Windows\Controls\ButtonWindow.h>

class TestDialog : public ModelessDialogWindow
{
public:
    TestDialog();
    virtual bool OnInitDialog(HWND hFocusWindow) override;
    virtual bool OnCommand(int notificationCode, int senderId, HWND controlHandle) override;

private:
    ButtonWindow okButton;
};
