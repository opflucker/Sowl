#include "TestModelessDialog.h"
#include "resource.h"

TestModelessDialog::TestModelessDialog(const Window& parentWindow)
    : ModelessDialogWindow(parentWindow, IDD_DIALOG1)
{
}

BOOL TestModelessDialog::OnInitDialog(HWND hFocusWindow)
{
    okButton.Attach(*this, IDOK);
    return TRUE;
}

BOOL TestModelessDialog::OnCommand(int notificationCode, int senderId, HWND controlHandle)
{
    if (senderId == okButton.GetId())
    {
        okButton.Enable(false);
        return true;
    }
    return false;
}
