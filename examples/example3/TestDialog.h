#pragma once
#include <Sowl/Windows/Dialogs/ModalDialogWindow.h>
#include <Sowl/Windows/Controls/ButtonWindow.h>

class TestDialog : public sowl::ModalDialogWindow
{
public:
    TestDialog(const Window& parentWindow);
    virtual bool OnInitDialog(HWND hFocusWindow) override;
    virtual bool OnCommand(int notificationCode, int senderId, HWND controlHandle) override;

private:
    sowl::ButtonWindow okButton;
};
