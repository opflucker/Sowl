#pragma once
#include <Sowl/Sowl.h>

class TestDialog : public sowl::ModalDialogWindow
{
public:
    explicit TestDialog(const Window& parentWindow);
    ~TestDialog() override = default;

    bool OnInitDialog(HWND hFocusWindow) override;
    bool OnCommand(int notificationCode, int senderId, HWND controlHandle) override;

private:
    sowl::ButtonWindow okButton;
};
