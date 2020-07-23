#pragma once
#include <Sowl/Windows/Dialogs/ModelessDialogWindow.h>
#include <Sowl/Windows/Controls/ButtonWindow.h>

class TestDialog : public sowl::ModelessDialogWindow
{
public:
    TestDialog();
    virtual bool OnInitDialog(HWND hFocusWindow) override;
    virtual bool OnCommand(int notificationCode, int senderId, HWND controlHandle) override;

private:
    sowl::ButtonWindow okButton;
};
