#pragma once
#include <ModelessDialogWindow.h>
#include <ButtonWindow.h>

class TestModelessDialog : public ModelessDialogWindow
{
public:
    TestModelessDialog(const Window& parentWindow);
    virtual BOOL OnInitDialog(HWND hFocusWindow) override;
    virtual BOOL OnCommand(int notificationCode, int senderId, HWND controlHandle);

private:
    ButtonWindow okButton;
};
