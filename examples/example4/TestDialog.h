#pragma once
#include <Sowl/Sowl.h>

class TestDialog : public sowl::ModelessDialogWindow
{
public:
    TestDialog();
    bool OnInitDialog(HWND hFocusWindow) override;
    bool OnCommand(int notificationCode, int senderId, HWND controlHandle) override;

private:
    sowl::ButtonWindow okButton;
};
