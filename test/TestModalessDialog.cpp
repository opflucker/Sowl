#include "TestModelessDialog.h"
#include "resource.h"

TestModelessDialog::TestModelessDialog()
    : ModelessDialogWindow(IDD_DIALOG1)
{
}

TestModelessDialog::TestModelessDialog(const Window& parentWindow)
    : ModelessDialogWindow(parentWindow, IDD_DIALOG1)
{
}

bool TestModelessDialog::OnInitDialog(HWND hFocusWindow)
{
    okButton.SetHandle(*this, IDOK);
    return TRUE;
}

bool TestModelessDialog::OnCommand(int notificationCode, int senderId, HWND controlHandle)
{
    if (senderId == okButton.GetId())
    {
        okButton.Enable(false);
        return true;
    }
    return false;
}
