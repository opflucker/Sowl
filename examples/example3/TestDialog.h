#pragma once
#include <Windows\Dialogs\ModalDialogWindow.h>
#include <Windows\Controls\ButtonWindow.h>

class TestDialog : public ModalDialogWindow
{
public:
    TestDialog(const Window& parentWindow);
    virtual bool OnInitDialog(HWND hFocusWindow) override;
    virtual bool OnCommand(int notificationCode, int senderId, HWND controlHandle) override;

private:
    ButtonWindow okButton;
};
