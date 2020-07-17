#pragma once
#include <ModelessDialogWindow.h>
#include <ButtonWindow.h>

class TestModelessDialog : public ModelessDialogWindow
{
public:
    TestModelessDialog();
    TestModelessDialog(const Window& parentWindow);
    virtual bool OnInitDialog(HWND hFocusWindow) override;
    virtual bool OnCommand(int notificationCode, int senderId, HWND controlHandle) override;

private:
    ButtonWindow okButton;
};
