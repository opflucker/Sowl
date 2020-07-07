#pragma once
#include <DialogWindow.h>
#include <ButtonWindow.h>

class TestDialog : public DialogWindow
{
public:
    TestDialog(const Window& parentWindow);
    virtual BOOL OnInitDialog(HWND hFocusWindow) override;
    virtual BOOL OnCommand(int notificationCode, int senderId, HWND controlHandle);

private:
    ButtonWindow okButton;
};
